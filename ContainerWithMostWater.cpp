class Solution {
public:
    int maxArea(vector<int>& heights) {
        int length = heights.size();
        int left = 0;
        int right = length - 1;
        int maximumAmount = -1;
        while(left < right)
        {
            maximumAmount = max(maximumAmount, min(heights[left], heights[right])*(right - left));
            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return maximumAmount;
    }
};
