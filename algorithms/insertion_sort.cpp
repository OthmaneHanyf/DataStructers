#include "library.h"

void sort(int n, int list[])
{
    int value, j;
    for(int i = 1; i < n; i++){
        value = list[i];
        j = i;
        while ( j > 0 && list[j-1] > value ){
            list[j] = list[j-1];
            j--;
        }
        list[j] = value;
    }
}

int main()
{
    int list[] = {3, 2, 5, 1, 4};
    int n = sizeof(list)/sizeof(*list);
    sort(n, list);
    print(n, list);
}