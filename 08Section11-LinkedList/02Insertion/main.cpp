#include<iostream>
#include <limits.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
}Node;

Node *first{nullptr};
size_t number_nodes{};

Node *create(int a[], int n){
    Node *temp, *last;

    first = new Node;
    ++number_nodes;
    first->data = a[0];
    first->next = nullptr;
    last = first;

    for (size_t i{1}; i < n; i++)
    {
        temp = new Node;
        ++number_nodes;
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

Node *insertion(Node *ptr, int value, int position){

    if((position >= 0) && (position <= number_nodes)){       // bound check
        Node *temp{new Node};
        ++number_nodes;
        temp->data = value;

        if(position == 0){
            temp->next = first;
            first = temp;
        }
        else{
            for (size_t i{1}; i < position; i++){
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
        return ptr;
    }
    return nullptr;
}
// for (size_t i{1}; (i < position) && ptr->next; i++)

void insert_to_first(int value){
    Node *temp{new Node};
    temp->data = value;

    temp->next = first;
    first = temp;
}

int main()
{
    int A[]{1, 4, 8, 2, 9, 17, 5, 21, 10};

    first = create(A, sizeof(A)/sizeof(A[0]));

    std::cout << first << std::endl;
    display(first);

    Node *insertion_result{};
    int value{}, position{};
    std::cout << "\nEnter value (for exiting - 1): ";
    std::cin >> value;
    while (value != -1){
        std::cout << "Enter position in btw 0 - " << number_nodes << " : ";
        std::cin >> position;

        insertion_result = insertion(first, value, position);
        if(insertion_result)
            std::cout << "\nValue " << value << " inserted after position: " << position << std::endl;
        else
            std::cout << "\nPosition " << position << " out of bounds.\n" << std::endl;

        display(first);
        
        std::cout << "\nEnter value (for exiting - 1): ";
        std::cin >> value;
    }

    value = 13;
    insert_to_first(value);
    std::cout << "\nValue " << value << " inserted to first." << std::endl;

    

    display(first);

}













