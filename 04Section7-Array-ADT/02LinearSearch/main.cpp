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

void Append(Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[(arr->length)++] = x;
    }
    else if(arr->length == arr->size)
        std::cout << "Array is Full" << std::endl;
}

void Insert(Array *arr, int index, int x)
{
    if((index >= 0) && ((size_t)index < arr->length) && (arr->length < arr->size)){
        for (size_t i = arr->length; i > (size_t)index; i--)
            arr->A[i] = arr->A[i - 1];
        
        arr->A[index] = x;
        ++(arr->length);        
    }
    else if((size_t)index == arr->length){
        Append(arr, x);
    }
    else{
        std::cout << "Index must be in between: 0 - 10" << std::endl;
        std::cout << index << " index is invalid." << std::endl;
    }
}
// T - O(n)
// Best : O(1)
// Worst : O(n)

int Delete(Array *arr, int index)
{
    int x{};
    if((index >= 0) && ((size_t)index < arr->length) && (arr->length < arr->size)){
        x = arr->A[index];

        for (size_t i = index; i < (arr->length - 1); i++)
            arr->A[i] = arr->A[i + 1];
        
        --(arr->length);        
    }
    else{
        std::cout << "Index must be in between: 0 - 10" << std::endl;
        std::cout << index << " index is invalid." << std::endl;
    }

    return x;
}
// T - O(n)
// Best : O(1)
// Worst : O(n)

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int LinearSearch(Array *arr, int key)
{
    std::cout << "Element " << key << " is being swaped..." << std::endl;
    for (size_t i = 0; i < (size_t)arr->length; i++)
    {
        if(key == arr->A[i]){
            // swap(arr->A[i], arr->A[i - 1]);
            swap(arr->A[i], arr->A[0]);
            return (int)i;
        }
    }
    return -1;    
}

int main()
{
    Array array{{8, 9, 4, 7, 6, 3, 10, 5, 14, 2}, 10, 10};

    Display(array);

    int result = LinearSearch(&array, 3);

    if (result > 0){
        std::cout << "\n" << result << " th element found in array." << std::endl;
    }
    else
        std::cout << "\n" << "Element not found in array." << std::endl;

    Display(array);
    result = LinearSearch(&array, 14);

    if (result > 0){
        std::cout << "\n" << result << " th element found in array." << std::endl;
    }
    else
        std::cout << "\n" << "Element not found in array." << std::endl;

    result = LinearSearch(&array, 11);

    if (result > 0){
        std::cout << "\n" << result << " th element found in array." << std::endl;
    }
    else
        std::cout << "\n" << "Element not found in array." << std::endl;

    std::cout << std::endl;
}













