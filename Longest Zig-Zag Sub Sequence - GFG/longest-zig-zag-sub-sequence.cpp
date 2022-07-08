// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int ZigZagMaxLength(vector<int>&nums){
		    if(nums.size() == 1){
		        return 1; 
		    }
		    int prev_diff =  nums[1] - nums[0] ; 
		    int count = prev_diff!= 0? 2 : 1 ; 
		    int diff = 0 ; 
		    for(int i =2 ; i< nums.size() ; i++){
		        diff = nums[i] - nums[i-1] ; 
		        if(prev_diff >= 0 && diff < 0){
		            count ++ ; 
		            prev_diff = diff ; 
		        }
		        else if(prev_diff <= 0 && diff > 0 ){
		            count ++ ; 
		            prev_diff = diff; 
		        }
		    }
		    return count ; 
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends