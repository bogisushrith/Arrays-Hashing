class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>>mp;
            for(int i = 0 ; i < strs.size() ; i++)
            {
                vector<int>freq(26, 0);
                string temp = strs[i];
                for(auto ch : temp)
                    freq[ch - 'a']++;
                string hashingString = "";
                for(int j = 0 ; j < 26 ; j++)
                {
                    hashingString.push_back(freq[j]);
                    hashingString.push_back('#');
                }
                mp[hashingString].push_back(temp);
            }
            vector<vector<string>>ans;
            for(auto it : mp)
                ans.push_back(it.second);
            return ans;
        }
    };