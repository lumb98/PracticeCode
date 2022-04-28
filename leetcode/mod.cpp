#include <iostream>
#include <vector>
#include <string>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

 };

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode*  next;
        LinkedNode(int val) : val(val),next(nullptr) {}
    };

    MyLinkedList() {
        _dummyHead=new LinkedNode(0);
        _size=0;
    }
    
    int get(int index) {
        if(index>_size-1||index<0)
            return -1;
        LinkedNode* cur=_dummyHead->next;
        while(index--){
            cur=cur->next;
        }
        //printLinkedList();
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next=_dummyHead->next;
        _dummyHead->next=newNode;
        ++_size;
        //printLinkedList();
    }
    
    void addAtTail(int val) {
        LinkedNode* tail = new LinkedNode(val);
        LinkedNode* temp=_dummyHead;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=tail;
        ++_size;
        //printLinkedList();
    }
    
    void addAtIndex(int index, int val) {
        if(index>_size||index<0)
            return ;
        LinkedNode* cur=_dummyHead;
        LinkedNode* newNode=new LinkedNode(val);
        while(index--){
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
        ++_size;
        //printLinkedList();
    }
    
    void deleteAtIndex(int index) {
        if(index>=_size||index<0){
            cout<<"erro"<<endl;
            return ;
        }
            
        LinkedNode* cur=_dummyHead;
        while(index--){
            cur=cur->next;
        }
        LinkedNode* tmp=cur->next;
        cur->next=cur->next->next;
        delete tmp;
        --_size;
        //printLinkedList();
    }

    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    private:
        int _size;
        LinkedNode* _dummyHead;
};


class Solution {
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


void printmat(vector<vector<int>> tmp);

//创建一个X行Y列的顺序二维数组并返回。
vector<vector<int>> creatmat(int x,int y);

void printmat(vector<int> tmp);



int main(){
    Solution output;
    int n=7;
    ListNode p;
    //p.next
    printmat(output.generateMatrix(n));
    return 0;
}



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