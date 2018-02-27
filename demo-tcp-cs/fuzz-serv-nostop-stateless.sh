rm -rf afl-output

afl-fuzz -i afl-input/ -o afl-output -m 500  -t 20 -D 5 -N tcp://127.0.0.1:7891 ./server-nonstop-stateless.out
