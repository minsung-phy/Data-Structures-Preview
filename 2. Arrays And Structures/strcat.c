//
//  main.c
//  strcat
//
//  Created by 이민성 on 2023/07/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void main(void) {
    char s[MAX_SIZE] = "dog";
    char t[MAX_SIZE] = "house";
    printf("%s\n", s);
    printf("%s\n", t);
    strcat(s, t);
    printf("%s\n", s);
}
