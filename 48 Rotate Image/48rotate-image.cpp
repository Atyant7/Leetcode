class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(int i=0;i<n;i++){
            int b=n-1,a=0;
            while(a<b){
                int temp=matrix[i][a];
                matrix[i][a]=matrix[i][b];
                matrix[i][b]=temp;
                a++;
                b--;
            }
        }
    }
};