#include<iostream>
#include<cmath>

typedef struct _Term
{
    int coeff;
    int exp;
}Term;

typedef struct _Poly
{
    int num;
    Term *terms;
}Poly;

Poly *add(const Poly *poly1, const Poly *poly2)
{
    Poly *polySum = new Poly;
    polySum->num = poly1->num + poly2->num; 
    polySum->terms = new Term[polySum->num];

    std::cout << "\nResult of adding two polynomials: ";
    size_t k1{};
    size_t k2{};
    size_t kSum{};

    while ((k1 < poly1->num) && (k2 < poly2->num)){
        if (poly1->terms[k1].exp > poly2->terms[k2].exp){
            polySum->terms[kSum++] = poly1->terms[k1++];
        }
        else if (poly1->terms[k1].exp < poly2->terms[k2].exp){
            polySum->terms[kSum++] = poly2->terms[k2++];
        }
        else{
            polySum->terms[kSum] = poly1->terms[k1++];
            polySum->terms[kSum++].coeff += poly2->terms[k2++].coeff;
        }
    }
    
    while (k1 < poly1->num)
        polySum->terms[kSum++] = poly1->terms[k1++];
    
    while (k2 < poly2->num)
        polySum->terms[kSum++] = poly2->terms[k2++];

    polySum->num = kSum;

    return polySum;
}

void create(Poly *polynomial)
{
    std::cout << "Enter number of values: ";
    std::cin >> polynomial->num;

    polynomial->terms = new Term[polynomial->num];

    std::cout << "Enter terms of polynomial as coefficient and exponent respectively: ";
    for (size_t i = 0; i < polynomial->num; i++){
        std::cin >> polynomial->terms[i].coeff >> polynomial->terms[i].exp;
    }
}

void display(const Poly *poly)
{   
    std::cout << std::endl;
    for (size_t i{}; i < poly->num; i++)
    {
        if(poly->terms[i].exp > 1)
            std::cout << poly->terms[i].coeff << "x^" << poly->terms[i].exp << " + ";
        else if (poly->terms[i].exp == 1)
            std::cout << poly->terms[i].coeff << "x" << " + ";
        else if (poly->terms[i].exp == 0)
            std::cout << poly->terms[i].coeff;
    }
    std::cout << "\n" << std::endl;
}

int result_of_sum(const Poly *poly, int x)
{
    int sum{};
    for (size_t i{}; i < poly->num; i++){
        sum += poly->terms[i].coeff * pow(x, poly->terms[i].exp);
    }
    return sum;
}

int main()
{
    Poly polynomial1;
    std::cout << "For polynomial 1" << std::endl;
    create(&polynomial1);
    display(&polynomial1);

    Poly polynomial2;
    std::cout << "For polynomial 2" << std::endl;
    create(&polynomial2);
    display(&polynomial2);

    Poly *polynomialSum = add(&polynomial1, &polynomial2);
    display(polynomialSum);

    std::cout << "Result of polynomialSum for 1: " << result_of_sum(polynomialSum, 1) << std::endl;
    std::cout << "Result of polynomialSum for 2: " << result_of_sum(polynomialSum, 2) << std::endl;

    delete [] polynomialSum->terms;
    polynomialSum->terms = nullptr;
    delete polynomialSum;
    polynomialSum = nullptr;
    
    delete [] polynomial1.terms;
    polynomial1.terms = nullptr;
    delete [] polynomial2.terms;
    polynomial2.terms = nullptr;
}













