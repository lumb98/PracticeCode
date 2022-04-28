#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <future>
#include <atomic>

using namespace std;


// int atest=0;

int mythread(int a){
    cout<<"mythread() start"<<"threadID = "<<this_thread::get_id()<<endl;
    chrono::milliseconds dura(5000);
    this_thread::sleep_for(dura);
    cout<<"mythread() end"<<"threadID = "<<this_thread::get_id()<<endl;
    return a;
}

atomic<int> atest(0);
//atomic<int> atest2(atest);//错误，不能对原子对象拷贝
atomic<int> atest2(atest.load());//正确可以用load()方法拷贝原子对象
//atest.store(12);atest=12;//给atest原子对象赋值，前面的一定是原子操作，后面的不是，这里不知道为什么不对。
int atomictest1(void){
    for(int i=0;i<1000000;++i){
        atest++;
        atest+=1;
        atest=atest+1;//不是原子操作
        cout<<"11It is "<<atest<<endl;
    }
        
}

int atomictest2(void){
    for(int i=0;i<1000000;++i){
        atest++;
        cout<<"22It is "<<atest<<endl;
    }
}

int atomictest3(void){
    for(int i=0;i<1000000;++i){
        atest++;
        

        cout<<"33It is "<<atest<<endl;
    }
}


int main(){
    cout<<"main"<<"threadID = "<<this_thread::get_id()<<endl;
    // future<int> result = async(mythread,100);
    // cout<<"continue..."<<endl;
    // future_status status=result.wait_for(chrono::seconds(6));
    // if(status==future_status::timeout){
    //     cout<<"超时线程没有执行完毕"<<endl;
    // }else if(status==future_status::ready){
    //     cout<<"线程执行完毕,返回"<<endl;
    //     cout<<result.get()<<endl;
    // }else if(status==future_status::deferred){
    //     cout<<"线程 deferred"<<endl;
    //     cout<<result.get()<<endl;
    // }
    
    thread t1(atomictest1);
    thread t2(atomictest2);
    thread t3(atomictest3);
    t1.join();
    t2.join();
    t3.join();

    cout<<"atest = "<<atest<<endl;

    cout<<"mian End"<<endl;
    return 0;
}