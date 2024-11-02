#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "str2int.h"

_Bool is_space(char c) {
  return (c == ' ');
}
_Bool is_digit(char c) {
  return (c >= '0' && c <= '9');
}
int str2int(const char *str) {
  
  assert(str != NULL);

  int result = 0;
  int sign = 1;
  int dlina = 0;
  int abs_res;
  
  while (is_space(*str)) {
    str++;
  }

  char first_el = *str;

  if (*str == '-' || *str == '+') {
    if (*str == '-') {
      sign = -1;
    }
    else {
      sign = 1;
    }
    str++;
  }
  while (is_digit(*str)) {
    dlina++;
    int digit = *str - '0';
    if (((sign >0) && (((2147483647 - digit) / 10) >= result)) || ((sign <0) && (((2147483648 - digit) / 10) >= result))){
      result = result * 10 + digit;
      str++;
    }
    else {
      assert(1==0);
    }
  }
  assert(dlina>0);
  
  return result * sign;
}

