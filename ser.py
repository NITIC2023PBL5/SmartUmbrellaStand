#時刻合わせコマンド
#sudo date --set "$(wget -q http://worldtimeapi.org/api/timezone/Asia/Tokyo.txt -O - | grep ^datetime | cut -d " " -f 2)"

import time
import serial
import requests
import dotenv
dotenv.load_dotenv()
import os
url_status = os.getenv('URL_STATUS')
url_notify = os.getenv('URL_NOTIFY')

ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)
ser.reset_input_buffer()
port = {}
code = {}
newp = None

def main():
    while True:
        while True:
            data = ser.readline().decode('utf-8',errors='replace').rstrip()
            if data==None:
                break
            output(data)
        time.sleep(0.01)
        continue
    ser.close()

def printStat():
    for key in code.keys():
        print(key,':',code[key])

def output(data):
    global newp
    if data.find('port')==0:  # 「port1:True」の形式で通信
        d = data.split(":")
        value = d[1] == 'True'
        if d[0] in port:
            if port[d[0]] != value:
                print('changed ',d[0],':',value)
                if value:
                    newp = d[0]
                    ser.write(b'request')
                else:
                    requests.delete(url=url_status+code[d[0]])
                    code[d[0]] = ''
        port[d[0]]=value
    elif data.find('mat')==0:  # 「mat:<Number>」の形式でマトリックスキーの入力を受ける
        value = data.split(':')[1]
        print(data)
        if newp:
            code[newp] = value
            requests.post(url=url_status+value)
        printStat()


main()