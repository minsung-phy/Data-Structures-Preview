//
//  main.c
//  DynamicMemoryAllocation
//
//  Created by 이민성 on 2023/07/18.
//

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
    if (!((p) = malloc(s))) {\
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

int main(void) {
    int i, *pi;
    float f, *pf;
    MALLOC(pi, sizeof(int))
    MALLOC(pf, sizeof(float));
    *pi = 1024;
    *pf = 3.14;
    printf("an integer = %d, a float = %f\n", *pi, *pf);
    // pf = (float *) malloc(sizeof(float)); // 허상 참조(dangling reference)
    free(pi);
    free(pf);
    return 0;
}
