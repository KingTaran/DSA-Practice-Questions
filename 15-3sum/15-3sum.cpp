// Yeh Question ne toh jaan hi nikal di 
//basic equation ka khel tha x + y + z = 0 
// x + y = z 
// basically find -z using two pointer technique


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size() ; 
        vector<vector<int>> v; 
        set<vector<int>> s; 
        sort(nums.begin() , nums.end()); 
        for(int i = 0 ; i< n-1 ; i++){
            int x = -nums[i] ;
            int j = i + 1 , k = n-1;
            while(j < k ){
                if((nums[j] + nums[k]) == x ) {
                    s.insert({nums[i] , nums[j] , nums[k]}); 
                    j ++ , k --; 
                }
                else if((nums[j] + nums[k] ) > x ) {
                    k--; 
                }
                else{
                    j++; 
                }
                
            }
            
        }
        for(auto x : s){
            v.push_back(x); 
        }
        return v; 
    }
};