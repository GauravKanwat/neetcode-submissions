class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mpp;
        for(auto c : s) {
            mpp[c]++;
        }
        for(auto c : t) {
            mpp[c]--;
            if(mpp[c] < 0) return false;
        }
        for(auto i : mpp) {
            if(i.second > 0) return false;
        }
        return true;
    }
};
