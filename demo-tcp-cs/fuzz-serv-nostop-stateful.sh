rm -rf afl-output


#afl-fuzzer -i afl-input/ -o afl-output -m 500  -t 20 -D 5 -N tcp://127.0.0.1:7891 ./server-nonstop-stateful.out
afl-fuzz -i afl-input/ -o afl-output -G grammar-example/demo.json -s -m 500  -t 20 -D 10 -N tcp://127.0.0.1:7891 ./server-nonstop-stateful.out
