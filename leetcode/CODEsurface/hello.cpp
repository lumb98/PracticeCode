#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mu;
condition_variable cv;
int flag=0;


void printa(){
    unique_lock<mutex> lk(mu);
    int cnt=0;
    while(cnt<10){
        while(flag!=0) cv.wait(lk);
        cout<<"a"<<endl;
        flag=1;
        cv.notify_all();
        cnt++;
    }

}

void printb(){
    unique_lock<mutex> lk(mu);
    int cnt=0;
    while(cnt<10){
        while(flag!=1) cv.wait(lk);
        cout<<"b"<<endl;
        flag=2;
        cv.notify_all();
        cnt++;
    }
    
}

void printc(){
    unique_lock<mutex> lk(mu);
    int cnt=0;
    while(cnt<10){
        while(flag!=2) cv.wait(lk);
        cout<<"c"<<endl;
        flag=0;
        cv.notify_all();
        cnt++;
    }
    
}


int main(void){
    cout<<"Hello"<<endl;
    thread t1(printa);
    thread t2(printb);
    thread t3(printc);

    
    t1.join();
    t2.join();
    t3.join();
    return 0;
}