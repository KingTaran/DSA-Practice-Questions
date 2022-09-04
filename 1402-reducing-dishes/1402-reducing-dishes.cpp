class Solution {
public:
    vector<vector<int>>dp; 
    int LIS(vector<int>  &arr, int i, int n,  int x  )
{
	// Base case: if nothing is remaining
	if (i == n)
		return 0;

	// case 1: exclude the current element and process the
	// remaining elements
        if(dp[i][x] != -1){
            return dp[i][x] ; 
        }
	int exclude = LIS(arr, i + 1, n ,x );

	// case 2: include the current element if it is greater
	// than previous element in LIS
	int include = arr[i]*x + LIS(arr, i + 1, n , x + 1);

	// return maximum of above two choices
	return dp[i][x] =  max(include, exclude);
}
    int maxSatisfaction(vector<int>& satisfaction) {
       int n = satisfaction.size(); 
        dp.resize(n  , vector<int>(n + 1 , -1)); 
        sort(satisfaction.begin() , satisfaction.end());
        return LIS(satisfaction ,  0,satisfaction.size()  , 1   ); 
    }
};