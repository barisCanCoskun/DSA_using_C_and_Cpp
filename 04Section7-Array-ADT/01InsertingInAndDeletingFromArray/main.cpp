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
    if((index >= 0) && (index < arr->length) && (arr->length < arr->size)){
        for (size_t i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        
        arr->A[index] = x;
        ++(arr->length);        
    }
    else if(index == arr->length){
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
    if((index >= 0) && (index < arr->length) && (arr->length < arr->size)){
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

int main()
{
    Array arr{{2, 3, 4, 5, 6}, 10, 5};

    Display(arr);

    Append(&arr, 7);
    Display(arr);

    Insert(&arr, 3, 10);
    Display(arr);

    Insert(&arr, 0, 10);
    Display(arr);

    Insert(&arr, -3, 10);
    Display(arr);

    std::cout << "Element " << Delete(&arr, 2) << " deleted." << std::endl;
    Display(arr);

}













