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

typedef struct {
    int rpm;
    int16_t duty;
    int16_t current;
}VESC_receive_dataTypeDef;


void test1(){
    can_frame data_frame;
    __u8 input[8]={0x00,0x00,0x04,0x20,0x00,0x17,0x00,0x91};
    //for()
    
    __uint64_t data111=0;
    bytetodata(&data111,input,BIGENDIAN);
}

int main(){
    // test1();
    __u8 input[8]={0x00,0x00,0x04,0x20,0x00,0x17,0x00,0x91};
    __uint64_t data111=0;
    bytetodata(&data111,input,BIGENDIAN);
    //return 0;
    system("../canup.sh");
    int can0;
    __uint64_t datain=10000,temp=0;
    __uint64_t recv_data=0;
    
    cin>>datain;
    short duty,current;
    int rpm;
    datain=datain<<32;
    can_frame sendframe,data_frame;
    sendframe.can_id=0x80000074;
    data_frame.can_id=0x80000974;
    int error=can0=can_init("can0");
    VESC_receive_dataTypeDef data;
    if(error==-1)
        return 0;
    while(1){
        usleep(10000);

        //read(can0,&data_frame,sizeof(data_frame));

        //bytetodata(&recv_data,data_frame.data,BIGENDIAN);
        // if(data_frame.can_id==0x80000974){
        //     data.duty=data_frame.data[6]<<8;
        //     data.duty|=data_frame.data[7];
        //     data.current=data_frame.data[4]<<8;
        //     data.current|=data_frame.data[5];
        //     data.rpm=data_frame.data[0]<<24;
        //     data.rpm|=data_frame.data[1]<<16;
        //     data.rpm|=data_frame.data[2]<<8;
        //     data.rpm|=data_frame.data[3];
        // }

        int databyte=can_recv_8byte(can0,&recv_data,data_frame.can_id);
        








        // read(can0,&recvframe,sizeof(recvframe));
        // for(int i=0;i<8;++i)
        //     cout<<"data="<<hex<<(int)recvframe.data[i]<<endl;
        // bytetodata(&recv_data,recvframe.data,BIGENDIAN);
        // for(int i=0;i<8;++i)
        //     cout<<"data="<<hex<<(int)recvframe.data[i]<<endl;
        // cout<<hex<<recv_data<<endl;
        //13k+36%,gaojb
        //cout<<"recv: "<<databyte<<endl;
        // cout<<"hex_data= "<<hex<<recv_data<<endl;
        temp=recv_data>>32;
        memcpy(&rpm,&temp,4);
        // rpm=recv_data>>32;
        // current=(recv_data&0x000000ffff0000)>>16;
        // duty=(recv_data&0x000000000000ffff);

        cout<<"duty= "<<duty<<endl;
        cout<<"current= "<<current<<endl;
        cout<<"rpm= "<<rpm<<endl;
        can_send_8byte(can0,datain,sendframe.can_id);
    }
    cout<<"hello"<<endl;
}


int can_init(char *name){
    int status=-1;
    if(name=="can0"){

        status=system(CANDOWN(can0));
        if(status!=0){
            cerr<<"error: can't down can0 please check file permission ,if can't find divice may it already down!!! "<<endl;
        }
        status=system(CANCOMMAND(can0,500000));
        if(status!=0){
            cerr<<"error: can't set can0!!! please check file permission"<<endl;
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
int can_send_8byte(int socket,__uint64_t data,canid_t can_id ){
    can_frame send_frame;
    send_frame.can_id=can_id;
    send_frame.can_dlc=4;
    datatobyte(send_frame.data,data,BIGENDIAN);
    int nbytes;
    nbytes=write(socket,&send_frame,sizeof(send_frame));
    if(nbytes!=send_frame.can_dlc){
        cerr<<"just sent "<<nbytes<<" Bytes data ,please check"<<endl;
        return -1;
    }
    return 0;
}


int can_recv_8byte(int socket,__uint64_t *data,canid_t can_id /*,black_flag block=CAN_RECV_UNBLOCK*/){
    can_frame recv_frame;
    // if (block==CAN_RECV_BLOCK)
    // {
    //     int limit=0;
    //     int nbyte=read(socket,&recv_frame,sizeof(recv_frame));
    //     while(recv_frame.can_id!=can_id&&limit<50){
    //         nbyte=read(socket,&recv_frame,sizeof(recv_frame));
    //         ++limit;
    //     }
    //     return nbyte;
    // }else{
        int nbyte=read(socket,&recv_frame,sizeof(recv_frame));
        if(recv_frame.can_id!=can_id){
            return -1;// not needdata
        }
        bytetodata(data,recv_frame.data,BIGENDIAN);
        return nbyte;
    // }
    
    
}



