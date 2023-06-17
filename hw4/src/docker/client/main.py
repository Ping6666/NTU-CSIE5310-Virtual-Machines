import time, requests


def request_flask():
    # res = requests.get('http://127.0.0.1:5000')
    res = requests.get('http://server:5000')

    _str = str(res.text)
    print(_str)

    with open('received.txt', 'w') as f:
        f.write(_str)

    print('done')
    return _str


if __name__ == '__main__':
    time.sleep(5)
    request_flask()
