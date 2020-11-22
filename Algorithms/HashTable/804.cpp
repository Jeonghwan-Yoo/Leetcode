// O(N^2)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> setOfMorse;
        for (auto &word : words)
        {
            string s;
            for (auto &w : word)
                s += morse[w - 'a'];
            setOfMorse.emplace(s);
        }
        
        return (int)setOfMorse.size();
    }
    string const morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
};