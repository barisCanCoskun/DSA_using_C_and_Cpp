#include<iostream>

typedef struct _Element
{
    size_t i;
    size_t j;
    size_t x;
}Element;

typedef Element * ElementPtr;

typedef struct _Sparse
{
    size_t m;
    size_t n;
    size_t num;
    Element *element;
}Sparse;

typedef Sparse * SparsePtr;

void create(SparsePtr sparse)
{
    std::cout << "\nEnter row dimension: ";
    std::cin >> sparse->m;
    std::cout << "\nEnter column dimension: ";
    std::cin >> sparse->n;
    std::cout << "\nEnter number of non-zero: ";
    std::cin >> sparse->num;

    sparse->element = new Element[sparse->num];

    std::cout << "\nEnter non-zero elements as row, column, element respectively: ";
    for (size_t i = 0; i < sparse->num; i++){
        std::cin >> sparse->element[i].i >> sparse->element[i].j >> sparse->element[i].x;
    }
}

SparsePtr add(const SparsePtr sparse1, const SparsePtr sparse2)
{  
    SparsePtr sparseSum = new Sparse;
    sparseSum->m = sparse1->m;
    sparseSum->n = sparse1->n;
    sparseSum->num = sparse1->num + sparse2->num;
    sparseSum->element = new Element[sparseSum->num];

    std::cout << "\nAdding two sparse matrices: ";
    size_t k1{};    // for sparse1's element number
    size_t k2{};    // for sparse2's element number
    size_t kSum{};

    while(k1 < sparse1->num && k2 < sparse2->num){    
        if(sparse1->element[k1].i < sparse2->element[k2].i){
            // sparseSum->element[kSum].i = sparse1->element[k1].i;
            // sparseSum->element[kSum].j = sparse1->element[k1].j;
            // sparseSum->element[kSum].x = sparse1->element[k1].x;
            // ++kSum;
            // ++k1;
            sparseSum->element[kSum++] = sparse1->element[k1++];
        }
        else if(sparse1->element[k1].i > sparse2->element[k2].i){
            sparseSum->element[kSum++] = sparse2->element[k2++];
        }
        else{
            if (sparse1->element[k1].j < sparse2->element[k2].j){
                sparseSum->element[kSum++] = sparse1->element[k1++];
            }
            else if (sparse1->element[k1].j > sparse2->element[k2].j){
                sparseSum->element[kSum++] = sparse2->element[k2++];
            }
            else{
                sparseSum->element[kSum].i = sparse2->element[k2].i;
                sparseSum->element[kSum].j = sparse2->element[k2].j;
                sparseSum->element[kSum].x = sparse1->element[k1].x + sparse2->element[k2].x;
                ++kSum;
                ++k1;
                ++k2;
            }
        }
    }

    while(k1 < sparse1->num){
        sparseSum->element[kSum++] = sparse1->element[k1++];
    }

    while(k2 < sparse2->num){
        sparseSum->element[kSum++] = sparse2->element[k2++];
    }

    sparseSum->num = kSum;

    return sparseSum;
}

void display(const SparsePtr sparse)
{   
    size_t k{};

    for (size_t i{}; i < sparse->m; i++)
    {
        for (size_t j{}; j < sparse->n; j++)
        {
            if (sparse->element[k].i == i && sparse->element[k].j == j)
                std::cout << sparse->element[k++].x << " ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

// if((sparse1->m != sparse2->m) || ((sparse1->n != sparse2->n)))
//         return false;

int main()
{
    Sparse sparse_matrix1;
    create(&sparse_matrix1);
    display(&sparse_matrix1);

    Sparse sparse_matrix2;
    create(&sparse_matrix2);
    display(&sparse_matrix2);

    SparsePtr sparse_matrix_sumPtr;

    if((sparse_matrix1.m != sparse_matrix2.m) || ((sparse_matrix1.n != sparse_matrix2.n)))
        std::cout << "These matrices are not suitable for adding" << std::endl;
    else{
        sparse_matrix_sumPtr = add(&sparse_matrix1, &sparse_matrix2);
        display(sparse_matrix_sumPtr);
        delete [] sparse_matrix_sumPtr->element;
        sparse_matrix_sumPtr->element = nullptr;

        delete sparse_matrix_sumPtr;
        sparse_matrix_sumPtr = nullptr;
    }
    
    delete [] sparse_matrix1.element;
    sparse_matrix1.element = nullptr; 
    delete [] sparse_matrix2.element;
    sparse_matrix2.element = nullptr;
}













