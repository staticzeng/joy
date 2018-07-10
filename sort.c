#include "sort.h"

void swap(int* l, int i, int j){
    int temp;
    temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

//冒泡排序
void bubble_sort(int* l, int size){
    int i, j;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(l[j] > l[j+1]){
                swap(l, j, j+1);
            }
        }
    }
}

//选择排序
void select_sort(int* l, int size){
    int i, j, max, temp;
    for(i = 0; i < size - 1; i++){
        max = 0;
        for(j = 1; j < size - i; j++){
            if(l[j] > l[max])
                max = j;
        }
        if(temp != size-i-1){
            swap(l, max, size-i-1);
        }
    }
}


//插入排序
void insert_sort(int* l, int size){
    int i, j, temp;
    for(i = 1; i < size; i++){
        j = i;
        while(j - 1 >= 0 && l[j] < l[j-1]){
            swap(l, j, j-1);
            j--;
        }
    }
}


//希尔排序
void shell_sort(int* l, int size){
    return;
}


//快速排序
void quick_sort(int* l, int start, int end){
    int i = start;
    int j = end;
    if(i == j)
        return;
    while(j > i){
        while(l[i] <= l[j] && i < j)
            i++;
        if(i < j)
            swap(l, i, j);
        while(l[j] >= l[i] && i < j)
            j--;
        if(i < j)
            swap(l, i, j);
    }
    if(i > start)
        quick_sort(l, start, i - 1);
    if(end > j)
        quick_sort(l, j + 1, end);
}


//堆排序
void heap_sort(int* l, int size){
    int i, tmp, max, end, mid = size / 2;
    if(size <= 1)
        return;
    while(mid>0){
        tmp = mid;
        while(tmp * 2 <= size){
            if(tmp*2 + 1 > size)
                max = tmp*2;
            else
                max = l[tmp*2-1] > l[tmp*2] ? tmp*2 : tmp*2+1;
            if(l[tmp-1] < l[max-1]){
                swap(l, tmp-1, max-1);
                tmp = max;
            } else
                break;
        }
        mid--;
    }

    for(i = 0; i < size - 1; i++){
        end = size - 1 - i;
        swap(l, 0, end);
        tmp = 1;
        while(tmp*2 <= end){
            if(tmp*2 + 1 > end)
                max = tmp*2;
            else
                max = l[tmp*2-1] > l[tmp*2] ? tmp*2 : tmp*2+1;
            if(l[tmp-1] < l[max-1]){
                swap(l, tmp-1, max-1);
                tmp = max;
            } else
                break;
        }
    }
}
