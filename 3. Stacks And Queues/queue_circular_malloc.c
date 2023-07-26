//
//  main.c
//  queue_circular_malloc
//
//  Created by 이민성 on 2023/07/26.
//

#include <stdio.h>

int main(void) {

    return 0;
}

void addq(element item)
{ // add an item to the queue
    rear = (rear+1) % capacity;
    if (front == rear)
        queueFull(); // double capacity
    queue[rear] = item;
}

void queueFull()
{
    // allocate an array with twice the capacity
    element* newQueue;
    MALLOC(newQueue, 2 * capacity * sizeof(*queue));
    
    // copy from queue to newQueue
    int start = (front + 1) % capacity;
    if (start < 2)
        // no wrap around
        copy(queue+start, queue+capacity, newQueue);
    else
    { // queue wraps around
        copy(queue+start, queue+capacity, newQueue);
        copy(queue, queue+rear+1, newQueue+capacity-start);
    }
    
    // switch to newQueue
    front = 2 * capacity - 1;
    rear = capacity - 2;
    capacity *= 2;
    free(queue);
    queue = newQueue;
}
