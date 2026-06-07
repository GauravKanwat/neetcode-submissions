class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(prev == nums[i]) return true;
            prev = nums[i];
        }
        return false;
    }
};