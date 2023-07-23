//
//  main.c
//  nfind
//
//  Created by 이민성 on 2023/07/23.
//

#include <stdio.h>
#include <string.h>

int nfind(char *string, char *pat)
{ // 먼저 패턴의 마지막 문자를 매치시킨 뒤, 처음부터 매치시킨다.
    int i, j, start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;
    for (i = 0; endmatch <= lasts; endmatch++, start++)
    {
        if (string[endmatch] == pat[lastp])
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++);
        if (j == lastp)
            return start; // 성공
    }
    return -1;
}

int main(void) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
