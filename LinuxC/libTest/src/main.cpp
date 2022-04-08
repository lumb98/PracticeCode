#include <iostream>
#include "sum.h"

using namespace std;

int main(void){
    int a,b;
    cout<<"please input First number:"<<endl;
    cin>>a;
    cout<<"please input Secand number:"<<endl;
    cin>>b;
    cout<<sum_int(a,b)<<endl;
    return 0;
}