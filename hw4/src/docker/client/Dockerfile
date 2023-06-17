FROM ubuntu:20.04

RUN apt-get update -y && \
    apt-get install -y python3.8 python3-pip python3.8-dev

WORKDIR /clientvol
ADD . /clientvol

ENV PYTHONPATH="$PYTHONPATH:/clientvol"

RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt

CMD ["/bin/bash", "./run.sh"]
