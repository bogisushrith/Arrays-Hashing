class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int> >answer;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 2 ; i++)
        {
            if(i > 0 && (nums[i] == nums[i-1]))continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k]; 
                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else if(sum == 0)
                {
                    int n1 = nums[j]; int n2 = nums[k];
                    answer.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && (nums[j] == n1))j++;
                    while(j < k && (nums[k] == n2))k--;
                }
            }
        }
        return answer;
    }
};