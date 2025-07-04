class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<pair<int, double>, int>mp;
        int length = position.size();
        for(int i = 0 ; i < length ; i++)
        {
            int len = target - position[i];
            double time = (static_cast<double>(len) / speed[i]); 
            mp[{position[i], time}]++;
        }
        stack< pair<int, double> >st;
        vector< pair<int, double> >v;
        for(auto it : mp)
            v.push_back({it.first.first, it.first.second});
        reverse(v.begin(), v.end());
        for(int i = 0 ; i < v.size() ; i++)
        {
            if(st.empty())
                st.push(v[i]);
            else
            {
                auto it = st.top();
                if(it.second < v[i].second)
                    st.push(v[i]);
            }
        }
        return st.size();
    }
};