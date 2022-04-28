#if !defined(__YBW_CAN_H__)
#define __YBW_CAN_H__
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <linux/can.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include "ybw_convert.h"

#define CAN_RECV_BLOCK true
#define CAN_RECV_UNBLOCK false
typedef bool black_flag;

int can_init(char *name);
int can_send_8byte(int socket,int64_t data,canid_t can_id );
int can_send_8byte(int socket,int64_t data,canid_t can_id );

#endif // __YBW_CAN_H__
