class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int rowstart = 0, colstart = 0, rowend = r - 1, colend = c - 1;

        vector<int> result;

        while (rowstart <= rowend && colstart <= colend) {
            // Traverse right
            for (int i = colstart; i <= colend; i++) {
                result.push_back(matrix[rowstart][i]);
            }
            rowstart++;

            // Traverse down
            for (int j = rowstart; j <= rowend; j++) {
                result.push_back(matrix[j][colend]);
            }
            colend--;

            // Traverse left
            if (rowstart <= rowend) {
                for (int k = colend; k >= colstart; k--) {
                    result.push_back(matrix[rowend][k]);
                }
                rowend--;
            }

            // Traverse up
            if (colstart <= colend) {
                for (int l = rowend; l >= rowstart; l--) {
                    result.push_back(matrix[l][colstart]);
                }
                colstart++;
            }
        }

        return result;
    }
};