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
    Node *temp{}, *last{};
    Node *firstNode = new Node;
    ++number_nodes;
    firstNode->data = a[0];
    firstNode->next = nullptr;
    last = firstNode;

    for (size_t i{1}; i < n; i++)
    {
        temp = new Node{a[i], nullptr};
        ++number_nodes;
        last->next = temp;
        last = temp;
    }
    return firstNode;
}

void display(const Node *ptr)
{
    std::cout << std::endl;

    while (ptr){
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

void concatenate(Node *ptr, Node *q){
    while (ptr->next){
        ptr = ptr->next;
    }
    ptr->next = q;    
}

Node *merge_to_new_list(Node *ptr, Node *q){                 // first try
    Node *last, *temp;
    Node *merge_first{};
    if(ptr->data <= q->data){
        merge_first = new Node{ptr->data, nullptr};
        ptr = ptr->next;
    }
    else{
        merge_first = new Node{q->data, nullptr};
        q = q->next;
    }
    last = merge_first;

    while (ptr && q){
        if(ptr->data <= q->data){
            temp = new Node{ptr->data, nullptr};
            ptr = ptr->next;
        }
        else{
            temp = new Node{q->data, nullptr};
            q = q->next;
        }
        last->next = temp;
        last = temp;
    }

    while (ptr){
        temp = new Node{ptr->data, nullptr};
        last->next = temp;
        last = temp;
        ptr = ptr->next;
    }
    
    while (q){
        temp = new Node{q->data, nullptr};
        last->next = temp;
        last = temp;
        q = q->next;
    }
    
    return merge_first;
}

Node *merge_to_first_list(Node *ptr, Node *q){                 // second try
    Node *last{}, *temp{};
    Node *merge_first{};

    if(ptr->data <= q->data){
        merge_first = ptr;
        ptr = ptr->next;
    }
    else{
        merge_first = new Node{q->data, ptr};
        q = q->next;
    }
    last = merge_first;

    while (ptr && q){
        if(ptr->data <= q->data){
            last = ptr;
            ptr = ptr->next;
        }
        else{
            temp = new Node{q->data, ptr};
            q = q->next;
            last->next = temp;
            last = temp;
        }
    }
    
    while (q){
        temp = new Node{q->data, nullptr};
        last->next = temp;
        last = temp;
        q = q->next;
    }
    
    return merge_first;
}

// O(m + n)
Node *merge(Node *ptr, Node *q){      // third try - best one : it doesn t require extra space
    Node *merge_first{}, *last{};

    if(ptr->data <= q->data){
        merge_first = ptr;
        ptr = ptr->next;
    }
    else{
        merge_first = q;
        q = q->next;
    }
    last = merge_first;
    last->next = nullptr;

    while (ptr && q){
        if(ptr->data <= q->data){
            last->next = ptr;
            last = ptr;
            ptr = ptr->next;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
        }
        last->next = nullptr;
    }

    if(ptr)
        last->next = ptr;
    else
        last->next = q;
    
    return merge_first;
}
//O(m + n)

int main()
{
    int A[]{3, 4, 5, 12, 13};

    first = create(A, sizeof(A)/sizeof(A[0]));
    std::cout << "First:" << first;
    display(first);

    int B[]{1, 2, 7, 10, 15, 18, 22};

    Node *second = create(B, sizeof(B)/sizeof(B[0]));
    std::cout << "Second:"  << second;
    display(second);

    // concatenate(first, second);
    // display(first);

    // Node *merge_list = merge_to_new_list(first, second);
    // std::cout << merge_list;
    // display(merge_list);

    // Node *merge_list = merge_to_first_list(first, second);
    // std::cout << merge_list;
    // display(merge_list);

    Node *merge_list = merge(first, second);
    std::cout << "Merge List:"  << merge_list;
    display(merge_list);

}













