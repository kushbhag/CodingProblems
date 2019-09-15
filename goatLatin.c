#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// https://leetcode.com/problems/goat-latin/

bool vowel (char c){
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
      c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
      return true;
  }
  return false;
}


char * maa (char * words, int a, int len, bool space){
  if (space){
    words = realloc (words, (1 + a + len) * sizeof (char));
    words [len + a] = ' ';
    words [len - 1] = 'm';
  } else {
    words = realloc (words, (a + len) * sizeof (char));
    words [len] = 'm';
  } 
  
  for (; a > 0; a --){
    if (space)
      words [len + a - 1] = 'a';
    else 
      words [len + a] = 'a';
  }
  return words;
}


char * toGoatLatin(char * s){
  int len = strlen (s);
  int temp = 1;
  int words = 1;
  bool vow = false;
  char * goat = malloc (1 * sizeof (char));
  char tempChar = 'a';

  if (len == 0){
    return goat;
  }

  if (vowel(s[0])){
    vow = true;
  } else {
    tempChar = s[0];
  }
  
  for (int i = 0; i < len; i++){
    if (s[i] == ' '){
      if (vow){
        maa (goat, words, temp, true);       
      } else {
        goat [temp - 2] = tempChar; 
        maa (goat, words, temp, true); 
      }
      temp += 2 + words;
      words ++;
      if (i + 1 == len){ 
        break;
      } else if (vowel(s[i+1])){
        
        vow = true;
      } else{
        vow = false;
        tempChar = s[i+1];
      }
    } else if (vow){
      goat [temp - 1] = s[i];
      if (i + 1 == len){
        maa (goat, words, temp, false);
      }
      temp ++;
      goat = realloc (goat, temp * sizeof(char));
    } else {
      goat = realloc (goat, temp * sizeof (char));
      if (i + 1 == len){
        goat[temp - 1] = tempChar;
        maa (goat, words, temp, false);
      } else{
        goat[temp - 1] = s[i + 1];
      }
      temp ++;
    }
  }
  return goat;
}

int main(){
  char * words = malloc (10 * sizeof (char));
  scanf ("%[^\n]%*c", words);
  words = toGoatLatin (words);
  
  printf("%s\n", words);
  free (words);
  return 0;
}
