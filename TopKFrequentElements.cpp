class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
           unordered_map<int, int>freq;
           for(int it : nums)
            freq[it]++;
            priority_queue <pair<int, int>, vector< pair<int, int>>, greater<>>minHeap;
            for(const auto&[num, count] : freq)
            {
                minHeap.push({count, num});
                if(minHeap.size() > k)
                    minHeap.pop();
            }
            vector<int>ans;
            while(!minHeap.empty())
            {
                ans.push_back(minHeap.top().second);
                minHeap.pop();
            }
            return ans;
        }
    };
    