#include<iostream>

typedef struct _Array
{
    int A[10];
    size_t size;
    size_t length;
}Array;

void Display(const Array *arr){
    std::cout << "\nElements are:\n";
    for (size_t i = 0; i < arr->length; i++)
    {
        std::cout << arr->A[i] << " ";
    }
    std::cout << std::endl;  
}

Array * Merge(const Array *arr1, const Array *arr2)
{
    size_t i{0};
    size_t j{0};
    size_t k{0};    // array3 index

    // buraya tekrar bakılmalı ! : sebep: access violation  -->  structure initialize yapıldı.
    // length initialize yapılmadığı için array in dışına taşıyordu. 
    Array *arr3 = new Array{{}, 10, 0};

    while ((i < arr1->length) && (j < arr2->length))
    {
        if(arr1->A[i] <= arr2->A[j]){
            arr3->A[k] = arr1->A[i++];
        }
        else{
            arr3->A[k] = arr2->A[j++];
        }
        ++k;
    }

    for (size_t index = i; index < (arr1->length); index++)
    {
        arr3->A[k++] = arr1->A[index];
    }
    
    for (size_t index = j; index < (arr2->length); index++)
    {
        arr3->A[k++] = arr2->A[index];
    }

    arr3->length = k;
    return arr3;
}
// m = arr1->length
// n = arr2->length
// T - O(m + n)


Array * Union(const Array *arr1, const Array *arr2)
{
    size_t i{0};
    size_t j{0};
    size_t k{0};    // array3 index

    Array *arr3 = new Array{{}, 10, 0};

    while ((i < arr1->length) && (j < arr2->length))
    {
        if(arr1->A[i] == arr2->A[j]){
            arr3->A[k] = arr1->A[i++];
            ++j;
        }
        else if(arr1->A[i] < arr2->A[j]){
            arr3->A[k] = arr1->A[i++];
        }
        else{
            arr3->A[k] = arr2->A[j++];
        }
        ++k;
    }

    for (size_t index = i; index < (arr1->length); index++)
    {
        arr3->A[k++] = arr1->A[index];
    }
    
    for (size_t index = j; index < (arr2->length); index++)
    {
        arr3->A[k++] = arr2->A[index];
    }

    arr3->length = k;
    return arr3;
}
// m = arr1->length
// n = arr2->length
// T - O(n ^ 2)

Array * Intersection(const Array *arr1, const Array *arr2)
{
    size_t i{0};
    size_t j{0};
    size_t k{0};    // array3 index

    Array *arr3 = new Array{{}, 10, 0};

    while ((i < arr1->length) && (j < arr2->length))
    {
        if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
            ++j;
        }
        else if(arr1->A[i] < arr2->A[j]){
            ++i;
        }
        else{
            ++j;
        }
    }

    arr3->length = k;
    return arr3;
}
// m = arr1->length
// n = arr2->length
// T - O(m + n)
// O(n)

// A - B (difference of A to B)
// array1 - array2
Array * Difference(const Array *arr1, const Array *arr2)
{
    size_t i{0};
    size_t j{0};
    size_t k{0};    // array3 index

    Array *arr3 = new Array{{}, 10, 0};

    while ((i < arr1->length) && (j < arr2->length))
    {
        if(arr1->A[i] == arr2->A[j]){
            ++i;
            ++j;
        }
        else if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else{
            ++j;
        }
    }

    for (size_t index = i; index < (arr1->length); index++)
    {
        arr3->A[k++] = arr1->A[index];
    }
    
    for (size_t index = j; index < (arr2->length); index++)
    {
        arr3->A[k++] = arr2->A[index];
    }

    arr3->length = k;
    return arr3;
}
// m = arr1->length
// n = arr2->length
// T - O(m + n)
// O(n)

int main()
{
    Array array1{{3, 10, 16, 20, 25}, 10, 5};
    Array array2{{4, 10, 20, 22, 23}, 10, 5};

    std::cout << "Before Union Merging" << std::endl;
    std::cout << "array1:";
    Display(&array1);
    std::cout << "array2:";
    Display(&array2);
    Array *array3 = Union(&array1, &array2);
    
    std::cout << "\nAfter Union Merging" << std::endl;
    std::cout << "array3:";
    Display(array3);

    Array *array4 = Intersection(&array1, &array2);
    
    std::cout << "\nIntersection Merging" << std::endl;
    std::cout << "array4:";
    Display(array4);

    Array *array5 = Difference(&array1, &array2);
    
    std::cout << "\nDifference Merging" << std::endl;
    std::cout << "array5:";
    Display(array5);

    return 0;

}













