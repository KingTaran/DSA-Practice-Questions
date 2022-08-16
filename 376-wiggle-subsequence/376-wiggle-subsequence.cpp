class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0 ){
            return 0 ; 
        }
        if(nums.size() == 1){
            return 1; 
        }
        int prev_diff = nums[0] - nums[1];
        int n = nums.size(); 
        int diff = 0 ; 
        int count = prev_diff != 0 ? 2 : 1; 
        for(int i = 2 ; i< n ; i++){
            diff= nums[i-1] -nums[i] ; 
            if(prev_diff <= 0 && diff > 0) {
                count ++; 
                prev_diff= diff ; 
            } 
            else if(prev_diff >= 0 && diff < 0 ){
                count ++; 
                prev_diff = diff; 
            } 
        }
        return count ; 
        
        
     }
};