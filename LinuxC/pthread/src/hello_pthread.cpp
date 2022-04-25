#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
using namespace std;




mutex my_mutex,my_mutex2;
lock_guard<mutex> lockg;
void hello(){
    for(int i=0;i<1000;++i){
        // my_mutex.lock();
        lock_guard<mutex> lockg(my_mutex);
        cout<<"I am second thread."<<i<<endl;
        cout<<"I am second thread."<<i<<endl;
        // my_mutex.unlock();
        usleep(1000);
    }
    lock(my_mutex,my_mutex2);//可以同时锁定多个锁，如果一个没锁住，就会解锁其他，过一段时间再尝试
    //调用adopt_lock后 只有在析构时会调用unlock()，而构造时不会调用lock()，就可以使其自动unloc(),

    lock_guard<mutex> lockg2(my_mutex2,adopt_lock);

    unique_lock<mutex> ulock2(my_mutex,adopt_lock);

    unique_lock<mutex> ulock2(my_mutex,try_to_lock);

    unique_lock<mutex> ulock2(my_mutex,defer_lock);

    /*  第二参数
        adopt_lock,前提，已经加锁了，用这个参数后会自动解锁，当然要在一个代码块内。
        try_to_lock,前提，没有加锁，用这个参数可以尝试加锁，如果加锁失败也不会反复尝试，可以通过调用owns_lock( )方法，根据其返回值确定是否得到锁，如果得到返回true。
        defer_lock ，前提，没有加锁，用这个参数也不会加锁，目前理解的这样操作的原因是方便使用下面的那些成员函数，自己确定加锁的位置，
    */

    /*  unique_lock的成员函数
        lock();             将该unique_lock加锁。
        unlock();           将该unique_lock解锁
        try_lock();         尝试加锁，如果加锁成功返回true，如果失败返回false。
        release();          解绑当前mutex锁，并把该锁指针返回，解绑后，该mutex锁不会自动解锁，需要用新的指针调用unlock()手动解锁。
    */
    mutex mutex1;
    unique_lock<mutex> ulock11(mutex1);
    unique_lock<mutex> ulock22(move(ulock11));
    
    /*  unique_lock的所有权

        所有权的转移
        上面的代码就可以将mutex1的所有权从ulock11转移给ulock22。除此之外也可以用返回值的方式将它的所有权转移
        unique_lock<mutex> rtn_unique_lock(){
            unique_lock<mutex> tmpguard(mutex1);
            return tmpguard;
        }
        unique_lock<mutex> ulock33 = rtn_unique_lock();
        此时mutex1的所有权就转移到了ulock33了；
    
    
    */
}


int main(){
    thread test(hello);
    //test.join();
    for(int i=0;i<1000;++i){
        // my_mutex.lock();
        lock_guard<mutex> lockg(my_mutex);
        cout<<"Hello Thread!!!!"<<i<<endl;
        cout<<"Hello Thread!!!!"<<i<<endl;
        // my_mutex.unlock();
        usleep(1000);
    }
    return 0;
}
