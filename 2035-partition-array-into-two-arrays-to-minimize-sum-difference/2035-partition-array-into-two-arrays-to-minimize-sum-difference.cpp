class Solution {
public:
    std::function<void (vector<vector<int>>&, int, int, int, int)> dp;
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        // both the 2d array refer to sum of the parts of the first
        // half array, one has k elements from left of nums,
        // the other part has n-k elements from the right of nums
        vector<vector<int>> leftKsums (n+1, vector<int>());
        vector<vector<int>> rightKsums (n+1, vector<int>());
        
        // lambda to recursively calculate all sums
        // NOTE: [&] in lamda will capture local variables by reference
        // so that we don't need to pass them in the arguments
		// e.g., 'n' is captured by the lamda from the scope
        //
        // for each subproblem, we can calculate the sum 
        // 1. either by taking the current element
        // 2. or by skipping the current element
        dp = [&] (vector<vector<int>> &Ksums, int sum, int len, int start, int index) {
            // the scan is complete
            if (index-start >= n) {
                // register the sum corresponding to the length
                Ksums[len].push_back(sum);
                return;
            }
            
            // take the current element and move to the next index
            dp(Ksums, sum+nums[index], len+1, start, index+1);
            
            // skip the current element and move ahead
            dp(Ksums, sum, len, start, index+1);
        };
        
        dp(leftKsums, 0, 0, 0, 0);
        dp(rightKsums, 0, 0, n, n);
        
        // the target sum for each half array is total / 2
        int total = 0;
        int target = 0;
        
        for (int& num: nums)
            total += num;
        
        target = total / 2;
        
        // sort the subarray on which binary search (lower_bound) will be performed
		for (vector<int>& right: rightKsums)
			std::sort(right.begin(), right.end());
        
        int ans = INT_MAX;
        
        // loop through all possible sums corresponding to various length k[0... n] on left part
        for (int i=0; i<=n; i++) {
            // find the closest match on the right part corresponding to length n-k
            for (int& leftHalfSum: leftKsums[i]) {
                int key = target - leftHalfSum;
                std::vector<int>::iterator it = std::lower_bound(rightKsums[n-i].begin(), rightKsums[n-i].end(), key);
                if (it == rightKsums[n-i].end())
                    it--;
                
                int rightHalfSum = *it;
                // leftSum indicates the sum of the left half array
                // same is true for rightSum
                int leftSum = leftHalfSum + rightHalfSum;
                int rightSum = total - leftSum;
                int diff = std::abs(leftSum-rightSum);
                
				// since the minimum absolute difference cannot be
				// less than zero
                if (diff == 0)
                    return 0;
                
                if (diff < ans) 
                    ans = diff;

            }
        }
        
        return ans;
    }
};