class Solution {
public:
    int maxSubArray(vector<int>& arr) {
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
    
    
    
}; 
    
    
    
    
    
//     //Brute-Force
//    /*
//    int max_sum  = INT_MIN ; 
//         for(int i = 0  ; i< n ; i++){
//             for(int j = i ; j< n ; j++){
//                 int sum = 0 ; 
//                 for(int k = i ;  k <= j ; k++){
                    
//                     sum += nums[k];                     
//                     }
//                 max_sum = max(max_sum , sum ) ; 
//             }
//         }
//         return max_sum ;
//         /*