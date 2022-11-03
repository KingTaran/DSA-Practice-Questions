class Solution {
public:
      int kadane(vector<int>& arr) {
        int n = arr.size() ; 
       int sum = 0 ; 
      int max_sum = INT_MIN  ; 
      for(int i = 0 ; i< n ; i++){
          sum += arr[i]; 
          if(sum > max_sum ){
              max_sum = sum ; 
          }
          if(sum < 0 ){
              sum = 0 ; 
          }
      }
      return max_sum ; 
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size(); 
        int count = 0 ; 
        int max_subarray_sum = INT_MIN ; 
        for(int i = 0 ; i< n ; i++){
            max_subarray_sum = max(max_subarray_sum , arr[i]);
            if(arr[i] <= 0 )
            {
                count ++; 
            }
        }
        if(count == n ){
            return max_subarray_sum ; 
        }
        
        int normal_kadane = kadane(arr); 
        int sum = 0 ; 
        for(int i = 0 ; i < n ; i++){
            sum += arr[i]; 
            arr[i] *=-1; 
        }
        int circular_kadane  = kadane(arr); 
        int special_kadane = sum + circular_kadane ; 
        return max(special_kadane, normal_kadane ) ; 
        
    }
};