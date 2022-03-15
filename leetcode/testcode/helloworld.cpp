#include <stdio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void reset(int *p){
    *p=0;
    cout<<"p="<<p<<endl;
    cout<<"*p="<<*p<<endl;

    p=0;
    cout<<"p="<<p<<endl;
    cout<<"*p="<<*p<<endl;
    
}

int main(int argc, char *args[])
{
    int i, j,test=100;
    printf("hello world!\n");
    printf("argc:%d\nargv:\n", argc);
    reset(&test);
    for (i = 0; i < argc; i++)
    {
        printf("%d:%s\n", i, args[i]);
    }
    getchar();

    return 0;
}