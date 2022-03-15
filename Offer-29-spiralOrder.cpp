
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream> 
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;
using std::max;


/*
思路
左向右即top是从左到右的，两边都是闭区间，即都是从left-right
上向下，从top+1到bottom
右向左，从right-1到left+1
下向上，从bottom到top+1
*/
#define INPUT 7
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int Ysize=matrix.size();
        if(Ysize==0){
            return {};
        }
        int Xsize=matrix[0].size();
        int left=0,right=Xsize-1,top=0,bottom=Ysize-1;
        while(left<=right&&top<=bottom){

            for(int i=left;i<=right;++i){
                ans.push_back(matrix[top][i]);
            }
            
            for(int j=top+1;j<=bottom;++j){
                ans.push_back(matrix[j][right]);
            }
            if(left<right&&top<bottom){
                
                for(int i=right-1;i>left;--i){
                    ans.push_back(matrix[bottom][i]);
                }
            
                for(int j=bottom;j>top;--j){
                    ans.push_back(matrix[j][left]);
                }
            }
            ++left;
            ++top;
            --right;
            --bottom;
            
        }
         return ans;
    }
};




void printmat(vector<vector<int>> tmp){
    int y=tmp.size();
    int x=tmp[0].size();
    for (int i=0;i<y;++i){
        for(int j=0;j<x;++j){
            if(tmp[i][j]<10)
                cout<<tmp[i][j]<<"   ";
            else
                cout<<tmp[i][j]<<"  ";

        }
        cout<<endl;
    }
}

vector<vector<int>> creatmat(int x,int y){
    int count=1;
    vector<vector<int>> output(y,vector<int>(x));
    for(int i=0;i<y;++i){
        for(int j=0;j<x;++j){
            output[i][j]=count++;
        }
    }
    return output;
}

void printmat(vector<int> tmp){
    int x=tmp.size();
    for (int i=0;i<x;++i){
        if(tmp[i]<10)
            cout<<tmp[i]<<"   ";
        else
            cout<<tmp[i]<<"  ";


        
    }
    cout<<endl;
}


int main(){
    Solution output;
    int n=INPUT;
    vector<int> ans;
    vector<vector<int>> tmp=creatmat(6,5);
    printmat(tmp);
    ans=output.spiralOrder(tmp);
    cout<<"ans="<<endl;
    printmat(ans);
    // for(int i=10;i>=0;--i){
    //     cout<<i<<endl;
    // }
    
    return 0;
}
