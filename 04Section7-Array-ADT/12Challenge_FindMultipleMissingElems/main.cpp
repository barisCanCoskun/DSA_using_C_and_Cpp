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

int FindMissingElements(const Array *arr)
{
    int missing{};
    for (size_t i = 0; i < arr->length - 1; i++)
    {
        if ((arr->A[i] + 1) != arr->A[i + 1])
        {
            missing = arr->A[i] + 1;
            while (missing < arr->A[i + 1])
            {
                std::cout << "Missing element: " << missing << "\n" << std::endl;
                ++missing;
            }   
        }
    }
    return missing;
}

int main()
{
    Array array1{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    std::cout << "array1:";
    Display(array1);

    if (!FindMissingElements(&array1))
        std::cout << "Missing element not found. \n" << std::endl;
    
    Array array2{{6, 7, 8, 11, 12, 16, 17, 18, 19, 20}, 10, 10};
    std::cout << "array2:";
    Display(array2);

    if (!FindMissingElements(&array2))
        std::cout << "Missing element not found. \n" << std::endl;

    return 0;

}













