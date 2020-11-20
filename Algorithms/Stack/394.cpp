// O(N)
class Solution {
public:
    string decodeString(string s) {
        int n = (int)s.size();
        
        stack<int> cnt;
        stack<string> st;
        string cur;
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i]))
                num = 10 * num + s[i] - '0';
            else if (s[i] == '[')
            {
                st.emplace(cur);
                cnt.emplace(num);
                cur.clear();
                num = 0;
            }
            else if (s[i] == ']')
            {
                int curCnt = cnt.top();
                cnt.pop();
                string prev = st.top();
                st.pop();
                for (int j = 0; j < curCnt; ++j)
                    prev += cur;
                cur = prev;
            }
            else
                cur += s[i];
        }
        
        return cur;
    }
};