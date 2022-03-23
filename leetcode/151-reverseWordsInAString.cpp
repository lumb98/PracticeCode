#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> store;
        int size=s.size();
        string temp;
        for(int i=0;i<size;++i){
            if(i>0&&s[i]==' '&&s[i-1]!=' '){
                store.push_back(temp);
                temp.clear();
            }else if(s[i]==' '){
                continue;
            }else{
                temp.push_back(s[i]);
                if(i+1==size)
                    store.push_back(temp);
            }
        }
        s.clear();
        for(int j=store.size()-1;j>=0;--j){
            if(j!=store.size()-1)
                s.push_back(' ');
            for(int k=0;k<store[j].size();++k){
                s.push_back(store[j][k]);
            }
        }
        return s;
    }
};