class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     int inc =  0 ; 
     int ecl = 0 ; 
        int n = nums.size() ; 
        int count[10001] ; 
    fill(count , count + 10001 ,  0 ) ; 
        for(int i = 0 ; i<n ; i++){
            count[nums[i]] ++  ; 
        }
        for(int i = 0 ; i<= 10000 ; i++){
            int ni = ecl  + count[i] * i ; 
            int ne = max(ecl , inc) ; 
            inc= ni ; 
            ecl  = ne; 
        }
        
        return max(inc , ecl ); 
        
    }
};