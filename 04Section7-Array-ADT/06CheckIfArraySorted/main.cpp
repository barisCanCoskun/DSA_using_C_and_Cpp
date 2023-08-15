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

void Reverse(Array *arr)
{
    size_t low{0};
    size_t high{arr->length - 1};

    while ((low < high) && (low != high))
    {
        swap(arr->A[low], arr->A[high]);
        ++low;
        --high;
    }
}

void LeftShift(Array *arr)
{
    for (size_t i = 0; i < arr->length; i++)
    {
        arr->A[i - 1] = arr->A[i];
        arr->A[i] = 0;
    }
    
}

void LeftRotate(Array *arr)
{
    int temp{arr->A[0]};
    for (size_t i = 0; i < arr->length; i++)
    {
        arr->A[i - 1] = arr->A[i];
        arr->A[i] = 0;
    }
    arr->A[arr->length - 1] = temp;
}

void InsertSorted(Array *arr, int value)
{
    if((arr->length < arr->size) && (arr->A[arr->length - 1] > value)){
        for (size_t i = arr->length - 1; i > 0; i--)
            if(arr->A[i] > value)
                arr->A[i + 1] = arr->A[i];
            else{
                arr->A[i + 1] = value;
                break;
            }

        ++(arr->length);        
    }
    else
        Append(arr, value);

}

bool IsSorted(const Array *arr)
{
    for (size_t i = 0; i < (arr->length - 1); i++)
    {
        if(arr->A[i] > arr->A[i + 1])
            return false;
    }
    return true;
}

void Rearrange(Array *arr)
{
    size_t i = 0;
    size_t j = (arr->length - 1);
    while (i < j)
    {
        while(arr->A[i] < 0)
            ++i;
        while(arr->A[j] >= 0)
            --j;        
        if(i < j)
            swap(arr->A[i], arr->A[j]);
    }
}

int main()
{
    Array array{{4, 8, 13, 16, 30, 25, 28, 33}, 10, 8};
    Display(array);

    InsertSorted(&array, 18);
    std::cout << "\nAfter inserted to sorted array: ";
    Display(array);

    if (IsSorted(&array))
        std::cout << "Array was sorted" << std::endl;
    else
        std::cout << "Array was not sorted" << std::endl;
    
    Array array1{{4, -8, 13, 16, -20, 25, -28, -33}, 10, 8};
    Display(array1);
    Rearrange(&array1);std::cout << "\nAfter rearrange array1: ";
    Display(array1);


    std::cout << std::endl;
}













