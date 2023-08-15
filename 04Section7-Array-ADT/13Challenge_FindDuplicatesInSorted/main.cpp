#include<iostream>

typedef struct _Array
{
    int A[10];
    size_t size;
    size_t length;
}Array;

void Display(Array arr){
    std::cout << "\nElements are:\n";
    for (size_t i = 0; i < arr.length; i++)
    {
        std::cout << arr.A[i] << " ";
    }
    std::cout << std::endl;  
}

void FindDuplicateElements(const Array *arr)
{
    for (size_t i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] == arr->A[i + 1])
        {
            std::cout << "Duplicate element: " << arr->A[i] << "\n" << std::endl;
            while (arr->A[i] == arr->A[i + 1])
                ++i;
        }   
    }
}

int main()
{
    Array array1{{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 10, 10};
    std::cout << "array1:";
    Display(array1);

    FindDuplicateElements(&array1);
    
    Array array2{{6, 7, 8, 9, 10, 11, 12, 14, 15, 16}, 10, 10};
    std::cout << "array2:";
    Display(array2);

    return 0;
}













