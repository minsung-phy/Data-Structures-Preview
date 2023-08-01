//
//  main.c
//  ListOperation
//
//  Created by 이민성 on 2023/08/01.
//

#include <stdio.h>

typedef struct {
    char data;
    struct listNode * link;
} listNode;

typedef listNode * listPointer;

int main(void) {

    return 0;
}

listPointer invert(listPointer lead)
{ // lead가 가리키고 있는 리스트를 역순으로 만든다.
    listPointer middle, trail;
    middle = NULL;
    while (lead)
    {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return middle;
}

listPointer concatenate(listPointer ptr1, listPointer ptr2)
{ // 리스트 ptr1 뒤에 리스트 ptr2가 연결된 새로운 리스트를 생성한다. ptr1이 가리키는 리스트는 영구히 바뀐다.
    listPointer temp;
    
    // check for empty lists
    if (!ptr1)
        return ptr2;
    if (!ptr2)
        return ptr1;
    
    // 두 리스트가 공백이 아니면 첫 번째 리스트의 끝을 탐색
    for (temp = ptr1; temp->link; temp = temp->link);
    
    // 첫 번쨰 끝을 두 번째 시작에 연결
    temp->link = ptr2;
    
    // 새로 연결된 리스트를 반환
    return ptr1;
}

void insertFront(listPointer *last, listPointer node)
{ // 리스트의 마지막 노드가 last인 원형 리스트의 앞에 노드를 삽입한다
    if (!(*last))
    { // 리스트가 공백일 경우, last가 새로운 항목을 가리키도록 변경시킨다
        *last = node;
        node->link = node;
    }
    else
    { // 리스트가 공백이 아닌 경우, 리스트의 앞에 새로운 항목을 삽입시킨다.
        node->link = (*last)->link;
        (*last)->link = node;
    }
}

int length(listPointer last)
{ // 원형 리스트 last의 길이를 계산한다
    listPointer temp;
    int count = 0;
    if (last)
    {
        temp = last;
        do {
            count++;
            temp = temp->link;
        } while (temp != last);
    }
    return count;
}
