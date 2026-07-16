class Solution {
public:
    // int is_prime(int a){
    //     for(int i = 2; i <= int(sqrt(a)) ; i++){
    //         if(a % i == 0){
    //             return 0;
    //         }
    //     }
    //     return 1;
    // }
    int countPrimes(int n) {
        if(n == 1 || n == 0) return 0;
        int count = 0;
        vector<int> v(n,1);
        v[0] = 0;
        v[1] = 0;
        for(int i = 2; i * i < n; i++){
            if(v[i]){
                for(int j = i * i; j < n; j += i){
                    v[j] = 0;
                }
            }
        }
        for(int i = 2; i < n; i++){
            if(v[i]) count++;
        }

        return count;
    }
};