class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        vector<vector<int>> ans;
        int minSum = INT_MAX;
        for(int i = 0 ; i < arr.size()-1 ; i++){
            minSum = min(minSum ,abs(arr[i] - arr[i+1]));
        }
        for(int i = 0 ; i < arr.size()-1 ; i++){
            vector<int> v(2);
            if(abs(arr[i] - arr[i+1]) == minSum){
                v[0] = arr[i];
                v[1] = arr[i + 1];
                ans.push_back(v);
            }

        }
        return ans;
    }
};