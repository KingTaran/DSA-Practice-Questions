// This question is based on greedy Algorithm 
// This is Base Questiion for jump game other problems 




class Solution {
public:
    bool canJump(vector<int>& nums) {
     
      int steps =nums[0]; 
        int n = nums.size();
        int new_range = nums[0] ; 
        if(n == 1){
            return 1; 
        }
           if(nums[0] == 0 ){
            return 0 ; 
        }
        for(int i = 1; i  <  n ; i ++){
            if(i == n-1){
                return 1; 
            }
            steps --; 
            new_range = max(new_range , nums[i] + i ); 
            if(new_range <= i ){
             
                return 0 ; 
            }
            steps = new_range  - i;
        }
        return 0 ;  
     }
};