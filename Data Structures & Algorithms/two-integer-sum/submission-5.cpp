class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) {
            int rem = target - nums[i];
            auto it = mpp.find(rem);
            if(it != mpp.end()) return {it->second, i};
            mpp[nums[i]] = i;
        }
        return {};
    }
};
