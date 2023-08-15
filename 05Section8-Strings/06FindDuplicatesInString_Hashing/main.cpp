#include<iostream>
#include<string.h>
#define SMALL_LETTERS_NUMBERS 26
#define MIN_SMALL_LETTERS 97

void FindDuplicates(const char a[]);
int max(const char *arr);

int main()
{
    char str[] = "finding";

    FindDuplicates(str);

}

void FindDuplicates(const char a[])
{
    int *hashArr = new int [SMALL_LETTERS_NUMBERS]{0};
    // int hashArr[SMALL_LETTERS_NUMBERS]{0};
    // for (size_t i = 0; i < SMALL_LETTERS_NUMBERS; i++)
    //     hashArr[i] = 0;

    for (size_t i = 0; a[i] != '\0'; i++)
        ++hashArr[a[i] - MIN_SMALL_LETTERS];
    
    for (size_t i = 0; i < SMALL_LETTERS_NUMBERS; i++)
        if (hashArr[i] > 1)
            std::cout << "alphabet: " << (char)(MIN_SMALL_LETTERS + i) << " repeating" << std::endl;
    
    delete [] hashArr;
    hashArr = nullptr; 
}










