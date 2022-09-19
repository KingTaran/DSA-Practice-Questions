
// IMPORTANT QUESTION and explaination 


// sum - v[i] Represents the amount of profit that player1 can make 
        // (-) sign is for the diffrence 
        // func(v , i + 1 , j  ,sum - v[i]) represents max profit saamne wala can make offically 
        // similarly 
        // if player 1 chooses last element
        // func(v , i  , j-1 , sum - v[j]) represents max profit saamne wala can make if the player one chooses last element 


class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int sum = 0 ; 
        sum = accumulate(stones.begin() , stones.end() , sum ); 
        
        dp.resize(stones.size() + 1 , vector<int> ( stones.size() + 1 , -1)); 
        int x = func(stones , 0 , stones.size() -1 , sum ); 
        
        // int y = min( func(stones , 1 , stones.size() -1) ,  func(stones , 0 , stones.size() -2)); 
        return x ; 
    }
private : 
    vector<vector<int>> dp ; 
    int func(vector<int> & v ,int  i  , int j , int sum  ){
        if(i == j ){
            return 0 ; 
        }
        if(i > j ){
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
       
        
        int choice1 = sum- v[i] - func(v , i + 1 , j  ,sum - v[i]) ; 
        int choice2 = sum- v[j] - func(v , i  , j-1 , sum - v[j]);  
        return dp[i][j] = max(choice1 , choice2); 
        
        
        
        
    }
};