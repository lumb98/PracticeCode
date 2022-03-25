#include "cansocket.hpp"
#include <iostream>
using namespace std;
template <typename T>
data_byte* spilt_dataTobyte(const T &data,int target_len){
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