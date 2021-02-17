#include "library.h"

void sort(int n, int* list)
{
    int min_value, min_index;
    for(int i = 0; i<n; i++){
        min_value = list[i];
        min_index = i;
        for(int j = i; j<n; j++){
            if(list[j]<min_value){
                min_value = list[j];
                min_index = j;
            }
        }
        if(min_index != i){
            replace(list[i], list[min_index]);
        }
    }
}

int main()
{
    int arr[] = {9, 5, 7, 3, 1};
    sort(5, arr);
    print(5, arr);
}