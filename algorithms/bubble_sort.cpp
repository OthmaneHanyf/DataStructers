#include "library.h"

void sort(int n, int* arr)
{
    // double tab[n];
    for(int i = 0; i < n-1; i++ ){
        for(int j = n - 1; j > i; j--){
            if(arr[j]<arr[j-1]) replace(arr[j], arr[j-1]);
        }
    }
}

int main()
{
    int arr[] = {9, 5, 7, 3, 1};
    sort(5, arr);
    print(5, arr);
}