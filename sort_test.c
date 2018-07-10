#include<stdio.h>
#include "sort.h"

int main(){
    int i;
    int a[10] = {3,5,2,56,8,43,3,4,1,9};
    //quick_sort(a, 0, 9);
    //select_sort(a, 10);
    heap_sort(a, 10);
    printf("\n\n");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n\n");
}

