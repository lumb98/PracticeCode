#ifndef __SUM_H__
#define __SUM_H__
#include <initializer_list>
#include <unordered_set>
#include <iostream>
using namespace std;
typedef int arrT[10];

typedef char data_byte[16];
template <typename T>
data_byte* spilt_dataTobyte(const T &data,int target_len);

// int sum(int &num1,int &num2);
int fact(int &input);
int fact2(void);
int sum(initializer_list<int> lst);
arrT* test(int n);
int (*test2(int n))[10];
void unordered_set_practice(void);

#endif