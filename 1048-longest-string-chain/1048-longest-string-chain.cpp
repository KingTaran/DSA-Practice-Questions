class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const std::string& first, const std::string& second)
	{
        return first.size() < second.size();
	});
        int res = -1 ; 
        map<string , int> m ; 
        for(auto  word : words){
            int longest = 0 ; 
            for(int i = 0 ; i <word.length(); i ++ ){
                string sub = word.substr(0 , i ) + word.substr(i + 1); 
                longest = max(longest ,  m[sub] + 1 ); 
                cout<< sub <<" "; 
            }
            m[word] = longest ; 
            res = max(res, longest ); 
         
        }
        return res ; 
    }
};