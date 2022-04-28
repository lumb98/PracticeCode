#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        int size=output.size();
        for(int i=0;i<size;++i){
            input.push(output.front());
            output.pop();
        }
        input.push(x);
    }
    
    int pop() {
        int size=input.size();
        for(int i=0;i<size-1;++i){
            output.push(input.front());
            input.pop();
        }
        int temp =input.front();
        input.pop();
        size=output.size();
        for(int i=0;i<size;++i){
            input.push(output.front());
            output.pop();
        }
        return temp;
    }
    
    int top() {
        if(output.size()==0)
            return input.back();
        else
            return output.back();
    }
    
    bool empty() {
        if(output.size()==0&&input.size()==0)
            return true;
        else 
            return false;
    }
private:

queue<int> input;
queue<int> output;

};

int main(void){
    MyStack * s=new MyStack();
    int temp;
    cin>>temp;
    s->push(temp);
    cin>>temp;
    s->push(temp);
    cout<<s->top()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->empty()<<endl;
    return 0;
}