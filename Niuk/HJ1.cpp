#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
    string temp;
    vector<string> storage;
    while (cin>>temp)
    {
        storage.push_back(temp);
    }
    int size=storage.size();
    cout<<storage[size-1].size()<<endl;
    return 0;
}