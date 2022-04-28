#if !defined(__YBW_CONVERT_I_H__)
#define __YBW_CONVERT_I_H__
template <typename T>
extern void datatobyte(char *output, T data, int mod);

template <typename T>
extern void bytetodata(T *output, char* input, int mod);


#endif // __YBW_CONVERT_I_H__
