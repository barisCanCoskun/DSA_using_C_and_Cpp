#include<iostream>
#include<string.h>
#define SMALL_LETTERS_NUMBERS 26
#define MIN_SMALL_LETTERS 97

bool CheckAnagram(const char str1[], const char str2[]);

int main()
{
    char string1[] = "decimal";
    char string2[] = "medical";

    if(CheckAnagram(string1, string2))
        std::cout << "The strings are anagram" << std::endl;
    else
        std::cout << "The strings are NOT anagram" << std::endl;
    
    char string3[] = "verbose";
    char string4[] = "observe";

    if(CheckAnagram(string3, string4))
        std::cout << "The strings: \"" << string3 << "\" and \"" << string4 << "\" are anagram" << std::endl;
    else
        std::cout << "The strings are NOT anagram" << std::endl;
    
    char string5[] = "joe";
    char string6[] = "observe";

    if(CheckAnagram(string5, string6))
        std::cout << "The strings: \"" << string5 << "\" and \"" << string6 << "\" are anagram" << std::endl;
    else
        std::cout << "The strings: \"" << string5 << "\" and \"" << string6 << "\" are NOT anagram" << std::endl;

}

bool CheckAnagram(const char str1[], const char str2[])
{
    int *hashArr = new int [SMALL_LETTERS_NUMBERS]{0};
    // int hashArr[SMALL_LETTERS_NUMBERS];
    // for (size_t i = 0; i < SMALL_LETTERS_NUMBERS; i++)
    //     hashArr[i] = 0;

    for (size_t i = 0; str1[i] != '\0'; i++)
        ++hashArr[str1[i] - MIN_SMALL_LETTERS];
    
    for (size_t i = 0; str2[i] != '\0'; i++)
        if (!hashArr[str2[i] - MIN_SMALL_LETTERS]){
            delete [] hashArr;
            hashArr = nullptr; 
            return false;
        }
    
    delete [] hashArr;
    hashArr = nullptr; 
    return true;
}










