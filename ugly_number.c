//
// Created by Jim on 2017/12/25.
//

#include <stdio.h>

int get_min(int n2, int n3, int n5, int n7){
    int temp = n2 < n3 ? n2 : n3;
    temp = temp < n5 ? temp : n5;
    temp = temp < n7 ? temp : n7;
    return temp ;
}

int find_ugly_number(int max){
    int ugly_number_queue[max];
    ugly_number_queue[0] = 1;
    int index = 1;
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    int p7 = 0;

    while (index < max){
        int min = get_min(ugly_number_queue[p2] * 2, ugly_number_queue[p3] * 3,
                          ugly_number_queue[p5] * 5, ugly_number_queue[p7] * 7);
        ugly_number_queue[index] = min;
        ugly_number_queue[index] = min;
        while (ugly_number_queue[p2] * 2 <= ugly_number_queue[index]) {
            p2++;
        }
        while (ugly_number_queue[p3] * 3 <= ugly_number_queue[index]) {
            p3++;
        }
        while (ugly_number_queue[p5] * 5 <= ugly_number_queue[index]) {
            p5++;
        }
        while (ugly_number_queue[p7] * 7 <= ugly_number_queue[index]) {
            p7++;
        }
        index++;
    }
    return ugly_number_queue[index-1];
}


int main(void){
    printf("Input N and enter.\n");
    int index;
    scanf("%d", &index);
    printf("The %d-th ugly number is %d.", index, find_ugly_number(index));
    return 0;
}
