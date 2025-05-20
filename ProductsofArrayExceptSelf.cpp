class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix;
        vector<int>postfix;
        int length = nums.size();
        int previousValue = 1;
        for(int i = 0 ; i < length ; i++)
        {
            prefix.push_back(previousValue);
            previousValue *= nums[i];
        }
        previousValue = 1;
        for(int i = length - 1 ; i >= 0 ; i--)
        {
            postfix.push_back(previousValue);
            previousValue *= nums[i];
        }
        reverse(postfix.begin(), postfix.end());
        vector<int>answer;
        for(int i = 0 ; i < length ; i++)
            answer.push_back(prefix[i]*postfix[i]);
        return answer;
    }
};
