#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);
  char *dis;
  dis = disemvowel(line);
  while (getline(&line, &size, stdin) > 0) {
    printf("%s\n", dis);
    free(dis);
  }
  free(line);
}
