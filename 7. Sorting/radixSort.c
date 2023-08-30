//
//  main.c
//  radixSort
//
//  Created by 이민성 on 2023/08/30.
//

#include <stdio.h>

typedef struct {
    int key;
} element;

int radixSort(element a[], int link[], int d, int r, int n);
int digit(int num, int position, int radix);

int main(void) {
    return 0;
}

int radixSort(element a[], int link[], int d, int r, int n)
{ // sort a[1:n] using a d-digit radix-r sort, digit(a[i], j, r) returns the jth radix-r digit (from the left) of a[i]'s key; each digit is in the range is [0,r); sorting within a digit is done using a bin sort
    int front[r], rear[r]; // queue front and rear pointers
    int i, bin, current, first, last;
    // create initial chain of records starting at first
    first = 1;
    for (i = 1; i < n; i++)
        link[i] = i + 1;
    link[n] = 0;
    for ( i = d-1; i >= 0; i--)
    { // sort on digit i
        // initialize bins to empty queues
        for (bin = 0; bin < r; bin++)
            front[bin] = 0;
        for (current = first; current; current = link[current])
        { // put records into queues/bins
            bin = digit(a[current].key, i, r);
            if (front[bin] == 0)
                front[bin] = current;
            else
                link[rear[bin]] = current;
            rear[bin] = current;
        }
        // fins first nonempty queue/bin
        for (bin = 0; !front[bin]; bin++);
        first = front[bin];
        last = rear[bin];
        // concatenate remaining queues
        for (bin++; bin < r; bin++)
            if (front[bin]) {
                link[last] = front[bin];
                last = rear[bin];
            }
        link[last] = 0;
    }
    return first;
}

int digit(int num, int position, int radix)
{
    // Extract the desired digit at the given position
    // For example, if num is 456 and position is 1, and radix is 10,
    // the result should be 5.
    int divisor = 1;
    for (int i = 0; i < position; i++) {
        divisor *= radix;
    }
    return (num / divisor) % radix;
}
