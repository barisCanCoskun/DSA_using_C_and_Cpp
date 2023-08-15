#include<iostream>

class Element
{
public:
    size_t i;
    size_t j;
    size_t x;
};

class Sparse
{
friend std::ostream &operator<<(std::ostream &os, const Sparse&sparse);   // for displaying sparse obj
friend Sparse operator+(const Sparse &lhs, const Sparse &rhs);            // for adding two matrices
private:
    size_t m;
    size_t n;
    size_t num;
    Element *element;
public:
    Sparse() = default;
    Sparse(size_t rowNum, size_t columnNum, size_t Number);
    ~Sparse();
};

// for adding two matrices
Sparse operator+(const Sparse &lhs, const Sparse &rhs)
{
    SparsePtr sparseSum = new Sparse;
    sparseSum->m = lhs.m;
    sparseSum->n = lhs.n;
    sparseSum->num = sparse1->num + sparse2->num;
    sparseSum->element = new Element[sparseSum->num];

    return 
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

// for displaying sparse obj
std::ostream &operator<<(std::ostream &os, const Sparse &sparse)
{
    size_t k{};

    for (size_t i{}; i < sparse.m; i++)
    {
        for (size_t j{}; j < sparse.n; j++)
        {
            if (sparse.element[k].i == i && sparse.element[k].j == j)
                os << sparse.element[k++].x << " ";
            else
                os << "0 ";
        }
        os << std::endl;
    }
    return os;
}

Sparse::Sparse(size_t rowNum, size_t columnNum, size_t Number)
    : m{rowNum}, n{columnNum}, num{Number}{
    elem = new Element[num];

    std::cout << "\nEnter non-zero elements as row, column, element respectively: ";
    for (size_t i = 0; i < num; i++){
        std::cin >> elem[i].i >> elem[i].j >> elem[i].x;
    }
}

Sparse::~Sparse(){
    delete [] elem;
    elem = nullptr; 
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












