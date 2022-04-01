#ifndef __CANSOCKET_HPP__
#define __CANSOCKET_HPP__
#include <linux/can.h>
#include <linux/can/raw.h>
#include <unistd.h>
#include <iostream>

typedef struct {
    int rpm;
    int16_t duty;
    int16_t current;
}VESC_receive_dataTypeDef;
using namespace std;
typedef char data_byte[16];
// template <typename T>
// data_byte* spilt_dataTobyte(const T &data,int target_len);

// template <typename T2>
// void merge_byteTodata(data_byte* data,T2 &res);

template <typename T>
data_byte* spilt_dataTobyte(const T &data,int target_len){
    T temp=data;
    static data_byte res{};
    for(int i=0;i<target_len;++i){
        res[target_len-i-1]=(temp>>8*i)&0xff;
    }

    return &res;
}

template <typename T2>
void merge_byteTodata(data_byte* data,T2 &res,int len){
   res=0x0;
   for(int i=len-1;i>=0;--i){
       //cout<<i<<endl;
       res|=(*data)[i]<<8*i;
   }

}

int VESC_RPM_can_send(int __fd,canid_t motor_ID,int RPM);
int VESC_duty_can_send(int __fd,canid_t motor_ID,int duty);
int VES_can_receive(int __fd,canid_t motor_ID);

#endif
