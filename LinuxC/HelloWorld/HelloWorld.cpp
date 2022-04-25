#include <iostream>
using namespace std;
#define put(helloworld) #helloworld
int main(int argc,char *argv[])
{
    cout<<put(helloworld)<<endl;

    return 0;
}
