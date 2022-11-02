class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int ,int > m ; 
        int n = nums.size() / 2; 
        for(int i = 0 ; i< nums.size() ; i++){
            m[nums[i]]++; 
        }
        for(auto x : m  ){
            if(x.second > n ){
                return x.first ; 
            }
        }
        return -1; 
    }
};