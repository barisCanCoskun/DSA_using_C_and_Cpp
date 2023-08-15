#include<iostream>
#include <ctype.h>

int main()
{
    char c;
    char s[]{"Welcome to  Adana!"};

    for (size_t i = 0; s[i] != '\0'; i++){
        if(!isalnum(s[i])) 
            std::cout << "Please enter valid letter!"<< std::endl;
    }

    std::cout << "Enter Name, surname, age:"<< std::endl;
    while ((c = getchar()) != -1){
        if(!isalnum(c))
            std::cout << "Please enter valid character!"<< std::endl;
    }
    
    
    std::cout << "letters: " << letters << " words: " << ++words << std::endl;

    // char s1[]{"GOOD BYE"};

    // for (size_t i = 0; s1[i] != '\0'; i++){
    //     if(s1[i] >= 97 && s1[i] <= 122)
    //         s1[i] -= 32;
    //     else if (s1[i] >= 'A' && s1[i] <= 'Z')
    //         s1[i] += 32;
    // }
    
    // std::cout << "changing case of string: " << s1 << std::endl;
    

}















