class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // checking on rows and making 1st column all 1
        for(int i = 0 ; i < rows ; i++){
            if(grid[i][0] == 0){
                int j = 0;
                while(j<cols){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                    }
                    else{
                        grid[i][j] = 0;
                    }
                    j++;
                }
            }
        }
        // flipping the columns where no.0 > no.1
        for(int i = 0 ; i < cols ; i++){
            int noz = 0;
            int noo = 0;
            for(int j = 0 ; j < rows ; j++){
                if(grid[j][i] == 0){
                    noz++;
                }
                else{
                    noo++;
                }
            }
            if(noz > noo){ //flip
                int j = 0;
                while(j<rows){
                    if(grid[j][i] == 0){
                        grid[j][i] = 1;
                    }
                    else{
                        grid[j][i] = 0;
                    }
                    j++;
                }
            }
        }
        int sum = 0;
        for(int i = 0 ; i < rows ; i++){
            int x = 1;
            for(int j = cols-1 ; j >= 0 ; j--){
                sum += grid[i][j]*x;
                x *= 2;
            }
        }
        return sum;
    }
};