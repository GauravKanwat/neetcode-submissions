class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int pile : piles) {
                cnt += ceil((double)pile / mid);
            }
            if(cnt <= h) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
