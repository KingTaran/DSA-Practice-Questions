class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     int inc =  0 ; 
     int ecl = 0 ; 
        int N = *max_element(nums.begin() , nums.end()); 
        int n = nums.size() ; 
        int count[N+1] ; 
    fill(count , count + N+1 ,  0 ) ; 
        for(int i = 0 ; i<n ; i++){
            count[nums[i]] ++  ; 
        }
        for(int i = 0 ; i<= N ; i++){
            int ni = ecl  + count[i] * i ; 
            int ne = max(ecl , inc) ; 
            inc= ni ; 
            ecl  = ne; 
        }
        
        return max(inc , ecl ); 
        
    }
};