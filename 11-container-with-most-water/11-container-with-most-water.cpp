class Solution {
public:
    // FUCKING OPTIMIZATION 
    int maxArea(vector<int>& height) {
        
        
        int n = height.size(); 
        int i = 0 , j = n-1;
        int res = 0 ; 
        while(i < j ){
            res = max(res , min(height[i] , height[j]) * (j-i) ); 
            if(height[i] > height[j]){
                j--; 
            }
            else{
                i++; 
            }
        }
        return res; 
    }
};



 // BRUTE FORCE : 
// int maxArea(vector<int>& height) {
//         if(height.size() == 2){
//             return min(height[0] , height[1]); 
//         }
//      int x  = INT_MIN ;
//         int y = INT_MIN ; 
//         int max_water_stored = INT_MIN; 
//         int r = 0 ; 
//         for(int i = 0 ; i < height.size()-1 ; i++){
//              x = height[i]; 
//             y = INT_MIN ; 
//             for(int j = i + 1 ; j <height.size(); j ++){
//                 max_water_stored = max(max_water_stored , min(height[i] , height[j] )* (j - i)); 
               
//             }
            
//         }
//         return max_water_stored ; 
//     }