class Solution {
public:
    bool divisorGame(int n) {
        if(n== 0 ){
            return 0 ; 
        }
        if(n==1){
            return 0 ; 
        }
        if(n % 2 == 0 ){
            return  1; 
        }
        else{
            return 0 ; 
        }
    }
};