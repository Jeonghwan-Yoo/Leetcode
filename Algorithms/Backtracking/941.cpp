// O(N)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = (int)arr.size();
        
        int pos = 1;
        while (pos < n && arr[pos - 1] < arr[pos])
            ++pos;
        
        if (pos == 1 || pos == n)
            return false;
        
        while (pos < n && arr[pos - 1] > arr[pos])
            ++pos;
        
        return pos == n;
    }
};