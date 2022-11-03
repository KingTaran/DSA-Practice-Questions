class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
      priority_queue <pair<int, int > > pq; 
        map<int ,int> m ; 
       for(int i = 0 ; i< n;  i ++  ){
           m[nums[i]]++; 
       }
       for(auto x : m ){
           pq.push({x.second , x.first }); 
       } 
      vector<int> res ; 
        while(!pq.empty() && res.size() < k ){
            res.push_back(pq.top().second);
            pq.pop(); 
        }
        return res  ; 
        
    }
};