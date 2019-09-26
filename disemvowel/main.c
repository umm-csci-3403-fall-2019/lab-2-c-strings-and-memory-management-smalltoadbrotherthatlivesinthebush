#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);
  char* dis;
  while (getline(&line, &size, stdin) > 0) {
    dis = disemvowel(line);	  
    printf("%s\n", dis);
    if (*dis != '\0'){
      free(dis);
    }
  }
  free(line);
}
