class Solution {
public:
    bool helper(vector<int> &a, int start, unordered_set<int>& visited){
        if(start < 0 || start > a.size() - 1) return false;
        if(a[start] == 0){
            return true;
        }
        if(visited.find(start) != visited.end()) return false;
        visited.insert(start);
        bool h1 = helper(a, start + a[start], visited);
        bool h2 = helper(a, start - a[start], visited);
        return h1||h2;
    }
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
        bool ans = helper(arr, start, visited);
        return ans;
    }
};