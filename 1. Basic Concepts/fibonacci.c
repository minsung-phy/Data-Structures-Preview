//
//  main.c
//  fibonacci
//
//  Created by 이민성 on 2023/07/19.
//

#include <stdio.h>

int fibonacci_recursive(int i)
{
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
        return (fibonacci_recursive(i-1) + fibonacci_recursive(i-2));
}

int fibonacci_loop(int i)
{
    int j = 0;
    int fib = 0;
    int fib0 = 0;
    int fib1 = 1;
    
    if (i > 0)
    {
        if (i == 0)
            return 0;
        else if (i == 1)
            return 1;
        else
            for(j = 2; j <= i; j++)
            {
                fib = fib0 + fib1;
                fib0 = fib1;
                fib1 = fib;
            }
        return fib;
    }
    else
        return -1;
}

int main(int argc, const char * argv[]) {
    printf("answer: %d\n", fibonacci_recursive(11));
    // printf("answer: %d\n", fibonacci_recursive(-5));
    printf("answer: %d\n", fibonacci_loop(11));
    // printf("answer: %d\n", fibonacci_loop(-5));
    return 0;
}
