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
    std::cout << "Element " << key << " is being linear searched..." << std::endl;
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

int BinarySearch(const Array *arr, int key)
{
    size_t low{0};
    size_t high{arr->length - 1};
    size_t mid{(high + low) / 2};

    std::cout << "Element " << key << " is being binary searched..." << std::endl;

    while(low <= high){
        mid = (high + low) / 2;
        if(arr->A[mid] == key)
            return (int)mid;
        else if(arr->A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int RecursiveBinarySearch(const Array *arr, size_t low, size_t high, int key)
{
    size_t mid{(high + low) / 2};

    std::cout << "Element " << key << " is being binary searched..." << std::endl;

    if(low <= high){
        if(arr->A[mid] == key)
            return (int)mid;
        else if(arr->A[mid] > key)
            return RecursiveBinarySearch(arr, low, mid - 1, key);
        else
            return RecursiveBinarySearch(arr, mid + 1, high, key);
    }
    
    return -1;
}

int Get(const Array *arr, int index)
{
    if((index >= 0) && ((size_t)index < arr->length))
        return arr->A[index];
    else
        return -1;
}

void Set(Array *arr, int index, int key)
{
    if((index >= 0) && ((size_t)index < arr->length))
        arr->A[index] = key;
}

int Max(const Array *arr)
{
    int max{};
    for (size_t i = 0; i < (arr->length); i++)
    {
        if((arr->A[i]) > max)
            max = (arr->A[i]);
    }
    return max; 
}

int Min(const Array *arr)
{
    int min{arr->A[0]};
    for (size_t i = 1; i < (arr->length); i++)
    {
        if((arr->A[i]) < min)
            min = (arr->A[i]);
    }
    return min; 
}

int Sum(const Array *arr)
{
    int sum{};
    for (size_t i = 0; i < (arr->length); i++){
        sum += (arr->A[i]);
    }
    return sum; 
}

int RecursiveSum(const Array *arr, int index)
{
    if (index == 0)
        return arr->A[index];
    else
        return RecursiveSum(arr, index - 1) + arr->A[index];
}
// T - O(n)
// S - O(n)


int main()
{
    Array array{{8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 10, 10};
    Display(array);

    std::cout << "\nRecursively Sum of array1 elements: " << RecursiveSum(&array, array.length - 1) << std::endl;
    std::cout << array.A[14] << std::endl;

    std::cout << std::endl;
}













