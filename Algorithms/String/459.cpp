// O(N)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = (int)s.size();
        vector<int> fail(n + 1);
        for (int i = 1, j = 0; i < n; ++i)
        {
            while (j > 0 && s[i] != s[j])
                j = fail[j - 1];
            if (s[i] == s[j])
            {
                ++j;
                fail[i] = j;
            }
        }
        if (fail[n - 1] && fail[n - 1] % (n - fail[n - 1]) == 0)
            return true;

        return false;
    }
};

// O(N)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        int n = (int)ss.size();
        if (ss.substr(1, n - 2).find(s) != string::npos)
                return true;
        
        return false;
    }
};

// O(N^2)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = (int)s.size();
        for (int i = 1; i <= (n >> 1); ++i)
            if (n % i == 0 && s.substr(i) == s.substr(0, n - i))
                return true;
        
        return false;
    }
};

// O(N^3)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = (int)s.size();
        for (int i = 1; i <= (n >> 1); ++i)
        {
            if (n % i != 0)
                continue;
            
            bool flag = true;
            string prefix = s.substr(0, i);
            for (int j = i; j < n; j += i)
            {
                if (prefix != s.substr(j, i))
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                return true;
        }
        return false;
    }
};