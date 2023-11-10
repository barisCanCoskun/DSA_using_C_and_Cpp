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
friend std::istream &operator>>(std::istream &is, Sparse&sparse);         // for reading sparse obj
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
    if((lhs.m != rhs.m) || ((lhs.n != rhs.n))){
        std::cout << "\nThese matrices are not suitable for adding!\n" << std::endl;
        return Sparse{0, 0, 0};    
    }
    Sparse sparseSum{lhs.m, lhs.n, lhs.num + rhs.num};

    std::cout << "\nAdding two sparse matrices: ";
    size_t k1{};    // for sparse1's element number
    size_t k2{};    // for sparse2's element number
    size_t kSum{};

    while(k1 < lhs.num && k2 < rhs.num){    
        if(lhs.element[k1].i < rhs.element[k2].i){
            sparseSum.element[kSum++] = lhs.element[k1++];
        }
        else if(lhs.element[k1].i > rhs.element[k2].i){
            sparseSum.element[kSum++] = rhs.element[k2++];
        }
        else{
            if (lhs.element[k1].j < rhs.element[k2].j){
                sparseSum.element[kSum++] = lhs.element[k1++];
            }
            else if (lhs.element[k1].j > rhs.element[k2].j){
                sparseSum.element[kSum++] = rhs.element[k2++];
            }
            else{
                sparseSum.element[kSum] = rhs.element[k2++];
                sparseSum.element[kSum++].x += lhs.element[k1++].x;
            }
        }
    }

    while(k1 < lhs.num){
        sparseSum.element[kSum++] = lhs.element[k1++];
    }

    while(k2 < rhs.num){
        sparseSum.element[kSum++] = rhs.element[k2++];
    }

    sparseSum.num = kSum;

    return sparseSum;
}

// for reading sparse obj
std::istream &operator>>(std::istream &is, Sparse &sparse)
{
    std::cout << "\nEnter non-zero elements as row, column, element respectively: ";
    for (size_t i = 0; i < sparse.num; i++){
        is >> sparse.element[i].i >> sparse.element[i].j >> sparse.element[i].x;
    }

    return is;  
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
    element = new Element[num];
}

Sparse::~Sparse(){
    delete [] element;
    element = nullptr; 
}

int main()
{
    Sparse sparse_matrix1{5, 5, 5};
    Sparse sparse_matrix2{5, 4, 5};

    std::cin >> sparse_matrix1;
    std::cin >> sparse_matrix2;

    Sparse sparse_sum = sparse_matrix1 + sparse_matrix2;

    std::cout << "Matrix 1 :" << std::endl;
    std::cout << sparse_matrix1;
    std::cout << "Matrix 2 :" << std::endl;
    std::cout << sparse_matrix2;
    std::cout << "Matrix Sum :" << std::endl;
    std::cout << sparse_sum;
    
}












