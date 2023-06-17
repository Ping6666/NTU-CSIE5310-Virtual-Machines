FROM ubuntu:20.04

RUN apt-get update -y && \
    apt-get install -y python3.8 python3-pip python3.8-dev

WORKDIR /servervol
ADD . /servervol

ENV PYTHONPATH="$PYTHONPATH:/servervol"

RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt

CMD ["python3", "./main.py"]
