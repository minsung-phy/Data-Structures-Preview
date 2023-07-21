//
//  main.c
//  structure
//
//  Created by 이민성 on 2023/07/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct {
    char name[10];
    int age;
    float salary;
} person;

typedef struct {
    char name[10];
    int age;
    float salary;
} humanBeing;

typedef struct {
    int month;
    int day;
    int year;
} date;

typedef struct {
    char name[10];
    int age;
    float salary;
    date dob; // 구조 속에 또 다른 구조
} humanBeing2;

int humansEqual(humanBeing person1, humanBeing person2)
{ // 만일 person1과 person2가 동일인이면 TRUE를 반환하고, 그렇지 않으면 FALSE를 반환한다.
    if (strcmp(person1.name, person2.name)) // name이 문자열이기 때문에 문자열 비교함수 strcmp 사용 (같으면 0, 같지않으면 0이 아닌 값 반환)
        return FALSE;
    if (person1.age != person2.age)
        return FALSE;
    if (person1.salary != person2.salary)
        return FALSE;
    return TRUE;
}

int main(void) {
   // strcpy(person.name, "james"); // strcpy: 문자열 복사 함수
    person.age = 10;
    person.salary = 35000;
    
    humanBeing person1, person2;
    humanBeing2 lms; // 구조 속에 또 다른 구조
    
    if (strcmp(person1.name, person2.name)) // 문자열 비교함수 (같으면 0, 같지않으면 0이 아닌 값 반환)
        printf("The two people do not have the same name\n");
    else
        printf("The two people have the same name\n");
    
    lms.dob.month = 2; // 구조 속에 또 다른 구조
    lms.dob.day = 11;
    lms.dob.year = 2003;
    
    return 0;
}
