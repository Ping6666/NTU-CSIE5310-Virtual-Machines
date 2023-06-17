from flask import Flask


def create_flask():
    app = Flask(__name__)

    @app.route('/')
    def home_page():
        _str = "sending from the server"
        print(_str)

        with open('sent.txt', 'w') as f:
            f.write(_str)
        return _str

    return app


app = create_flask()

if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0', port=5000)
