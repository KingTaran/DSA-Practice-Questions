class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); 
        int countone = 0 ; 
        int countwo = 0  ; 
        int countthree = 0 ; 
        for(int i = 0 ; i< n ; i++){
            if(nums[i] == 0 ){
                countone ++; 
            }
            else if(nums[i] == 1){
                countwo ++ ; 
            }
            else{
                countthree ++; 
            }
        }
        int i = 0 ; 
        while(i < n ){
            while(countone != 0 )
            {
                nums[i] = 0; 
                i++ ; 
                countone --; 
            }
            while(countwo != 0 ){
                nums[i] = 1;
                i++; 
                countwo--; 
            }
        while(countthree != 0 ){
            nums[i] = 2;
            i++; 
            countthree --; 
        }
            
        }
        return  ;
        
        
    }
};