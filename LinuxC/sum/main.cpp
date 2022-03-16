#include "sum.h"
#include <iostream>
using namespace std;
int main(void)
{

    
    //typedef int arrT[10];
    //using arrT=int[10];
    arrT ccc{10,20,3,4,5,6,7,8,9,10};
    arrT* bbb;
    //bbb=test(5);
    //bbb=&ccc;
    unordered_set_practice();

    for(int i=0;i<10;++i){
        cout<<"bbb["<<i<<"]="<<(*test2(100))[i]<<endl;
    }
    //int test=0;
    //int* p=&test;
    //int a=0,b=0;
    initializer_list<int> aaa{1,1,1,1,1};
	cout << "HelloWorld" << endl;

    cout<<sum(aaa)<<endl;
    // cout<<"Befor The test is:"<<endl;
    // cin>>test;
    // cout<<"Plase input first number:"<<endl;
    // cin>>a;
    // cout<<"Plase input second number:"<<endl;
    // cin>>b;
    // cout<<"The sum is:"<<sum(a,b)<<endl;
    // int i=5;
    // int *const p=&i;
    // const int *cp=&i;
    // cout<<"The *cp is:"<<*cp<<endl;
    // cout<<"The *p is:"<<*cp<<endl;
    //*cp=50;
    // *p=10;
    // cout<<"After The *cp is:"<<*cp<<endl;
    // cout<<"After The *p is:"<<*cp<<endl;

    
    //cout<<"After The test is:"<<test<<endl;
	return 0;
}