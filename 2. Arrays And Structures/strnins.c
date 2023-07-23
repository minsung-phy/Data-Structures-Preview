//
//  main.c
//  strnins
//
//  Created by 이민성 on 2023/07/23.
//

#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void strnins(char *s, char *t, int i)
{ // 스트링 s의 i번째 위치에 스트링 t를 삽입
    char string[MAX_SIZE], *temp = string;
    if (i < 0 && i > strlen(s))
    {
        fprintf(stderr, "Position is out of bounds \n");
        // exit(EXIT_FAILURE);
    }
    if (!strlen(s)) // s의 길이가 0인 경우
        strcpy(s, t);
    else if (strlen(t))
    {
        strncpy(temp, s, i);
        strcat(temp, t);
        strcat(temp, (s+i));
        strcpy(s, temp);
    }
}

int main(void) {
    char s[MAX_SIZE] = "amobile";
    char t[MAX_SIZE] = "uto";
    strnins(s, t, 1);
    printf("%s\n", s);
    return 0;
}
