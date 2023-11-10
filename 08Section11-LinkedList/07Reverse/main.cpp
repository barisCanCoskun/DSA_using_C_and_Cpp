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
Node *q_rec{};
size_t count{};

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
    std::cout << std::endl;

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
            ++number_nodes;
            return temp;
        }
    }
    temp->next = first;
    first = temp;
    ++number_nodes;
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

bool check_sorted(Node *ptr){
    if(ptr){
        while(ptr->next){
            if(ptr->data > ptr->next->data){
                std::cout << "This list NOT sorted." << std::endl;
                return true;
            }
        ptr = ptr->next;
        }
        std::cout << "This list sorted." << std::endl;
        return true;
    }
    std::cout << "There is no list." << std::endl;
    return false;
}

bool remove_duplicates_first_try(Node *ptr){          // first try, on my own
    if(ptr){
        int previous_number_nodes = number_nodes;
        Node *temp{};
        while (ptr->next){
            while(ptr->next && (ptr->data == ptr->next->data)){
                temp = ptr->next;
                ptr->next = temp->next;
                std::cout << "Node with value: " << temp->data << " removed from list." << std::endl;
                delete temp;
                --number_nodes;
            }
            if(ptr->next)
                ptr = ptr->next;
        }
        if(previous_number_nodes == number_nodes)
            std::cout << "There is no duplicate in list." << std::endl;
        else
            std::cout << previous_number_nodes - number_nodes << " nodes removed from list. " << std::endl;
        
        return true;
    }
    
    std::cout << "There is no list." << std::endl;
    return false;
}

bool remove_duplicates(Node *ptr){
    if(ptr){
        int previous_number_nodes = number_nodes;
        Node *temp{ptr->next};
        while (temp){
            if(ptr->data == temp->data){
                ptr->next = temp->next;
                std::cout << "Node with value: " << temp->data << " removed from list." << std::endl;
                delete temp;
                temp = ptr->next;
                --number_nodes;
            }
            else{
                ptr = temp;
                temp = temp->next;
            }
        }
        if(previous_number_nodes == number_nodes)
            std::cout << "There is no duplicate in list." << std::endl;
        else
            std::cout << previous_number_nodes - number_nodes << " nodes removed from list. " << std::endl;
        
        return true;
    }
    
    std::cout << "There is no list." << std::endl;
    return false;
}

void reverse_links(Node *ptr){       // pointer sliding:  r,  q,  ptr
    Node *q{}, *r{};
    while (ptr){
        r = q;
        q = ptr;
        ptr = ptr->next;
        q->next = r;
    }
    first = q;
}

void reverse_links_recursive(Node *q, Node *ptr){       // pointer sliding:  q,  ptr
    if (ptr){
        reverse_links_recursive(ptr, ptr->next);
        ptr->next = q;
    }
    else
        first = q;
}

void reverse_elements(Node *ptr){
    int a[number_nodes];
    
    for (size_t i = 0; ptr; i++){
        a[i] = ptr->data;
        ptr = ptr->next;
    }

    ptr = first;
    for(size_t i{number_nodes - 1}; ptr; --i){
        ptr->data = a[i];
        ptr = ptr->next;
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void reverse_elements_recursive(Node *ptr){
    if(ptr){
        reverse_elements_recursive(ptr->next);
        if(count++ < number_nodes / 2){
            swap(ptr->data, q_rec->data);
            q_rec = q_rec->next;
        }
    }
}

int main()
{
    int A[]{1, 4, 5, 13, 12, 14, 17, 20, 23};

    first = create(A, sizeof(A)/sizeof(A[0]));

    std::cout << first << std::endl;
    display(first);

    reverse_links(first);
    
    display(first);

    reverse_elements(first);
    
    display(first);

    q_rec = first;
    reverse_elements_recursive(first);
    
    display(first);
    
    reverse_links_recursive(nullptr, first);
    
    display(first);

}













