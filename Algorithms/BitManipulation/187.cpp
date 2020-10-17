// O(N)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = (int)s.size();
        if (n < 10)
            return vector<string>();
        
        int conv[26] = { 0, };
        conv['A' - 'A'] = 0b00;
        conv['C' - 'A'] = 0b01;
        conv['G' - 'A'] = 0b10;
        conv['T' - 'A'] = 0b11;
        bitset<1<<20> hash;
        bitset<1<<20> hash2;
        unsigned int key = 0;
        for (int i = 0; i < 10; ++i)
        {
            key <<= 2;
            key |= conv[s[i] - 'A'];
        }
        hash.set(key);
        
        vector<string> ret;
        for (int i = 10; i < n; ++i)
        {
            key <<= 2;
            key = 0xfffff & key;
            key |= conv[s[i] - 'A'];
            if (!hash[key])
                hash.set(key);
            else if (!hash2[key])
            {
                ret.emplace_back(s.substr(i - 9, 10));
                hash2.set(key);
            }
        }
        
        return ret;
    }
};