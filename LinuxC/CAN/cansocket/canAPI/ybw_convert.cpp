#include "ybw_convert.h"

void datatobyte(__uint8_t *output, __uint64_t data, int mod) {
    if (mod == BIGENDIAN) {
        for (int i = 0; i < sizeof(data); ++i) {
            output[i] = (data >> 8 * (sizeof(data) - 1 - i)) & 0xff; 	//每次右移八个位，那么我们最开始就把最左边的（即高地址）存到了数组的低地址，这就是大端
        }
    }
    else {//LITTLEENDIAN
        for (int i = 0; i < sizeof(data); ++i) {
            output[i] = (data >> 8 * i) & 0xff;      			//每次右移八个位，那么我们最开始就把最右边的（即低地址）字节存到了数组的低地址，这就是小端
        }
    }
}

void bytetodata(__uint64_t *output, __uint8_t* input, int mod) {
    (*output)=0;
    if (mod == BIGENDIAN) {
        for (int i = 0; i < 8; ++i) {
            (*output) |= ((__uint64_t)input[i] << (8 * (8 - 1 - i)));
        }
    }
    else {//LITTLEENDIAN
        for (int i = 0; i < sizeof(output); ++i) {
            (*output) |= ((__uint64_t)input[i] << (8 * (i)));
        }
    }
}