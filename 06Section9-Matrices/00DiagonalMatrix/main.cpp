#include<iostream>

typedef struct _Matrix
{
    int A[10];
    int n;
}Matrix;

void Set(Matrix *m, int i, int j, int x);
int Get(const Matrix *m, int i, int j);

int main()
{
    Matrix matrix;
    for (auto &i : matrix.A)
        i = 0;
    matrix.n = 4;

    Set(&matrix, 1, 1, 7);
    Set(&matrix, 2, 2, 5);
    Set(&matrix, 3, 3, 9);
    Set(&matrix, 4, 4, 21);
    std::cout << "matrix[2, 2] = " << Get(&matrix, 2, 2) << std::endl;

    for (const auto &i : matrix.A)
        std::cout << i << ", ";
    

}

void Display(const Matrix *m, int i, int j)
{
    
}

void Set(Matrix *m, int i, int j, int x)
{
    if(i == j)
        m->A[i - 1] = x;
}

int Get(const Matrix *m, int i, int j)
{
    if(i == j)
        return m->A[i - 1];
    else
        return 0;
}













