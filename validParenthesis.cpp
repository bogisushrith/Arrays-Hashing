class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int length = s.size();
        for(int i = 0 ; i < length ; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if(st.size() == 0)
                    return false;
                char ch = st.top();
                if(s[i] == ']' && ch == '[')
                    st.pop();
                else if(s[i] == ')' && ch == '(')
                    st.pop();
                else if(s[i] == '}' && ch == '{')
                    st.pop();
                else 
                    return false;
            }
        }
        if(st.size() == 0)
            return true;
        return false;
    }
};
