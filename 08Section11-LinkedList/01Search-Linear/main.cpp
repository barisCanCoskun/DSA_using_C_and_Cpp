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
    std::cout << "/0";
    std::cout << std::endl;
}

Node *search_linear(Node *ptr, int key){
    while (ptr != nullptr){
        if (ptr->data == key){
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}

Node *search_linear_recursive(Node *ptr, int key){
    if(ptr == nullptr)
        return nullptr;
    if(ptr->data == key)
        return ptr;
    else
        return search_linear_recursive(ptr->next, key);
}

Node *search_linear_move_to_head(Node *ptr, int key){
    Node *q{nullptr};
    while (ptr != nullptr){
        if (ptr->data == key){
            q->next = ptr->next;
            ptr->next = first;
            first = ptr;
            return ptr;
        }
        q = ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

int main()
{
    int A[]{1, 4, 8, 2, 9, 17, 5, 21, 10};

    first = create(A, sizeof(A)/sizeof(A[0]));

    std::cout << first << std::endl;
    display(first);

    int key{2};
    Node *search_result = search_linear_recursive(first, key);
    if(search_result)
        std::cout << "Key " << search_result->data << " found at node: " << search_result << " recursively" << std::endl;
    else
        std::cout << "Key " << key << " not in list." << std::endl;

    key = 3;
    search_result = search_linear_recursive(first, key);
    if(search_result)
        std::cout << "Key " << key << " found at node: " << search_result << " recursively"  << std::endl;
    else
        std::cout << "Key " << key << " not in list." << std::endl;

    key = 9;
    search_result = search_linear(first, key);
    if(search_result)
        std::cout << "Key " << key << " found at node: " << search_result << std::endl;
    else
        std::cout << "Key " << key << " not in list." << std::endl;

    key = 2;
    search_result = search_linear_move_to_head(first, key);
    if(search_result)
        std::cout << "Key " << key << " found at node: " << search_result  << " and moved to head."<< std::endl;
    else
        std::cout << "Key " << key << " not in list." << std::endl;
    display(first);

    key = 5;
    search_result = search_linear_move_to_head(first, key);
    if(search_result)
        std::cout << "Key " << key << " found at node: " << search_result  << " and moved to head."<< std::endl;
    else
        std::cout << "Key " << key << " not in list." << std::endl;
    display(first);

}













