/*
   american fuzzy lop - a trivial program to test the build
   --------------------------------------------------------

   Written and maintained by Michal Zalewski <lcamtuf@google.com>

   Copyright 2014 Google Inc. All rights reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at:

     http://www.apache.org/licenses/LICENSE-2.0

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char** argv) {

  int buffer[6];
  scanf("%d",&buffer[3]);
  if(buffer[3]==3)
     exit(1);



  scanf("%d",&buffer[4]);
  if(buffer[4]==4)
     exit(1);


}
