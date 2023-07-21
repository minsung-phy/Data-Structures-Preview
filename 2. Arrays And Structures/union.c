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
    enum tagField {female, male} sex; // 열거형
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

int main(void) {
    humanBeing person1, person2;
    
    person1.sexInfo.sex = male;
    person1.sexInfo.u.bread = FALSE;
    
    person2.sexInfo.sex = female;
    person2.sexInfo.u.children = 4;
    
    return 0;
}
