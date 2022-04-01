#include "sum.h"
// int sum(int &num1,int &num2){
//     return num1+num2;
// }

template <typename T>
data_byte* (const T &data,int target_len){
    T temp=data;
    int type_size=sizeof(temp);
    static data_byte res{};
    for(int i=0;i<target_len;++i){
        //cout<<(int)res[i]<<endl;
        res[i]=(temp>>8*i)&0xff;
        //cout<<"res"<<(int)res[i]<<endl;
    }

    return &res;
}

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

void unordered_set_practice(void){
    //unordered_set<int> uset;
    unordered_set<int> uset{10,2,3,4,5,6,8,7};//值得注意的是当我们用下面的循环（范围for循环）打印时是与当前顺序相反的。
    unordered_set<int> uset2(uset);

    for(int print:uset){
        cout<<print<<endl;
    }
    for(int print:uset2){
        cout<<print<<endl;
    }
}
