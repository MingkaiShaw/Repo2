#include<iostream>

int main()
{
    int *a ;
    int b = 20;
    a = new int;
    *a = b;
    int *x=a;

    std::cout << *x;
    delete x;
    x = NULL;
   
    
    return 0;

}