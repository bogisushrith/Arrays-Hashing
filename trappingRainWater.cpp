class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefixSum(n, 0);
        vector<int>suffixSum(n, 0);
        int leftMax = 0;
        for(int i = 0 ; i < n ; i++)
        {
            prefixSum[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }
        int rightMax = 0;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            suffixSum[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }
        int answer = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(prefixSum[i] > height[i] && suffixSum[i] > height[i])
            {
                int mini =  min(prefixSum[i], suffixSum[i]);
                answer += mini - height[i];
            }
        }
        return answer;
    }
};