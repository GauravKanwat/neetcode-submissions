class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]+1000]++;
        }
        vector<pair<int,int>> temp;
        for(auto it : mpp)
            temp.push_back({it.second, it.first});
        sort(temp.rbegin(), temp.rend());
        vector<int> ans;
        int i = 0;
        while(i < k) {
            int num = temp[i].second;
            ans.push_back(num-1000);
            i++;
        }
        return ans;
    }
};
