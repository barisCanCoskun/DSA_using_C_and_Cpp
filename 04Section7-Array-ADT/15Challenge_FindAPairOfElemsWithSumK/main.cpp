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

int max(const Array *arr)
{
    int max = arr->A[0];
    for (size_t i = 0; i < arr->length; i++)
    {
        if(max < (arr->A[i]))
        {
            max = arr->A[i];
        }
    }
    return max;
};

void FindPairElements(const Array *arr, int k)
{
    int *hashArr = new int [max(arr) + 1];

    for (size_t i = 0; i < (size_t)max(arr); i++)
        hashArr[i] = 0;

    std::cout << std::endl;

    for (size_t i = 0; i < arr->length; ++i)
    {   
        if ((k >= arr->A[i]) && hashArr[k - arr->A[i]])
            std::cout << arr->A[i] << " and " << k - arr->A[i] << " inside in hash" << std::endl;
        ++hashArr[arr->A[i]];
    }

    delete [] hashArr;
    hashArr = nullptr; 
}

int main()
{
    Array array1{{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 10, 10};
    std::cout << "array1:";
    Display(array1);

    FindPairElements(&array1, 10);
    
    Array array2{{18, 4, 10, 7, 8, 5, 11, 2, 20, 23}, 10, 10};
    std::cout << "array2:";
    Display(array2);

    FindPairElements(&array2, 15);

    return 0;
}













