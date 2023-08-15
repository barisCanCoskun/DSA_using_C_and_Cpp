#include<iostream>
#define SMALL_LETTERS_NUMBERS 26
#define MIN_SMALL_LETTERS 97

void FindDuplicates(const char a[]);

int main()
{
    char str[] = "finding";

    FindDuplicates(str);

}

void FindDuplicates(const char a[])
{
    int Hash{};
    int x{};

    for (size_t i = 0; a[i] != '\0'; i++){
        x = 1;
        x <<= (a[i] - MIN_SMALL_LETTERS);
        if(x & Hash)
            std::cout << a[i] << " duplicated." << std::endl;
        else
            Hash |= x;
    }
    
}










