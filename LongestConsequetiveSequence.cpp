class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>mp;
        for(int i = 0 ; i < nums.size() ; i++)
            mp[nums[i]] = 1;
        int maximum = 0;
        for(auto it : mp)
        {
            if(mp.find(it.first - 1) != mp.end())
                mp[it.first] = mp[it.first - 1] + 1;
            maximum = max(maximum, mp[it.first]);
        }
        return maximum;
    }
};