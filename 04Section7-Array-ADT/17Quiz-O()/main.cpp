#include<iostream>

int main()
{
    int A[] = {1, 5, 9, 15, 4, 12, 10, 17, 3, 11};
    int secLargest{};
    int largest{A[0]};
    size_t size{sizeof(A) / sizeof(A[0])};

    for (size_t i = 1; i < size; i++)
        if (A[i] > secLargest)
            if (A[i] > largest){
                secLargest = largest;
                largest = A[i];
            }        
    std::cout << "second largest: " << secLargest << std::endl;

}













