#include<iostream>

void print(const int p[][4], size_t size1, size_t size2){
    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            std::cout << p[i][j] << " " ;
        }
    }
    std::cout << std::endl;
}

int main()
{
    int A[3][4]{{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};  // 1st method

    A[1][2] = 15;

    std::cout << A[1][2] << std::endl;
    print(A, 3, 4);

    int *B[3];              // 2nd method
    B[0] = new int[4];      
    B[1] = new int[4];
    B[2] = new int[4];

    B[1][2] = 15;
    // print(B, 3, 4);

    int **C;                // 3rd method : entire structure is in heap 
    C = new int *[3];

    C[0] = new int [4];
    C[1] = new int [4];
    C[2] = new int [4];
    
    C[1][2] = 15;

    int **D;
    D = new int*;
    *D = new int;

    int d = 5;
    int *dptr = &d;

    *D = dptr;
    std::cout << **D << std::endl;

}













