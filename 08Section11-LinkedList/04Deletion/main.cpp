#include<iostream>
#include <limits.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
}Node;

Node *first{nullptr};
size_t number_nodes{};
int deleted_value{};

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

    if((position >= 0) && (position <= number_nodes + 1)){       // bound check
        Node *temp{new Node};
        ++number_nodes;
        temp->data = value;

        if(position == 0){
            temp->next = first;
            first = temp;
        }
        else{
            for (size_t i{1}; i < position - 1; i++){
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
        return ptr;
    }
    return nullptr;
}

Node *delete_list(Node *ptr, int position){
    if(ptr){
        if(position == 1){
            first = first->next;
            deleted_value = ptr->data;
            delete ptr;
            --number_nodes;
            return first;
        }
        if((position > 1) && (position <= number_nodes)){       // bound check
            Node *following{};  
            for (size_t i{1}; i < position; i++){
                following = ptr;
                ptr = ptr->next;
            }
            following->next = ptr->next;
            deleted_value = ptr->data;
            delete ptr;
            --number_nodes;
            return following;
        }
        return nullptr;
    }
    
    std::cout << "There is no list." << std::endl;
    return nullptr;
}

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
    int A[]{1, 4, 8, 2, 9, 17, 5, 21, 10};

    first = create(A, sizeof(A)/sizeof(A[0]));

    std::cout << first << std::endl;
    display(first);

    Node *insertion_result{};
    int value{}, position{};
    std::cout << "\nFor Insertion enter value (for exiting - 1): ";
    std::cin >> value;
    while (value != -1){
        std::cout << "Enter position in btw 0 - " << number_nodes + 1 << " : ";
        std::cin >> position;

        insertion_result = insertion(first, value, position);
        if(insertion_result){
            std::cout << "\nNode at position: " << position 
            << " with value: " << value << " inserted." << std::endl;
        }
        else
            std::cout << "\nPosition " << position << " out of bounds.\n" << std::endl;

        display(first);
        
        std::cout << "\nEnter value (for exiting - 1): ";
        std::cin >> value;
    }

    Node *deletion_result{};
    std::cout << "\nFor Deletion enter position in btw 0 - " << number_nodes + 1 << " (for exiting - 1) : ";
    std::cin >> position;
    while (position != -1){

        deletion_result = delete_list(first, position);
        if(deletion_result){
            std::cout << "\nNode at position: " << position 
            << " with value: " << deleted_value << " deleted." << std::endl;
        }
        else
            std::cout << "\nPosition " << position << " out of bounds.\n" << std::endl;

        display(first);
        
        std::cout << "\nFor Deletion enter position in btw 0 - " << number_nodes + 1 << " (for exiting - 1) : ";
        std::cin >> position;
    }

}













