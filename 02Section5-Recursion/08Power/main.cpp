#include<iostream>

int pow(int m, int n){
    if(n == 1)
        return m;
    else
        return pow(m, n-1) * m;
}

int powLessTime(int m, int n){
    int result = 1;

    while(n != 0){
        if(n & 1)
            result *= m;
        
        n >>= 1;
        m *= m;
    }

    return result;
}

int main()
{
    std::cout << pow(2, 5) << std::endl;
    std::cout << powLessTime(2, 5) << std::endl;
}













