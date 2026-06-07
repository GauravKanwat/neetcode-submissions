class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int zeros = 0, product = 1;
        for(int i : nums) {
            if(i == 0) zeros++;
            product *= i;
        }
        if(zeros > 1) return res;
        else if(zeros == 1) {
            int idx = 0;
            product = 1;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] != 0) product *= nums[i];
                if(nums[i] == 0) idx = i;
            }
            res[idx] = product;
        }
        else {
            for(int i=0; i<nums.size(); i++) {
                int temp = product / nums[i];
                res[i] = temp;
            }
        }
        return res;
    }
};
