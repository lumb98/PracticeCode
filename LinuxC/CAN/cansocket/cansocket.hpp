#ifndef __CANSOCKET_HPP__
#define __CANSOCKET_HPP__
typedef char data_byte[16];
template <typename T>
data_byte* spilt_dataTobyte(const T &data,int target_len);

#endif
