#include<iostream>

int fun(int n)
{
    if(n > 100)
        return n - 10;
    else
        return fun(fun(n + 11));
}

int main()
{
    std::cout << fun(95) << std::endl;
}













