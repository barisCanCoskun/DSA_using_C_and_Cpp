#include<iostream>

int main()
{
    char s[]{"welcome"};
    size_t i{};
    while (s[i++] != '\0');
    std::cout << "length: " << i - 1 << std::endl;

}















