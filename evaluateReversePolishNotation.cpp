class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int length = tokens.size();
        for(int i = 0 ; i < length ; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int number2 = st.top();
                st.pop();
                int number1 = st.top();
                st.pop();
                if(tokens[i] == "+")st.push(number1 + number2);
                else if(tokens[i] == "-")st.push(number1 - number2);
                else if(tokens[i] == "*")st.push(number1 * number2);
                else if(tokens[i] == "/")st.push(number1 / number2);
            }
            else
            {
                int value = stoi(tokens[i]);
                st.push(value);
            }
        }
        return st.top();
    }
};