// O(N)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        
        if (hash.count(node) == 0)
        {
            hash[node] = new Node(node->val);
            for (auto &n : node->neighbors)
                hash[node]->neighbors.emplace_back(cloneGraph(n));
        }
        
        return hash[node];
    }
private:
    unordered_map<Node*, Node*> hash;
};