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

int FindMissingElement(const Array *arr)
{
    for (size_t i = 0; i < arr->length - 1; i++)
    {
        if ((arr->A[i] + 1) != arr->A[i + 1])
        {
            return (arr->A[i] + 1);
        }
        
    }
    return -1;
}

int main()
{
    int missing{};
    Array array1{{1, 2, 3, 4, 5, 6, 8, 9, 10, 11}, 10, 10};
    std::cout << "array1:";
    Display(array1);

    missing = FindMissingElement(&array1);
    if (missing > 0){
        std::cout << "Missing element: " << missing << "\n" << std::endl;
    }
    else
        std::cout << "Missing element not found. \n" << std::endl;
    
    Array array2{{6, 7, 8, 9, 10, 11, 12, 14, 15, 16}, 10, 10};
    std::cout << "array2:";
    Display(array2);

    missing = FindMissingElement(&array2);
    if (missing > 0){
        std::cout << "Missing element: " << missing << "\n" << std::endl;
    }
    else
        std::cout << "Missing element not found. \n" << std::endl;

    Array array3{{6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 10, 10};
    std::cout << "array3:";
    Display(array3);

    missing = FindMissingElement(&array3);
    if (missing > 0){
        std::cout << "Missing element: " << missing << "\n" << std::endl;
    }
    else
        std::cout << "Missing element not found. \n" << std::endl;    

    return 0;

}













