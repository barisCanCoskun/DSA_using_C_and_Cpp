#include<stdio.h>


struct basic_info {
  char first_name[50];
  int age;
};

struct address {
  char city[20];
};
struct Person {
  struct basic_info info;
  struct address adrs;
  union {
    int salary;
  };
};

int Age_More_than_k(struct Person per[], int k, int n) {
  // Your Code Here
  int number = 0;
  for (int i = 0; i < n; i++) {
      if(per[i].info.age > k)
        ++number;
  }
  
  //the number of people older than k
  return number;
}

int main()
{



}













