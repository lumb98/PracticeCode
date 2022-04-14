#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;


void hello(){
    for(int i=0;i<1000;++i){
        cout<<"I am second thread."<<i<<endl;
        cout<<"I am second thread."<<i<<endl;
        usleep(10000);
    }
    
   
}


int main(){
    thread test(hello);
    //test.join();
    for(int i=0;i<1000;++i){
        cout<<"Hello Thread!!!!"<<i<<endl;
        cout<<"Hello Thread!!!!"<<i<<endl;
        usleep(10000);
    }
    return 0;
}
