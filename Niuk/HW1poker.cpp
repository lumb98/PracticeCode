#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <thread>

using namespace std;
class compare1 {
    bool operator()(const pair<int,multimap<int,int>> a, const pair<int, multimap<int, int>> b) {
        if(a.first!=b.first)
            return a.first < b.first;
        else if (a.first == b.first) {
            return a.second < b.second;
        }
    }
};
int main(void){
    vector<vector<int>> in={{1,2},
                            {1,3},
                            {1,4},
                            {1,12},
                            {2,2},
                            {2,3},
                            {3,6},
                            {3,7},
                            {3,8},
                            {3,9},
                            {4,10},
                            {4,2},
                            {3,2},
                            {4,13},};
    int nums=14;
    set<pair<int, int>, compare1> input;
    //set<pair<int, multimap<int, int>>> pai;//数量 大小 花色
    //pair<int, multimap<int, int>> temp;
    //multimap<int, int> mtemp;
    cout << "hello" << endl;
    for (int i = 0; i < 14; ++i) {
        input.insert(make_pair(in[i][1], in[i][0]));
    }
    for (auto print : input) {
        cout << print.first << " " << print.second << endl;
    }

}