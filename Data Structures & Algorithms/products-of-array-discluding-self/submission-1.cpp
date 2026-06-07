class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), postf(n, 1);
        
        for(int i=0; i<n; i++) {
            if(i>0) pref[i] = pref[i-1]*nums[i-1];
        }
        for(int i=n-1; i>=0; i--)
            if(i < n-1) postf[i] = postf[i+1]*nums[i+1];

        vector<int> ans;
        for(int i=0; i<n; i++)
            ans.push_back(pref[i] * postf[i]);
        return ans;
    }
};
