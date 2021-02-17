#include <iostream>
#include "library.h"
using namespace std;

void merge(int list[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for ( int i = 0; i < n1; i++ ){
        L[i] = list[l + i];
    }
    for ( int i = 0; i < n2; i++ ){
        R[i] = list[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while( i < n1 && j < n2 ){
        if( L[i] < R[j] ){
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
    k++;
    }

    while ( i < n1 ){
        list[k] = L[i];
        i++;
        k++;
    }

    while ( j < n2 ){
        list[k] = R[j];
        j++;
        k++;
    }
}

void sort(int list[], int leftLastIndex, int rightLastIndex)
{
    if ( leftLastIndex < rightLastIndex ){
        int middleIndex = (( leftLastIndex + rightLastIndex + 1) / 2) - 1 ;
        sort(list, leftLastIndex, middleIndex);
        sort(list, middleIndex + 1, rightLastIndex);
        merge(list, leftLastIndex, middleIndex , rightLastIndex);
    }
}

int main()
{
    int list[] = { 7, 2, 4, 8, 1, 6, 3, 5 };
    int listSize = sizeof(list)/sizeof(*list);
    sort(list, 0, listSize - 1);
    print(listSize, list);
}