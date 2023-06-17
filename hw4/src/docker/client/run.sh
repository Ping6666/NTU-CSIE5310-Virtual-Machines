#!/bin/bash

CMD="python3 ./main.py"
exec $CMD &

tail -f /dev/null
