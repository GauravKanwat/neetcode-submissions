class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlen = 0;
        for(int num : nums) {
            int streak = 0, curr = num;
            while(st.find(curr) != st.end()) {
                streak++; curr++;
            }
            maxlen = max(streak, maxlen);
        }
        return maxlen;
    }
};
