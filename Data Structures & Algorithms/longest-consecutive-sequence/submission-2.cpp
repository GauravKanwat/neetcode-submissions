class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(int i : nums) st.insert(i);

        int longest = 1;
        for(auto it : st) {
            int curr = it;
            int count = 1;
            if(st.find(curr - 1) == st.end()) {
                while(st.find(curr + 1) != st.end()) {
                    curr++; count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
