class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v(rowIndex+1);  

        for (int i = 0; i < rowIndex + 1; i++) {
            v[i].resize(i + 1);  // each row has i+1 elements
            v[i][0] = v[i][i] = 1;  // first and last are 1

            for (int j = 1; j < i; j++) {
                v[i][j] = v[i-1][j-1] + v[i-1][j];  // Pascal's relation
            }
        }
        return v[rowIndex];
    }
};