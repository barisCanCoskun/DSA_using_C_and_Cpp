#include<iostream>

typedef struct _Element
{
    size_t i;
    size_t j;
    size_t x;
}Element;

typedef struct _Sparse
{
    size_t m;
    size_t n;
    size_t num;
    Element *element;
}Sparse;

void create(Sparse *sparse)
{
    std::cout << "\nEnter row dimension: ";
    std::cin >> sparse->m;
    std::cout << "\nEnter column dimension: ";
    std::cin >> sparse->n;
    std::cout << "\nEnter number of non-zero: ";
    std::cin >> sparse->num;

    // sparse->element = (Element *)malloc((sparse->num) * sizeof(Element));
    sparse->element = new Element[sparse->num];

    std::cout << "\nEnter non-zero elements as row, column, element respectively: ";
    for (size_t i = 0; i < sparse->num; i++){

        std::cin >> sparse->element[i].i >> sparse->element[i].j >> sparse->element[i].x;

        // std::cin >> sparse->element[i].i;
        // std::cout << ", ";
        // std::cin >> sparse->element[i].j;
        // std::cout << ": ";
        // std::cin >> sparse->element[i].x;
        }

}

void display(const Sparse *sparse)
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

int main()
{
    Sparse sparse_matrix;
    create(&sparse_matrix);

    display(&sparse_matrix);
    
    delete [] sparse_matrix.element;
    sparse_matrix.element = nullptr; 
}













