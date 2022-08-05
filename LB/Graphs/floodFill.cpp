#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillVector(vector<vector<int>>&image, int sr, int sc, int color, vector<vector<bool>>&visited, int currColor){
        // if going out of boundaries then return 
        if(sr >= image.size() || sr < 0) return;
        if(sc >= image[sr].size() || sc < 0) return;

        // If the image color found return
        if(image[sr][sc] == color) return;

        // int oldColor = image[sr][sc];
        image[sr][sc] = color;
        visited[sr][sc] = true;

        if(sr+1 <image.size() && sr+1 >= 0 && image[sr+1][sc] == currColor && !visited[sr+1][sc]){
            fillVector(image,sr+1,sc,color,visited,currColor);
        }
        if(sc+1 < image[sr].size() && sc+1 >= 0 && image[sr][sc+1] == currColor && !visited[sr][sc+1]){
            fillVector(image,sr,sc+1,color,visited,currColor);
        }
        if(sr-1 < image.size() && sr-1 >= 0 &&image[sr-1][sc] == currColor && !visited[sr-1][sc]){
            fillVector(image,sr-1,sc,color,visited,currColor);
        }
        if(sc-1 < image[sr].size() && sc-1 >= 0 && image[sr][sc-1] == currColor && !visited[sr][sc-1]){
            fillVector(image,sr,sc-1,color,visited,currColor);
        }

        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        fillVector(image,sr,sc,color,visited,image[sr][sc]);
        return image;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr=1, sc=1;
    int color = 2;

    Solution s;
    image = s.floodFill(image,sr,sc,color);
    
    for(int i=0;i<image.size(); i++){
        for(int j=0; j<image[i].size(); j++){
            cout<<image[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}