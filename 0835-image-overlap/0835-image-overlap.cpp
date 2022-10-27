class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // find the pattern of image 2 in image 1 if it does exist and if it does then we are going to
        // find the difference of the index or number of movies we will need to make it work
        // else if such pattern doesnt exist then we return 0
        
        vector<pair<int,int>> vec1;
        vector<pair<int,int>> vec2;
        
        for(int i=0; i<img1.size(); i++){
            for(int j=0; j<img2[i].size(); j++){
                if(img1[i][j] == 1){
                    vec1.push_back({i,j});        
                }    
                
                if(img2[i][j] == 1){
                    vec2.push_back({i,j});
                }
            }
        }
        
        
        map<pair<int,int>, int> mp;
        
        int ans = 0;
        
        for(auto i: vec1){
            for(auto j: vec2){
                int x = j.first-i.first;
                int y = j.second-i.second;
                mp[{x,y}]++;
                
                ans = max(ans, mp[{x,y}]);
            }
        }
        
        
        return ans;
        
    }
};