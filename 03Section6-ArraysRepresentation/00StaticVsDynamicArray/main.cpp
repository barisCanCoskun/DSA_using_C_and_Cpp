#include<iostream>
#include<stdlib.h>

void print(const int *p, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        std::cout << p[i] << " " ;
    }
    std::cout << std::endl;
}

int main()
{
    // this array will be created inside stack 
    int A[10] = {2, 4, 6, 8, 10};

    int *p;

    // allocate memory in heap
    p = (int *)malloc(5 * sizeof(int)); // with C
    // p = new int [5];                 // with C++
    p[0] = 3;

    for (size_t i = 1; i < 5; i++)
    {
        p[i] = p[i-1] + 2;
    }
    
    print(A, 5);
    print(p, 5);
}













