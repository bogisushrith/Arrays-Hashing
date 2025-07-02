class Solution {
public:
    void solve(string s, vector<string>&answer, int open, int close, int n)
    {
        if(open + close >= (2*n))
        {
            answer.push_back(s);
            return;
        }
        if(open < n)
            solve(s + "(", answer, open + 1, close, n);
        if(close < open)
            solve(s + ")", answer, open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>answer;
        string s = "";
        solve(s, answer, 0, 0, n);
        return answer;
    }
};
