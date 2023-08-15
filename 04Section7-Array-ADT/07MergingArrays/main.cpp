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

void Merge(const Array *arr1, const Array *arr2, Array *arr3)
{
    size_t i{0};
    size_t j{0};
    size_t k{0};    // array3 index

    while ((i < arr1->length) && (j < arr2->length))
    {
        if(arr1->A[i] <= arr2->A[j]){
            arr3->A[k] = arr1->A[i++];
        }
        else{
            arr3->A[k] = arr2->A[j++];
        }
        ++(arr3->length);
        ++k;
    }

    for (size_t index = i; index < (arr1->length); index++)
    {
        arr3->A[k++] = arr1->A[index];
        ++(arr3->length);
    }
    
    for (size_t index = j; index < (arr2->length); index++)
    {
        arr3->A[k++] = arr2->A[index];
        ++(arr3->length);
    }
}
// m = arr1->length
// n = arr2->length
// T - O(m + n)

int main()
{
    Array array1{{3, 8, 16, 20, 25}, 5, 5};
    Array array2{{4, 10, 12, 22, 23}, 5, 5};
    Array array3{{}, 10, 0};

    std::cout << "Before Merging" << std::endl;
    std::cout << "array1:";
    Display(array1);
    std::cout << "array2:";
    Display(array2);
    std::cout << "array3:";
    Display(array3);

    Merge(&array1, &array2, &array3);
    
    std::cout << "After Merging" << std::endl;
    std::cout << "array3:";
    Display(array3);

    return 0;

}













