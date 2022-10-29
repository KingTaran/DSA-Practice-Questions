class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
    long long  res = 1; 
        for(long long  i =  1 ; i<= 2*n ; i++){
            res = (res * i)  ; 
            if(i %2 == 0){
                res = res /2; 
            }
            res = res%mod ; 
        }
        return res%mod   ; 
        
    }
};