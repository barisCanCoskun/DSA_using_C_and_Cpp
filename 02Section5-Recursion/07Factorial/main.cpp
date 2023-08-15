#include<iostream>

int fact(int n){
    if(n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int fact1(int n){
    int mul = 1;
    while(n != 0){
        mul *= n;
        --n;
    }
    return mul;
}

int main()
{
    std::cout << fact(5) << std::endl;
    std::cout << fact1(5) << std::endl;
}













