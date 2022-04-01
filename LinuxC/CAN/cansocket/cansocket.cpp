#include "cansocket.hpp"


using namespace std;


int VESC_RPM_can_send(int __fd,canid_t motor_ID,int RPM){
    data_byte *byte_RPM;
    byte_RPM=spilt_dataTobyte(RPM,4);
    can_frame RPM_frame;
    RPM_frame.can_id=0x80000300+motor_ID;
    RPM_frame.can_dlc=4;
    for(int i=0;i<4;++i){
        RPM_frame.data[i]=(*byte_RPM)[i];
    }
    int nbytes;
    nbytes = write(__fd, &RPM_frame, sizeof(RPM_frame));
    if(nbytes != sizeof(RPM_frame))
    {
        cerr<<"Send Error RPM_frame\n!"<<endl;
        return -1;
    }
    return 0;
}

int VESC_duty_can_send(int __fd,canid_t motor_ID,int duty){
    data_byte *byte_duty;
    byte_duty=spilt_dataTobyte(duty,4);
    can_frame duty_frame;
    duty_frame.can_id=0x80000000+motor_ID;
    duty_frame.can_dlc=4;
    for(int i=0;i<4;++i){
        duty_frame.data[i]=(*byte_duty)[i];
    }
    int nbytes;
    nbytes = write(__fd, &duty_frame, sizeof(duty_frame));
    if(nbytes != sizeof(duty_frame))
    {
        cerr<<"Send Error duty_frame\n!"<<endl;
        return -1;
    }
    return 0;
}

#define VESC_reveive_data_DutyCurrentRpm 0x80000900

int VES_can_receive(int __fd,canid_t motor_ID){
    VESC_receive_dataTypeDef data;
    can_frame data_frame;
    int nbytes;
    nbytes = read(__fd, &data_frame, sizeof(data_frame));
    //cout<<nbytes<<endl;
    if(nbytes!=16)   //if the data is not 16 bytes, that is not we need, 
        return -1;
    //cout<<hex<<data_frame.can_id<<endl;
    if(data_frame.can_id!=VESC_reveive_data_DutyCurrentRpm+motor_ID){
        return -1;
    }else{
        data.duty=data_frame.data[6]<<8;
        data.duty|=data_frame.data[7];
        data.current=data_frame.data[4]<<8;
        data.current|=data_frame.data[5];
        data.rpm=data_frame.data[0]<<24;
        data.rpm|=data_frame.data[1]<<16;
        data.rpm|=data_frame.data[2]<<8;
        data.rpm|=data_frame.data[3];
        cout<<"motor:"<<motor_ID<<endl;
        cout<<"RPM="<<data.rpm<<"r/min"<<endl;
        cout<<"duty="<<(float)data.duty/1000<<"%"<<endl;
        cout<<"current="<<(float)data.current/10<<"A"<<endl;
    }
    


    return 0;
}

