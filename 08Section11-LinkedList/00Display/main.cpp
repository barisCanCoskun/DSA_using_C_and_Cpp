#include<iostream>
#include <limits.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
}Node;

Node *first{nullptr};

Node *create(int a[], int n){
    Node *temp, *last;

    first = new Node;
    first->data = a[0];
    first->next = nullptr;
    last = first;

    for (size_t i{1}; i < n; i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    return first;
}

void display(const Node *ptr)
{
    while (ptr != nullptr){
        std::cout << ptr->data << " |-> ";
        ptr = ptr->next;
    }
    std::cout << " /0";
    std::cout << std::endl;
}

// display list reversely
void display_recursive(const Node *ptr)
{
    if(ptr != nullptr){
        display_recursive(ptr->next);
        std::cout <<  ptr->data << ", ";
    }
}

int count_recursive(const Node *ptr){
    if(ptr)
        return count_recursive(ptr->next) + 1;
    else
        return 0;
}

int count(const Node *ptr){
    int number_nodes{};

    while (ptr->next){
        ++number_nodes;
        ptr = ptr->next;
    }
    return number_nodes;
}

int sum_recursive(const Node *ptr){
    if(ptr)
        return sum_recursive(ptr->next) + ptr->data;
    else
        return 0;
}

int maximumData(const Node * ptr){
    int max{INT_MIN};
    while (ptr != nullptr){
        if (ptr->data > max)
            max = ptr->data;
        ptr = ptr->next;
    }
    return max;
}

int maximum_recursive(const Node *ptr){
    int x{};
    if(ptr){
        x = maximum_recursive(ptr->next);
        return (x > ptr->data) ? x : ptr->data;
    }
    return INT_MIN;
}

int maximum_recursive_long(const Node *ptr){
    int x{};
    if(ptr == nullptr)
        return INT_MIN;
    else{
        x = maximum_recursive_long(ptr->next);
        if(x > ptr->data)
            return x;
        else
            return ptr->data;
    }
}

int main()
{
    int A[]{1, 4, 8, 2, 9};

    Node *first = create(A, sizeof(A)/sizeof(A[0]));

    std::cout << first << std::endl;
    display(first);

    std::cout << first << std::endl;

    display_recursive(first);
    std::cout << std::endl;

    std::cout << "Count of nodes in list: " << count_recursive(first) << std::endl;
    std::cout << "Sum of data of nodes in list: " << sum_recursive(first) << std::endl;
    std::cout << "Maximum data of nodes in list: " << maximumData(first) << std::endl;


    // int x{7};
    // int *ptr{&x};
    // std::cout << sizeof(Node) << std::endl;
    // std::cout << sizeof(int) << std::endl;
    // std::cout << sizeof(ptr) << std::endl;
    // std::cout << sizeof(nullptr) << ", " << sizeof(NULL) << std::endl;
    std::cout << nullptr << ", " << NULL << std::endl;

}













