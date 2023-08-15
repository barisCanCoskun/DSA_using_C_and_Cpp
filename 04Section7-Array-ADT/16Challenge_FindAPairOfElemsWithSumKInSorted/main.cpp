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

void FindPairElementsSorted(const Array *arr, int k)
{
    for (size_t i = 0, j = arr->length - 1; i < j;)
    {
        if (arr->A[i] + arr->A[j] == k)
        {
            std::cout << arr->A[i] << " + " << arr->A[j] << " = " << k << "\n" << std::endl;
            ++i;
            --j;
        }
        else if(arr->A[i] + arr->A[j] < k)
            ++i;
        else
            --j;   
    }
}

int main()
{
    Array array1{{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 10, 10};
    std::cout << "array1:";
    Display(array1);

    FindPairElementsSorted(&array1, 10);
    
    Array array2{{2, 4, 5, 7, 8, 10, 11, 18, 20, 23}, 10, 10};
    std::cout << "array2:";
    Display(array2);

    FindPairElementsSorted(&array2, 15);

    return 0;
}













