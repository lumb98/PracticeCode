#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>//用于sort排序
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size=nums.size();
        if(size<4)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<size;++i){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<size;++j){
                if(j>i+1&&nums[j]==nums[j-1]){
                continue;
                }
                int start=j+1;
                int end=size-1;
                int temptarget=target-nums[i]-nums[j];
                while(start<end){
                    if(nums[start]+nums[end]<temptarget){
                        ++start;
                        while(start<end&&nums[start]==nums[start-1])++start;
                    }else if(nums[start]+nums[end]>temptarget){
                        --end;
                        while(start<end&&nums[end]==nums[end+1])--end;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        while(start<end&&nums[start]==nums[start+1])++start;    //这里的两个去重和前面的两个判断的方向是相反的，没想明白为什么，
                        while(start<end&&nums[end]==nums[end-1])--end;      //去掉这两行或者写的和上面一样都会出现重复的数组。
                        --end;
                        ++start;
                    }

                }

            }
            
        }

        return ans;
    }
};