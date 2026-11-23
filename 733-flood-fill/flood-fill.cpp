class Solution {
public:
    void dfs(vector<vector<int>>& image, int color, int i, int j, int n, int m, int ok){
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        if(image[i][j] != ok) return;
        image[i][j] = color;
        dfs(image, color, i + 1, j, n, m, ok);
        dfs(image, color, i - 1, j, n, m, ok);
        dfs(image, color, i, j + 1, n, m, ok);
        dfs(image, color, i, j - 1, n, m, ok);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == color) return image;
        dfs(image, color, sr, sc, n, m, image[sr][sc]);
        return image;
    }
};