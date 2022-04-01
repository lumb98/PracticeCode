#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int sizex=3,sizey=2;
    // cin>>sizex>>sizey;
    // int temp;
    vector<int> x={3,8,9},y={1,7};
    // while(cin>>temp){
    //     x.push_back(temp);
    // }
    // while(cin>>temp){
    //     y.push_back(temp);
    // }
    vector<int> ans;
    int xptr=0;
    int yptr=0;
    cout<<"xptr="<<xptr<<"yptr="<<yptr<<endl;
    while(ans.size()<(unsigned int)(sizex+sizey)){
        cout<<"xptr="<<xptr<<"yptr="<<yptr<<endl;
        if(xptr==sizex-1){
            for(int i=yptr;i<sizey;++i){
                ans.push_back(y[yptr]);
            }
        }
        if(yptr==sizey-1){
            for(int i=xptr;i<sizex;++i){
                ans.push_back(x[xptr]);
            }
        }
        if(x[xptr]<y[yptr]){
            ans.push_back(x[xptr]);
            ++xptr;
        }else if(x[xptr]>y[yptr]){
            ans.push_back(y[yptr]);
            ++yptr;
        }else{
            ++yptr;
            ++xptr;
        }
    }
    for(int o:ans)
    cout<<o<<" ";
    cout<<endl;

}