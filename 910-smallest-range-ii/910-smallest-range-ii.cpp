class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end()); 
        int res = nums[nums.size() -1 ] - nums[0]; 
      for(int i = 0 ; i< nums.size()-1 ; i++){
         
              int mn = min(nums[0] + k , nums[i+1] - k ); 
              int mx = max(nums[nums.size() -1] - k , nums[i] + k ); 
              res = min(res , mx - mn) ;
              
          
          
      }   
        return res ; 
        
        
    }
};