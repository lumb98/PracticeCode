#include <iostream>
#include <string>

using namespace std;

// class Solution {
// public:
//     string reverseLeftWords(string s, int n) {
//         string temp;
//         for(int i=0;i<n;++i){
//             temp.push_back(s[i]);
//         }
//         s.erase(s.begin(),s.begin()+n);
//         for(char t:temp){
//             s.push_back(t);
//         }
//         return s;
//     }
// };


class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int size=s.size();
        for(int i=0;i<n;++i){
            s.push_back('0');
        }
        for(int i=0;i<n;++i){
            s[size+i]=s[i];
        }
        s.erase(s.begin(),s.begin()+n);
        return s;
    }
};


int main(void){
    int n=0; 
    cin>>n;
    string s;   
    // getline(cin,s);
    cin>>s;
    cout<<"???"<<endl;
    Solution slt;

    string ans=slt.reverseLeftWords(s,n);

    cout<<ans<<endl;
    return 0;
}