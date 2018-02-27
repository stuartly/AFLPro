rm -rf afl-output

afl-fuzzer -i afl-input/ -o afl-output -t 1000 -D 5 -N tcp://127.0.0.1:7891 ./server-stop.out
