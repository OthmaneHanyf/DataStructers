#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#include <iostream>
using namespace std;

void print(int n, int* arr)
{
    cout << "[ ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    cout << "]" << endl;
}

void replace(int& a, int& b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

#endif //_HEADER_FILE_H_

