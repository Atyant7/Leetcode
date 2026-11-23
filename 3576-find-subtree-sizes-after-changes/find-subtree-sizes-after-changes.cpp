class Solution {
public:
    vector<vector<int>> originalTree, newTree;
    vector<int> lastSeen, answer;

    void buildTree(int node, vector<int>& parent, string& s) {
        int c = s[node] - 'a';
        int prev = lastSeen[c];

        if(node != 0) {
            int p = (prev == -1) ? parent[node] : prev;
            newTree[p].push_back(node);
        }

        lastSeen[c] = node;

        for(int child : originalTree[node]) {
            buildTree(child, parent, s);
        }

        lastSeen[c] = prev;
    }

    int dfs(int node) {
        answer[node] = 1;

        for(int child : newTree[node]) {
            answer[node] += dfs(child);
        }

        return answer[node];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        originalTree.resize(n);
        newTree.resize(n);
        answer.resize(n, 0);
        lastSeen.assign(26, -1);

        for(int i = 1; i < n; i++) {
            originalTree[parent[i]].push_back(i);
        }

        buildTree(0, parent, s);
        dfs(0);

        return answer;
    }
};