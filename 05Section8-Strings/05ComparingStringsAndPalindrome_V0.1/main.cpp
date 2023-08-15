#include<iostream>
#include<string.h>

bool CompareStrings(char a[], char b[]);
bool Palindrome(char a[]);
void reverse(const char *const sPtr, char *s1);

int main()
{
    char A[] = "Painter";
    char B[] = "Painting";

    if (CompareStrings(A, B)){
        std::cout << "Strings are equal" << std::endl;
    }
    else
        std::cout << "Strings are not equal" << std::endl;
    
    char C[] = "Painter";
    char D[] = "Painter";

    if (CompareStrings(C, D)){
        std::cout << "Strings are equal" << std::endl;
    }
    else
        std::cout << "Strings are not equal" << std::endl;    

    std::cout << std::endl;   

    char E[] = "viva aviv";
    if(Palindrome(E))
        std::cout << "String is palindrome" << std::endl;
    else
        std::cout << "String is not palindrome" << std::endl;
}

bool CompareStrings(char a[], char b[])
{
    size_t size_a{};
    size_t size_b{};
    size_t i = 0;

    for (i = 0; a[i] != '\0'; i++);
    size_a = i;

    for (i = 0; b[i] != '\0'; i++);
    size_b = i;

    if(size_a == size_b)
        for (size_t i = 0; i < size_a; i++)
        {
            if (a[i] != b[i]){
                return 0;
            }
        }
    else{
        std::cout << "Strings sizes not equal" << std::endl;
        return 0;
    }
    return 1;
}

bool Palindrome(char a[])
{
    size_t size_b{};
    size_t i = 0;

    for (i = 0; a[i] != '\0'; i++);
    size_b = i;

    char *b = new char[size_b + 1];

    reverse(a, b);

    // for (size_t j = 0; j < size_b; j++)
    // {
    //     b[j] = a[--i];
    // }
    b[size_b] = '\0';

    if(!strcmp(a, b))
        return 1;
    else
        return 0;

}

void reverse(const char *const sPtr, char *s1)
{
    static size_t i{};
    if(sPtr[0] == '\0')
        return;
    else{
        reverse(&sPtr[1], s1);
        s1[i++] = sPtr[0]; 
    }
}










