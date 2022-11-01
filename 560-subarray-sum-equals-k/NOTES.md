// Brute force
//         int n = nums.size();
//         int count= 0 ;
//         for(int i = 0 ; i< n ; i++){
//             for(int j = i   ; j <n    ; j ++){
//             int subarray_sum = 0 ;
//                 for(int k = i ; k <= j ; k++ ){
//                      subarray_sum += nums[k] ;
//                  }
//                 // cout<< subarray_sum <<" ";
//           if(subarray_sum == k ){
//                 count ++;
//             }
//             }
//         }
//         return count ;