class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size() || arr[start ] < 0){
            return 0; 
        }
        arr[start] *=-1; 
        return !arr[start]  || canReach(arr, start - arr[start]) || canReach(arr , start + arr[start]); 
    }
};