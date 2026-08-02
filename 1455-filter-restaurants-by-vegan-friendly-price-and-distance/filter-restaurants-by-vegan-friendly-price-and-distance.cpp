class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> v;
        if(veganFriendly == 1){
            for(int i = 0 ; i < restaurants.size() ; i++){
                if(restaurants[i][2] == 1 && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                    v.push_back(make_pair(restaurants[i][0] , restaurants[i][1]));

                }
            }
        }
        else{
            for(int i = 0 ; i < restaurants.size() ; i++){
                if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                    v.push_back(make_pair(restaurants[i][0] , restaurants[i][1]));

                }
            }
        }
        sort(v.begin(), v.end(), [](
            const pair<int,int>& a, const pair<int,int>& b
        ){
            if(a.second == b.second){
                return a.first>b.first;
            }
            return a.second>b.second;
        });
        vector<int> ans;
        for(int i = 0 ; i < v.size() ; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};