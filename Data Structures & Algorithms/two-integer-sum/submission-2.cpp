class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        
        for(int i=0; i<nums.size(); i++) {
            int res = target - nums[i];
            if(mpp.find(res) != 0) return {mpp[res], i};
            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
