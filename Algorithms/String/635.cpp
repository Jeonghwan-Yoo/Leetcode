// O(N1 + N2)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = (int)version1.size();
        int n2 = (int)version2.size();
        int pos1 = 0;
        int pos2 = 0;
        while (pos1 < n1 || pos2 < n2)
        {
            while (pos1 < n1 && version1[pos1] == '0')
                ++pos1;
            while (pos2 < n2 && version2[pos2] == '0')
                ++pos2;
            
            string s1, s2;
            while (pos1 < n1 && version1[pos1] != '.')
            {
                s1 += version1[pos1];
                ++pos1;
            }
            while (pos2 < n2 && version2[pos2] != '.')
            {
                s2 += version2[pos2];
                ++pos2;
            }
            if (s1.empty())
                s1 = "0";
            if (s2.empty())
                s2 = "0";
            
            if ((int)s1.size() < (int)s2.size())
                return -1;
            else if ((int)s1.size() > (int)s2.size())
                return 1;
            
            for (int i = 0; i < (int)s1.size(); ++i)
            {
                if (s1[i] < s2[i])
                    return -1;
                else if (s1[i] > s2[i])
                    return 1;
            }
            ++pos1;
            ++pos2;
        }
        return 0;
    }
};