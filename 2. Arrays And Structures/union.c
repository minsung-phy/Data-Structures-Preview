//
//  main.c
//  union
//
//  Created by 이민성 on 2023/07/21.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int month;
    int day;
    int year;
} date;

typedef struct {
    enum tagField {female, male} sex; // 열거형: enum 열거형이름 {상수 이름};
    union {
        int children;
        int bread;
    } u;
} sexType;

typedef struct {
    char name[10];
    int age;
    float salary;
    date dob;
    sexType sexInfo;
} humanBeing;

typedef struct {
    char data;
    struct list *link; // link는 포인터 변수
} list;

int main(void) {
    humanBeing person1, person2;
    
    person1.sexInfo.sex = male;
    person1.sexInfo.u.bread = FALSE; // FALSE = 0 이므로 bread는 int형이다
    
    person2.sexInfo.sex = female;
    person2.sexInfo.u.children = 4;
    
    list item1, item2, item3;
    item1.data = 'a';
    item2.data = 'b';
    item3.data = 'c';
    item1.link = item2.link = item3.link = NULL;
    
    item1.link = &item2;
    item2.link = &item3;
    
    return 0;
}
