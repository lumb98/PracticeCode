#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sys/time.h>
#include  "cansocket.hpp"
// #include  "cansocket.cpp"
#define command "/sbin/ip link set can0 type can bitrate 500000"//将CAN0波特率设置为125000 bps
#define up "ifconfig can0 up"//打开CAN0
#define down "ifconfig can0 down"//关闭CAN0
using namespace std;




int main()
{   
    // while(1){
    //     int test=0;
    //     float ftest=0;
    //     cin>>test;
    //     data_byte *data;
    //     data=spilt_dataTobyte(test,8);
    //     for(int i=0;i<4;++i){
    //         //cout<<"here22"<<endl;
    //         //cout<<(int)(*data)[i]<<endl;
    //     }
    //     int output11=0;
    //     // output11=(*data)[3]<<24;
    //     // output11|=(*data)[2]<<16;
    //     // output11|=(*data)[1]<<8;
    //     // output11|=(*data)[0];
    //     merge_byteTodata(data,output11);
    //     cout<<"output is :"<<output11<<endl;
    // }
    // return 0;
    int status(999);

    status=system(down);
    cout<<status<<endl;
    status=system(command);
    cout<<status<<endl;
    status=system(up);//上面三行关闭CAN设备，设置波特率后，重新打开CAN设备
    cout<<status<<endl;
    
    int s, nbytes;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame[2] = {{0}};
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);//创建套接字
    strcpy(ifr.ifr_name, "can0" );
    ioctl(s, SIOCGIFINDEX, &ifr); //指定 can0 设备
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(s, (struct sockaddr *)&addr, sizeof(addr));//将套接字与 can0 绑定
    //setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);//设置过滤规则，取消当前注释为禁用过滤规则，即不接收所有报文，不设置此项（即如当前代码被注释）为接收所有ID的报文。
    // frame[0].can_id = 0x80000374;
    // frame[0].can_dlc = 8;
    // frame[0].data[0] = 0x00;
    // frame[0].data[1] = 0x00;
    // frame[0].data[2] = 0x00;
    // frame[0].data[3] = 0xFF;
    // frame[0].data[4] = 0x00;
    // frame[0].data[5] = 0x00;
    // frame[0].data[6] = 0x00;
    // frame[0].data[7] = 0x00;
    // for(int i=0;i<100;i++)
    // {
    ofstream data;
    data.open("candata.txt",ios::out);
    data<<"rpm"<<"         "<<"time_msec"<<endl;
    struct timeval time;
    gettimeofday(&time,NULL);
    long startTime=time.tv_sec;
    // while(1){
    //     gettimeofday(&time,NULL);
    //     cout<<((time.tv_sec-startTime)*1000+time.tv_usec/1000)<<endl;
    // }
    long time_msec;
    int rpm;
    while(1){
        int i=0;
        int speed=0;
        float duty;
        cin>>duty;
        while(1){
            //cout<<"hello"<<endl;
            //frame[0].data[7]++;
            // nbytes = write(s, &frame[0], sizeof(frame[0])); //发送 frame[0]
            // if(nbytes != sizeof(frame[0]))
            // {
            //     printf("Send Error frame[0]\n!");
            // }
            VESC_duty_can_send(s,0x74,duty*100000);
            // VESC_RPM_can_send(s,0x74,speed);
            
            rpm=VESC_can_receive(s,0x74);
            if(rpm!=-1){
                gettimeofday(&time,NULL);
                time_msec=((time.tv_sec-startTime)*1000+time.tv_usec/1000);
                data<<rpm<<"         "<<time_msec<<endl;

            }
            
            
            while(i!=10000){
                //cout<<i<<endl;
                i++;
            }
            i=0;
        }
        //cout<<"bind "<<i<<endl;
 
        nbytes = read(s, &frame[1], sizeof(frame[1]));//接收总线上的报文保存在frame[1]中
        printf("the nbytes:%d\n", nbytes);
        printf("length:%d", sizeof(frame[1]));
        printf("ID=0x%X DLC=%d\n", frame[1].can_id, frame[1].can_dlc);
        printf("data0=0x%02x\n",frame[1].data[0]);
        printf("data1=0x%02x\n",frame[1].data[1]);
        printf("data2=0x%02x\n",frame[1].data[2]);
        printf("data3=0x%02x\n",frame[1].data[3]);
        printf("data4=0x%02x\n",frame[1].data[4]);
        printf("data5=0x%02x\n",frame[1].data[5]);
        printf("data6=0x%02x\n",frame[1].data[6]);
        printf("data7=0x%02x\n",frame[1].data[7]);
        //sleep(1);
    }
    // }
 
    close(s);
    return 0;
}


