#include<iostream>

int fun(int n)
{
    if(n == 0)
        return 0;
    else
        return fun(n - 1) + n;
}

int main()
{
    std::cout << fun(5) << std::endl;
}













