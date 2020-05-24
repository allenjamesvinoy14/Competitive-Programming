import requests

URL = 'https://api.pinterest.com/v1/5076767024189847189/boards/'

data = {
    'name' : 'crio board'
}
try:
    r = requests.post(url = URL, data=data)
    print(r.json)

except requests.exceptions.ConnectionError:
    print('\n\nError: Could not post review. Make sure you have started the server!!!\n\n')

