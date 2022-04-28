#include "ybw_can.h"

#define CANCOMMAND(can_num,bitrate) "/sbin/ip link set "#can_num" type can bitrate "#bitrate //将CAN0波特率设置为125000 bps
#define CANUP(can_num) "ifconfig "#can_num" up"//打开CAN0
#define CANDOWN(can_num) "ifconfig "#can_num" down"//关闭CAN0


using namespace std;
/*
    NAME is the can net name in IFCONFIG
*/
// string returnsrting(string s){
//     return s;
// }


int main(){
    int can0;
    int64_t data=10000;
    data=data<<32;
    can_frame sendframe;
    sendframe.can_id=0x80000074;
    can0=can_init("can0");
    while(1){
        usleep(10000);
        can_send_8byte(can0,data,sendframe.can_id);
    }
    cout<<"hello"<<endl;
}


int can_init(char *name){
    int status=-1;
    if(name=="can0"){

        status=system(CANDOWN(can0));
        if(status!=0){
            cerr<<"error: can't down can0!!! please check file permission"<<endl;
            return -1;
        }
        status=system(CANCOMMAND(can0,500000));
        if(status!=0){
            cerr<<"error: can't set can0!!!"<<endl;
            return -1;
        }
        status=system(CANUP(can0));
        if(status!=0){
            cerr<<"error: can't up can0!!!"<<endl;
            return -1;
        }
    }else if(name=="can1"){
        status=system(CANDOWN(can1));
        if(status!=0){
            cerr<<"error: can't down can1!!! please check file permission"<<endl;
            return -1;
        }
        status=system(CANCOMMAND(can1,500000));
        if(status!=0){
            cerr<<"error: can't set can1!!!"<<endl;
            return -1;
        }
        status=system(CANUP(can1));
        if(status!=0){
            cerr<<"error: can't up can1!!!"<<endl;
            return -1;
        }
    }else {
        cerr<<"error input parameter is illegal"<<endl;
        return -1;
    }
    int errorinfo;
    
    int s=socket(PF_CAN,SOCK_RAW,CAN_RAW);
    struct ifreq ifr;
    strcpy(ifr.ifr_name,name);
    errorinfo=ioctl(s,SIOCGIFINDEX,&ifr);
    if(errorinfo==-1){
        cerr<<"error can't ioctl!!!"<<endl;
        return -1;
    }
    struct sockaddr_can can_addr;
    can_addr.can_family=AF_CAN;
    can_addr.can_ifindex=ifr.ifr_ifindex;
    errorinfo=bind(s,(struct sockaddr *)&can_addr,sizeof(can_addr));
    if(errorinfo==-1){
        cerr<<"error can't bind!!!"<<endl;
        return -1;
    }
    return s;

}
//需求 给定 canid 和数据，将其发送。
int can_send_8byte(int socket,int64_t data,canid_t can_id ){
    can_frame send_frame;
    //__u8 temp[8]={};
    send_frame.can_id=can_id;
    send_frame.can_dlc=4;
    datatobyte(send_frame.data,data,BIGENDIAN);
    // for(int i=0;i<4;++i){
    //     send_frame.data[i]=send_frame.data[i+4];
    //     //send_frame.data[i+4]=0;
    // }
    //cout<<"here"<<endl;
    for(int i=0;i<8;++i)
        cout<<(int)send_frame.data[i]<<endl;
    int nbytes;
    nbytes=write(socket,&send_frame,sizeof(send_frame));
    if(nbytes!=send_frame.can_dlc){
        cerr<<"just sent "<<nbytes<<" Bytes data ,please check"<<endl;
        return -1;
    }
    return 0;
}


int can_recv_8byte(int socket,int64_t *data,canid_t can_id ,black_flag block=CAN_RECV_UNBLOCK){
    can_frame recv_frame;
    if (block==CAN_RECV_BLOCK)
    {
        int limit=0;
        int nbyte=read(socket,&recv_frame,sizeof(recv_frame));
        while(recv_frame.can_id!=can_id&&limit<50){
            nbyte=read(socket,&recv_frame,sizeof(recv_frame));
            ++limit;
        }
        return nbyte;
    }
    
    int nbyte=read(socket,&recv_frame,sizeof(recv_frame));
    if(recv_frame.can_id!=can_id){
        return -1;// not needdata
    }
    bytetodata(data,(__u8*)recv_frame.data,BIGENDIAN);
    return nbyte;;
}



