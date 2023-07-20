//
//  main.c
//  selectionSort_MeasurementRepetitionsClock
//
//  Created by 이민성 on 2023/07/20.
//

#include <stdio.h>
#include <time.h>
#include "selectionSort.h"
#define MAX_SIZE 1001

void main(void)
{
    int i, n, step = 10;
    int a[MAX_SIZE];
    double duration;
    
    // times for n = 0, 10, ..., 100, 200, ..., 1000
    printf("    n    repetitions    time\n");
    for (n = 0; n <= 1000; n += step)
    {
        // get time for size
        long repetitions = 0;
        clock_t start = clock();
        do
        {
            repetitions++;
            
            // initialize with worst-case data
            for (i = 0; i < n; i++)
                a[i] = n - i;
            
            sort(a, n);
        } while (clock() - start < 1000);
            // repeat until enough time has elapsed
        
        duration = ((double)(clock()-start)) / CLOCKS_PER_SEC;
        duration /= repetitions;
        printf("%6d    %9d    %f\n", n, repetitions, duration);
        if (n == 100) step = 100;
    }
}
