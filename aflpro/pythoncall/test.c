#include <stdio.h>
#include <Python.h>

#include "pycall.h"

int main(int argc, char *argv[]) {
    PyObject * result = pycall("mytest", "testChecker", "s", "My message!");
    int return_val = PyLong_AsLong(result);
    pycall("mytest","sendMessage","s", "88888888888888");    
    printf("The result is: %d\n", return_val);
    return 0;
}
