class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int maxarea = 0;
        while(left < right) {
            int area = (min(heights[left], heights[right])) * (right - left);
            maxarea = max(maxarea, area);
            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return maxarea;
    }
};
