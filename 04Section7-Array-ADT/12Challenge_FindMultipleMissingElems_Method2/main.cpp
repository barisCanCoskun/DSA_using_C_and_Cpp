#include<iostream>

typedef struct _Array
{
    int A[12];
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

void FindMissingElements(const Array *arr1, Array *arr2)
{
    for (size_t i = 0; i < arr1->length; i++)
    {
        ++(arr2->A[arr1->A[i]]);
    }

    for (size_t i = 1; i < arr2->length; i++)
    {
        if(!arr2->A[i])
            std::cout << "Missing element: " << i << "\n" << std::endl;
    }
    
}

int main()
{
    Array array1{{3, 7, 4, 9, 12, 6, 1, 11, 2, 10}, 12, 10};
    Array array2{{}, 12, 12};
    std::cout << "array1:";
    Display(array1);
    std::cout << "array2:";
    Display(array2);

    FindMissingElements(&array1, &array2);

    return 0;
}













