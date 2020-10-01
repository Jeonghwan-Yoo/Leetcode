// O(1)
class RecentCounter {
public:
    RecentCounter() {
        queue<int> empty;
        swap(q, empty);
    }
    
    int ping(int t) {
        q.emplace(t);
        while (q.front() < t - 3000)
            q.pop();
        
        return (int)q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */