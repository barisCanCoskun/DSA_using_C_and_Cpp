#include<iostream>

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
        :first{nullptr} {}
    LinkedList(int a[], int n);
    ~LinkedList();

    void display();
    int length();
    int insert(int index, int x);
    void insert(int x);  // to sorted LL
    int deleteIndex(int index);

};

LinkedList::LinkedList(int a[], int n){
    Node *temp{}, *last{};
    first = new Node;
    first->data = a[0];
    first->next = nullptr;
    last = first;

    for (size_t i{1}; i < n; i++)
    {
        temp = new Node{a[i], nullptr};
        last->next = temp;
        last = temp;
    }
}

LinkedList::~LinkedList()
{
    Node *temp{first};
    while (first){
        first = first->next;
        delete temp;
        temp = first;
    }
}

void LinkedList::display()
{
    Node *ptr{first};
    std::cout << std::endl;

    while (ptr){
        std::cout << ptr->data << " |-> ";
        ptr = ptr->next;
    }
    std::cout << "/0";
    std::cout << std::endl;
}

int LinkedList::length(){
    int count{};
    Node *ptr{first};
    while(ptr){
        ++count;
        ptr = ptr->next;
    }
    return count;
}

// to sorted LL
void LinkedList::insert(int value){
    Node *temp{new Node{value, nullptr}};

    if(!first){
        first = temp;
        return ;
    }

    Node *ptr{first};

    while(ptr && (value > ptr->data)){                 
        if(ptr->next && (value > ptr->next->data))
            ptr = ptr->next;
        else{
            temp->next = ptr->next;
            ptr->next = temp;
            return ;
        }
    }
}

int LinkedList::insert(int index, int x){
    if((index < 0) || (index > this->length())){       // bound check
        std::cout << "Out of bound." << std::endl;
        return -1;
    }
    
    Node *ptr{first};
    Node *temp{new Node{x, nullptr}};

    if(index == 0){
        temp->next = first;
        first = temp;
    }
    else{
        for (size_t i{1}; i < index; i++){
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return x;
}

int LinkedList::deleteIndex(int index){
    if(first){
        if((index < 1) || (index > this->length())){       // bound check
            std::cout << "Out of bound." << std::endl;
            return -1;
        }

        Node *ptr{first};
        int deleted_value{-1};

        if(index == 1){
            first = first->next;
            deleted_value = ptr->data;
            delete ptr;
        }
        else{
            Node *following{};  
            for (size_t i{1}; i < index; i++){
                following = ptr;
                ptr = ptr->next;
            }
            following->next = ptr->next;
            deleted_value = ptr->data;
            delete ptr;
        }

        return deleted_value;
    }
    std::cout << "There is no list." << std::endl;
    return -1;
}

int main()
{
    int A[] = {5, 12, 7, 1, 8};
    LinkedList l(A, sizeof(A)/sizeof(A[0]));

    l.display();

    int index{};
    std::cout << "Enter the index to be deleted: ";
    std::cin >> index;
    int value{l.deleteIndex(index)};
    if(value != -1){
        std::cout << "Index " << index << " with value " << value << " deleted." << std::endl;
    }
    l.display();

    std::cout << "Enter the index and value to be inserted: ";
    std::cin >> index >> value;
    value = l.insert(index, value);
    if(value != -1){
        std::cout << "Index " << index << " with value " << value << " inserted." << std::endl;
    }
    l.display();

    std::cout << "Enter just the value to be inserted: ";
    std::cin >> value;
    l.insert(value);
    std::cout << "Value " << value << " inserted." << std::endl;
    l.display();



}













