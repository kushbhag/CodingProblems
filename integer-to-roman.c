#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


char * introman(int num){
    int i = 0;
    char * c = malloc (10 * sizeof (char));

    while (num != 0){
      if (num >= 1000){
        c[i] = 'M';
        i++;
        num -= 1000;
      } else if (num >= 900 ){
        c[i] = 'C';
        c[i+1] = 'M';
        i += 2;
        num -= 900;
      } else if (num >= 500){
        c[i] = 'D';
        i++;
        num -= 500;
      } else if (num >= 400){
        c[i] = 'C';
        c[i+1] = 'D';
        i += 2;
        num -= 400;
      } else if (num >= 100){
        c[i] = 'C';
        i++;
        num -= 100;
      } else if (num >= 90){
        c[i] = 'X';
        c[i+1] = 'C';
        i += 2;
        num -= 90;
      } else if (num >= 50){
        c[i] = 'L';
        i++;
        num -= 50;
      } else if (num >= 40){
        c[i] = 'X';
        c[i+1] = 'L';
        i += 2;
        num -= 40;
      } else if (num >= 10){
        c[i] = 'X';
        i++;
        num -= 10;
      } else if (num >= 9){
        c[i] = 'I';
        c[i+1] = 'X';
        i += 2;
        num -= 9;
      } else if (num >= 5){
        c[i] = 'V';
        i++;
        num -= 5;
      } else if (num >= 4){
        c[i] = 'I';
        c[i+1] = 'V';
        i += 2;
        num -= 4;
      } else if (num >= 1){
        c[i] = 'I';
        i++;
        num -= 1;
      }
    }
    c[i] = '\0';
    return c;
}



int main(){
  while (1){
    int c;
    scanf ("%d", c);
    char * s = introman(c);
    printf ("%c", s);
    if (c == 10) {
      free (s);
      break;
    }
  }

  return 0;
}
