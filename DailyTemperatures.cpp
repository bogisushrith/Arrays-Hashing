class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>answer;
        stack<int>stk;
        int length = temperatures.size();
        for(int i = length - 1 ; i >= 0 ; i--)
        {
            if(stk.empty())
            {
                answer.push_back(0);
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && temperatures[stk.top()] <= temperatures[i])
                    stk.pop();
                if(!stk.empty())
                {
                    answer.push_back(stk.top() - i);
                    stk.push(i);
                }
                else
                {
                    answer.push_back(0);
                    stk.push(i);
                }
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
