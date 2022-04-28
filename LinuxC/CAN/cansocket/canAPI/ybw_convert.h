#if !defined(__YBW_CONVERT_H__)
#define __YBW_CONVERT_H__
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#define BIGENDIAN 1
#define LITTLEENDIAN 0


/*
    set MOD for select bigendian or littleendian
*/

// template <typename T>
void datatobyte(__uint8_t *output, __int64_t data, int mod) ;


// template <typename T>
void bytetodata(__int64_t *output, __uint8_t* input, int mod);


#endif // __YBW_CONVERT_H__
