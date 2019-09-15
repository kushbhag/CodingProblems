#include <string.h>
#include <assert.h>
#include <stdio.h>


int rominteger (char * s){
  int len = strlen (s);\
  int total = 0;

  for (int i = 0; i < len; i++){
    if (s[i] == 'I'){
      if (s[i+1] != '\0' && (s[i+1] == 'V' || s[i+1] == 'X')){
        total -= 1;
      } else total += 1;
    } else if (s[i] == 'V') total += 5;
    else if (s[i] == 'X'){
      if (s[i+1] != '\0' && (s[i+1] == 'L' || s[i+1] == 'C')){
        total -= 10;
      } else total += 10;
    } else if (s[i] == 'L') total += 50;
    else if (s[i] == 'C'){
      if (s[i+1] != '\0' && (s[i+1] == 'D' || s[i+1] == 'M')){
        total -= 100;
      } else total += 100;
    } else if (s[i] == 'D') total += 500;
    else if (s[i] == 'M') total += 1000;
  }

  return total;
}


int main(){
  while (1){
    char c [50] = {};
    scanf ("%s", c);
    printf ("%d", rominteger (c));
    if (c == "hello") return;
  }
  return 0;
}
