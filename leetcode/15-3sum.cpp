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