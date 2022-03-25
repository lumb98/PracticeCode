#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>//用于sort排序
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// 三元组元素c去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // if(nums.size()<=2||nums[0]>0)
        //     return ans;
        for(int i=0;i<nums.size();++i){
             if (nums[i] > 0) {
                break;
            }
            if(i>0&&nums[i]==nums[i-1])
                continue;
            unordered_set<int> set;
            for(int j=i+1;j<nums.size();++j)
            {
                if(j>i+2&&nums[j]==nums[j-1]&&nums[j-1]==nums[j-2])
                    continue;
                int x=0-nums[i]-nums[j];
                if(set.find(x)!=set.end()){
                    ans.push_back({nums[i],nums[j],x});
                    set.erase(x);
                }else{
                    set.emplace(nums[j]);
                }
            }
        }

        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            if(nums[i]>0)
                return ans;
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=n-1;
            int target=0-nums[i];
            while(start<end){
                if(start>i+1&&nums[start]==nums[start-1]){
                    ++start;
                    continue;
                }
                
                if(nums[start]+nums[end]>target){
                    --end;
                }else if(nums[start]+nums[end]<target)
                    ++start;
                else if(nums[start]+nums[end]==target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    end=n-1;
                    ++start;
                }
            }
        }
        return ans;
    }
};

//100ms内终极版，找到原因了，上面那个200ms是因为我每次找到数组之后，都把end复位，这个操作导致，多走了很多路。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            if(nums[i]>0)
                return ans;
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=n-1;
            int target=0-nums[i];
            while(start<end){
                
                if(start>i+1&&nums[start]==nums[start-1]){
                    ++start;
                    continue;
                }
                int sum=nums[start]+nums[end];
                if(sum>target){
                    --end;
                }else if(sum<target){
                    ++start;
                }else {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    ++start;
                    --end;
                }
            }
        }
        return ans;
    }
};