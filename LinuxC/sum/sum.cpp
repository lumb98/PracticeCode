#include "sum.h"
// int sum(int &num1,int &num2){
//     return num1+num2;
// }

int fact(int &input){
    static int output=0;
    output++;
    input+=100;
    return output;
}

int fact2(void){
    int output=100000;
    output+=1000;
}

int sum(initializer_list<int> lst){
    int sum=0;
    for(const auto num:lst ){
        sum+=num;
    }
    return sum;
}

arrT* test(int n){
    static arrT example;
    for(int i=0;i<10;++i){
        example[i]=n*i;
    }
    return &example;
}

int (*test2(int n))[10]{
    static arrT example;
    for(int i=0;i<10;++i){
        example[i]=n*i;
    }
    return &example;
}
