class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int low = 0, high = n-1;
        int maxArea = 0;
        while(low < high) {
            int area = min(heights[low], heights[high]);
            area = area * (high - low);
            maxArea = max(area, maxArea);
            if(heights[low] < heights[high]) low++;
            else high--;
        }
        return maxArea;
    }
};
