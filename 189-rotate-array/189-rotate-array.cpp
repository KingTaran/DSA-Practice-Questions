class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> v(n , 0 ); 
        for(int i = 0 ; i< n ; i++) {
            v[i] =  nums[i]; 
        }  
        for(int i = 0 ; i< n ; i++){
            nums[(i+k)%n] = v[i]; 
        }
    }
};