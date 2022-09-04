class Solution {
public:
    // i : score : age 
     
  
   int func(vector<pair<int,int >> &arr , int n ){
       vector<int> ans(n , 0);  
       int best = 0;   // Store the final answer
        
        // Logic of LIS
        for(int i=0; i<arr.size();i++) {
            ans[i]=arr[i].second; 
            for(int j=0;j<i;j++) {
                if(arr[i].second >= arr[j].second) {
                    ans[i] = max(ans[i], ans[j] + arr[i].second);
                }
            }
            best = max(best, ans[i]);
        }
        
        return best; // Time to celebrate!
   }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // memset(dp , -1 ,sizeof(dp)); 
        vector<pair<int,int>> v ; 
        for(int i = 0 ; i< scores.size() ; i++){
            v.push_back({ages[i] , scores[i]}); 
        }
        sort(v.begin() , v.end()); 
        return func(v ,  v.size()  ) ; 
        
        
    }
};