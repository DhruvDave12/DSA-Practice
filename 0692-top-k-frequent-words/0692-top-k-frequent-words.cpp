class Solution {
    class comparator {
        public:
        bool operator()(const pair<int,string>& a,const pair<int,string>& b) const {
            if(a.first == b.first){
                // sort the string lexicographically and return
                int x = a.second.compare(b.second);
                
                // it means a is lexicographically greater than b so return true as we need                    to swap it
                return x>0;
            }
            
            // it shows b is bigger than a so we need to swap it so return true
            return a.first<b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>,comparator> pq;
        map<string,int> mp;
        for(auto it: words) mp[it]++;
        for(auto it: mp) pq.push({it.second,it.first});
        
        int i = 0;
        vector<string> ans;
        while(i < k && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        return ans;
        
    }
};