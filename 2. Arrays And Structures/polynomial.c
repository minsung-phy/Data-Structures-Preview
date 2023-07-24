//
//  main.c
//  polynomial
//
//  Created by 이민성 on 2023/07/21.
//

#include <stdio.h>
#include <stdlib.h>

// 함수 padd의 초기 버전

//#define MAX_DEGREE 101 /* 다항식의 최대 차수 + 1*/
//
//typedef struct {
//    int degree; // 지수
//    float coef[MAX_DEGREE]; // 차수 (계수)
//} polynomial;

//#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)
///* d = a + b, 여기서 a, b, d는 다항식이다. */
//d = Zero(); // ADT, d = 0
//while (!IsZero(a) && !IsZero(b)) do { // IsZero: 다항식이 0이면 TRUE, 0이 아니면 FALSE
//    switch COMPARE(LeapExp(a), LeapExp(b)) { // 각 a, b 다항식에서 제일 큰 지수 비교
//        case -1: // b가 더 클때
//            d = Attach(d, coef(b, LeapExp(b)), LeapExp(b)); // coef는 계수를 return 함
//            b = Remove(b, LeapExp(b));
//            break;
//        case 0: sum = Coef(a, LeapExp(a)) + Coef(b, LeapExp(b)); // 같을 때
//            if (sum) {
//                Attach(d, sum. LeapExp(a));
//                a = Remove(a, LeapExp(a));
//                b = Remove(b, LeapExp(b));
//            }
//            break;
//        case 1: d = Attach(d, Coef(a, LeapExp(a)), LeapExp(a)); // a가 더 클때
//            a = Remove(a, LeapExp(a));
//    }
//}

// 이 표현 방법은 대부분의 연산을 위한 알고리즘을 간단하게 구성할 수 있게 하지만 많은 저장 공간의 낭비를 초래한다.
// 예를 들어, 만일 a.degree << MAX_DEGREE (기호 << : 매우작음)이면, a.coef[MAX_DEGREE]의 대부분이 필요 없게 된다.
// 희소 다항식, 즉 0이 아닌 계수를 가진 항의 수가 다항식의 차수보다도 아주 작은 경우도 마찬가지이다.

// 공간을 절약하기 위한 또 다른 방법으로 모든 다항식을 저장하는 하나의 전역 배열 terms를 사용하는 표현을 생각해보자. 필요한 C 선언은 다음과 같다.

#define MAX_TERMS 100 // 배열 terms의 크기
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)

typedef struct {
    float coef; // 계수
    int expon; // 지수
    } polynomial;

polynomial terms[MAX_TERMS];// 다항식의 항들을 저장하는 polynomial 타입의 배열

int avail = 0; // 배열 terms에서 사용 가능한 첫 번째 위치

void attach(float coefficient, int exponent)
{ // 새로운 항을 다항식에 첨가한다.
    if (avail >= MAX_TERMS)
    {
        fprintf(stderr, "다항식에 항이 너무 많다.");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{ // A(x)와 B(x)를 더하여 D(x)를 생성한다.
    float coefficient;
    *startD = avail; // 위치
    while (startA <= finishA && startB <= finishB)
        switch (COMPARE(terms[startA].expon, terms[startB].expon))
        {
            case -1: // a의 expon이 b의 expon보다 작은 경우
                attach(terms[startB].coef, terms[startB].expon);
                startB++;
                break;
            case 0: // 지수가 같은 경우
                coefficient = terms[startA].coef + terms[startB].coef;
                if (coefficient)
                    attach(coefficient, terms[startA].expon);
                startA++;
                startB++;
                break;
            case 1: // a의 expon이 b의 expon보다 큰 경우
                attach(terms[startA].coef, terms[startA].expon);
                startA++;
        }
    /* A(x)의 나머지 항들을 첨가한다. */
    for(; startA <= finishA; startA++)
        attach(terms[startA].coef, terms[startA].expon);
    /* B(x)의 나머지 항들을 첨가한다. */
    for(; startB <= finishB; startB++)
        attach(terms[startB].coef, terms[startB].expon);
    *finishD = avail - 1;
}

int main(void) {

    return 0;
}
