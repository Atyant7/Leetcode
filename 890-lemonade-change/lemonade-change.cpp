class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] > 5) return false;
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five == 0) return false;
                five--;
                ten++;
            }
            else if(ten && five){
                ten--; 
                five--;
            }
            else if(five >= 3) five = five - 3;
            else return false;
            
        }
        return true;
    }
};