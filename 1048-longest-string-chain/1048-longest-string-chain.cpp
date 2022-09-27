class Solution {
public:
    static bool comp(string &s1 , string &s2){
        return s2.length() > s1.length(); 
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , comp ); 
        int res = 0 ; 
        map<string , int> dp ; 
        for(auto word : words ){
            for(int i = 0 ; i< word.size() ; i++){
                string pre = word.substr(0 , i  ) + word.substr(i + 1); 
                dp[word] = max(dp[word] , dp[pre] + 1 ); 
                
            }
            res = max(res , dp[word]) ; 
        }
        return res ; 
    }
};