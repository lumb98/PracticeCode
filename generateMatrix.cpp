#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution1 {
public:
    vector<vector<int>> generateMatrix(int n) {
        cout<<"Hello"<<endl;
        int ring=n;
        int y=0,x=0;
        int count=1;
        int turn=0;
        int fix=0;
        vector<vector<int>> tmp(n,vector<int>(n));
        if(n==0) return tmp;
        //while(count<=n*n){

            while(count<=n*n){     //转弯计数 转三次 第三次后 内循环运行ring-2次 运行四次后ring=ring-2
                
                
                if (ring==1){
                    tmp[y][x]=n*n;
                    //printmat(tmp);
                    return tmp;
                }
                for(int i=0;i<ring-1;++i){   //前进计数运行ring-1次
                    
                    if(tmp[y][x]!=0) {
                        cout<<"ERRO in "<<x<<" "<< y<< " already have "<<tmp[y][x]<<endl;
                        //printmat(tmp);
                        return tmp;
                    }
                    
                    tmp[y][x]=count;
                    switch (turn)
                    {
                    case 0/* constant-expression */:
                        /* code */
                        ++x;
                        break;
                    case 1/* constant-expression */:
                        /* code */
                        ++y;
                        break;
                    case 2/* constant-expression */:
                        /* code */
                        --x;
                        break;        
                    case 3/* constant-expression */:
                        /* code */
                        --y;
                        break;
                    default:
                        break;
                    }
                    ++count;
                }
                
                if(turn==3){
                    ring-=2;
                    turn=-1;
                    ++x;
                    ++y;
                }
                ++turn;
                            
            }
        //printmat(tmp);
        

        return tmp;
    }
};

class Solution2 {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> tmp(n,vector<int>(n));
    int startx=0,starty=0;
    int loop=n/2;
    int count=1;
    int offset=1;
    while(loop--){
        int i=startx;
        int j=starty;
        for(;i<startx+n-offset;++i){
            tmp[j][i]=count++;
        }
        for(;j<starty+n-offset;++j){
            tmp[j][i]=count++;
        }
        for(;i>startx;--i){
            tmp[j][i]=count++;
        }
        for(;j>starty;--j){
            tmp[j][i]=count++;
        }
        ++startx;
        ++starty;
        offset+=2;
    }
    if(n%2){
        tmp[n/2][n/2]=n*n;
    }

    return tmp;
    }
};
void printmat(vector<vector<int>> tmp){
    int n=tmp.size();
    for (int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(tmp[i][j]<10)
                cout<<tmp[i][j]<<"   ";
            else
                cout<<tmp[i][j]<<"  ";

        }
        cout<<endl;
    }
}

int main(){
    Solution2 output;
     int n=8;

 
    // int ring=n;
    // int y=0,x=0;
    // int count=1;
    // int turn=0;
    // int fix=0;
    // vector<vector<int>> tmp(n,vector<int>(n));
    printmat(output.generateMatrix(n));
    // if(n==0) return 0;
    // //while(count<=n*n){

    //     while(count<=n*n){     //转弯计数 转三次 第三次后 内循环运行ring-2次 运行四次后ring=ring-2
            
            
    //         //cout<<"turn="<<turn<<endl;
    //         //if (turn==3) fix=1;
    //         //    else fix=0;
    //         if (ring==1){
    //             tmp[y][x]=n*n;
    //             printmat(tmp);
    //             return 0;
    //         }
    //         for(int i=0;i<ring-1;++i){   //前进计数运行ring-1次
                
    //             //cout<<"x="<<x<<" y="<<y<<endl;
    //             if(tmp[y][x]!=0) {
    //                 cout<<"ERRO in "<<x<<" "<< y<< " already have "<<tmp[y][x]<<endl;
    //                 printmat(tmp);
    //                 return 0;
    //             }
                
    //             tmp[y][x]=count;
    //             switch (turn)
    //             {
    //             case 0/* constant-expression */:
    //                 /* code */
    //                 ++x;
    //                 break;
    //             case 1/* constant-expression */:
    //                 /* code */
    //                 ++y;
    //                 break;
    //             case 2/* constant-expression */:
    //                 /* code */
    //                 --x;
    //                 break;        
    //             case 3/* constant-expression */:
    //                 /* code */
    //                 --y;
    //                 break;
    //             default:
    //                 break;
    //             }
    //             ++count;
    //         }
            
    //         if(turn==3){
    //             ring-=2;
    //             turn=-1;
    //             ++x;
    //             ++y;
    //         }
    //         ++turn;
            
    //         //printmat(tmp);
    //         //cout<<"count= "<<count<<endl;
    //         //cout<<"ring= "<<ring<<endl;
    //         //cout<<endl;
                
            
    //     }
    // //}
    // printmat(tmp);
    

    //cout<<tmp[3][3]<<endl;
    // vector<int> tmp2{1, 3, 5, 7, 9};
    // cout<<"HelloWorld!!!"<<endl;
    // cout <<"tmp[0]="<< --tmp[0] << endl;
    // cout <<"tmp2[0]="<< tmp2[0] << endl;
    // if(++tmp2[0]==2)
    //     cout<<"++before==="<< tmp2[0]<<endl;
    return 0;
}
