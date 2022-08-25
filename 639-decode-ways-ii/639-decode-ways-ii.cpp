class Solution {
public:

	// TIME COMPLEXITY:- O(N)
	// SPACE COMPLEXITY:- O(N)
    
    #define ll long long
    #define MOD 1000000007
    // dp[i] = number of ways to decode the substring(0,i-1)
    int numDecodings(string s) {
        vector<ll> dp(s.length()+1,0);
        if(s[0]=='0') // no ways to decode
            return 0;
        dp[0] = 1; // base case
        dp[1] = (s[0]=='*')?9:1;
        for(ll i=2;i<=s.length();i++){
            char curr = s[i-1],prev = s[i-2];
            // introducing first barrier like (12)(3)
            if(curr=='*')
                dp[i] = (dp[i]+(9*dp[i-1])%MOD)%MOD;
            else if(curr!='0')
                dp[i] = (dp[i]+dp[i-1])%MOD;
            
            // introducing second barrier like (1)(23)
            if(prev=='*'){
                if(curr=='*')
                    dp[i] = (dp[i]+(15*dp[i-2])%MOD)%MOD;
                else if(curr<='6')
                    dp[i] = (dp[i]+(2*dp[i-2])%MOD)%MOD;
                else
                    dp[i] = (dp[i]+dp[i-2])%MOD;
            }
            else if(prev=='1'){
                if(curr=='*')
                    dp[i] = (dp[i]+(9*dp[i-2])%MOD)%MOD;
                else
                    dp[i] = (dp[i]+dp[i-2])%MOD;
            }
            else if(prev=='2'){
                if(curr=='*')
                    dp[i] = (dp[i]+(6*dp[i-2])%MOD)%MOD;
                else if(curr<='6')
                    dp[i] = (dp[i]+dp[i-2])%MOD;
            }
        }
        return dp.back();
    }
};