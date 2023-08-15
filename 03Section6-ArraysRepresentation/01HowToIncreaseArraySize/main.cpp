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
    int *p = new int [5];

    p[0] = 5;
    p[1] = 8;
    p[2] = 9;
    p[3] = 6;
    p[4] = 4;

    print(p, 5);

    int *q = new int[10];
    
    for (size_t i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    delete [] p;
    p = q;
    q = nullptr;
   
    print(p, 10);
    
}













