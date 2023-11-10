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

// temp->data = value;                   // C-style
// temp->next = nullptr;                 // C-style

Node *insert(Node *ptr, int value){
    Node *temp{new Node{value, nullptr}};

    while(ptr && (value > ptr->data)){                  // first == nullptr
        if(ptr->next && (value > ptr->next->data))
            ptr = ptr->next;
        else{
            temp->next = ptr->next;
            ptr->next = temp;
            return temp;
        }
    }
    temp->next = first;
    first = temp;
    return temp;
}

Node *insert_instructor_choice(Node *ptr, int value){
    Node *following{};
    Node *temp{new Node};
    temp->data = value;

    if(!ptr || (value <= ptr->data)){          // first == null
        temp->next = first;
        first = temp;
        return temp;
    }

    while(ptr && (value > ptr->data)){
        following = ptr;
        ptr = ptr->next;
    }
    temp->next = following->next;
    following->next = temp;
    return temp;
    
}

void insert_to_first(int value){
    Node *temp{new Node};
    temp->data = value;

    temp->next = first;
    first = temp;
}

int main()
{
    // int A[]{1, 4, 5, 8, 12, 14, 17, 20, 23};

    // first = create(A, sizeof(A)/sizeof(A[0]));

    std::cout << first << std::endl;
    display(first);

    int value{};
    std::cout << "\nEnter value (for exiting - 1): ";
    std::cin >> value;
    while (value != -1){
        insert(first, value);
        std::cout << "\nValue " << value << " inserted: " << std::endl;
        display(first);
        
        std::cout << "\nEnter value (for exiting - 1): ";
        std::cin >> value;
    }

}













