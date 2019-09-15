// Problem: https://leetcode.com/problems/alphabet-board-path/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

int row (char a){
    if (a >= 97 && a <= 101){
        return 1;
    } else if (a >= 102 && a <= 106){
        return 2;
    } else if (a >= 107 && a <= 111){
        return 3;
    } else if (a >= 112 && a <= 116){
        return 4;
    } else if (a >= 117 && a <= 121){
        return 5;
    }
    return 6;
}

char * alphabetBoardPath(char * target){
    assert (target);

    char ans [100];

    char curr = 97;
    char targetChar;
    int len = strlen(target);
    int ansLen = 1;
    int i = 0;
    int temp = 0;

    while (1){
        if (row (target[i]) == 6 && curr != 117 && curr != 122){
            targetChar = 'u';
        } else{
            targetChar = target[i];
        }

        temp = row(targetChar) - row(curr);
        if (i == len){
            ans[ansLen] = '\0';
            char * final = malloc (ansLen * sizeof (char));
            strcpy (final, ans);
            return final;
        } else if (temp == 0){
            temp = targetChar - curr;
            if (temp == 0){
                ans [ansLen - 1] = '!';
                i ++;
            } else if (temp > 0){
                ans [ansLen - 1] = 'R';
                curr ++;
            } else if (temp < 0){
                ans [ansLen - 1] = 'L';
                curr --;
            }
        } else if (temp > 0){
            ans [ansLen - 1] = 'D';
            curr += 5;
        } else if (temp < 0){
            ans [ansLen - 1] = 'U';
            curr -= 5;
        }
        ansLen ++;
    }
}

int main (){
    char * s = "za";
    char * ans = alphabetBoardPath (s);
    printf ("%s\n", ans);
    free (ans);
}