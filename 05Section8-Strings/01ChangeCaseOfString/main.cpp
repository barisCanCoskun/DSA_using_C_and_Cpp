#include<iostream>

int main()
{
    char s[]{"welcome"};

    for (size_t i = 0; s[i] != '\0'; i++){
        if(s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    
    std::cout << "changing case of string: " << s << std::endl;

    char s1[]{"GOOD BYE"};

    for (size_t i = 0; s1[i] != '\0'; i++){
        if(s1[i] >= 97 && s1[i] <= 122)
            s1[i] -= 32;
        else if (s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] += 32;
    }
    
    std::cout << "changing case of string: " << s1 << std::endl;
    

}















