//
//  main.c
//  strstr
//
//  Created by 이민성 on 2023/07/23.
//

#include <stdio.h>
#include <string.h>

int main(void) {
    char pat[] = "ello";
    char str[] = "Hello World";
    char *t;
    if (t = strstr(str, pat))
        printf("The string from strstr is: %s\n", t);
    else
        printf("The pattern was not found with strstr\n");
    return 0;
}
