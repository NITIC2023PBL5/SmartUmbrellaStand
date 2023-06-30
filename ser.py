import time
import serial

ser = serial.Serial('/dev/ttyACM0',9600,timeout=1)
ser.reset_input_buffer()
port = {}
code = {}
newp = None

def main():
    while True:
        while True:
            data = ser.readline().decode('utf-8').rstrip()
            if data==None:
                break
            output(data)
        time.sleep(0.01)
        continue
    ser.close()

def output(data):
    if data.find('port')==0:  # 「port1:True」の形式で通信
        d = data.split(":")
        value = d[1] == 'True'
        if d[0] in port:
            if port[d[0]] != value:
                print('changed ',d[0],':',value)
                if value:
                    newp = d[0]
                    ser.write(b'request')
        port[d[0]]=value
    elif data.find('mat')==0:  # 「mat:<Number>」の形式でマトリックスキーの入力を受ける
        value = int(data.split(':')[1])
        print(data)
        if newp:
            code[newp] = value


'''
async def userCheck(index):
    string = 'check:'+index
    ser.write(string.encode('utf-8'))
    while True:
        data = ser.readline().decode('utf-8').rstrip()
        if data == None:
            time.sleep(0.1)
            continue
        elif data.find('number')==0:
        else:
            if data == 'exit': return None
            else:
                '''
            

main()