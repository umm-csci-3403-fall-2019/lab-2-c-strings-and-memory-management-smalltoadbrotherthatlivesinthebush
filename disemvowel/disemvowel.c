#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int len, i;
  char *result;

  len=strlen(str);
  result = (char*) calloc(len+1, sizeof(char));
  int index = 0;
  for (i=0; i<len; i++){
	  if((str[i] != 'a') && (str[i] != 'e') && (str[i] != 'i') && (str[i] != 'o') && (str[i] != 'u') && (str[i] != 'A') && (str[i] != 'E') && (str[i] != 'I') && (str[i] != 'O') && (str[i] != 'U')) {
		  result[index] = str[i];
		  index++;
	  }
  }
  result[index] = '\0';
  return result;
}
