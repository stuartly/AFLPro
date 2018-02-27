#include <unistd.h>
#include <stdio.h>

int main(){
  char* args[1];
  args[0] = "afl-input/a";
  int result = execv("file-server-socket.out", args);
  printf("result is %d\n",result);
  return result;
}

