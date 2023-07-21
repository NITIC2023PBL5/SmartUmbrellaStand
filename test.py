import requests
import dotenv
dotenv.load_dotenv()
import os

url_status = os.getenv('URL_STATUS')
url_notify = os.getenv('URL_NOTIFY')
token = os.getenv('TOKEN')

requests.post(url=url_notify+'81',
              params={
                  "message":"テストメッセージ",
                  "token":token
              },
              verify=False)
