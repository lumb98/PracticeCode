#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using  namespace std;

int main(void){
    string storage;
    char target;
    unordered_map<char,int> mp;

    getline(cin,storage);

    cin>>target;
        
    int count=0;
    if(target>64)
        for(char o:storage){

            if(o==target||o+32==target||o-32==target){
                ++count;
            }
        }
    else
        for(char o:storage){

            if(o==target){
                ++count;
            }
        }
    cout<<count<<endl;
}