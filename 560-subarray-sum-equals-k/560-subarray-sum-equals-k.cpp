class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int , int> m ;
        m[0] ++;
        int cum_sum = 0 ; 
        int count =  0;
        int n = nums.size(); 
        for(int i = 0 ; i< n ; i++){
            cum_sum += nums[i]; 
            count += m[ cum_sum - k ]; 
            m[cum_sum ]++; 
        }
        return count ; 
    }
};