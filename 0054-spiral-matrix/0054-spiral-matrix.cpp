class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int rightLimit = column;
        int leftLimit = 0;
        int topLimit = 0;
        int bottomLimit = row;
        vector<int> vec;
        
        vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(),false));
        
        while(leftLimit <= column/2 && rightLimit >= column/2 && topLimit <= row/2 && bottomLimit >= row/2){
            for(int i=leftLimit; i<rightLimit; i++){
                if(vis[topLimit][i]) continue;
                vec.push_back(matrix[topLimit][i]);
                vis[topLimit][i] = true;
            }    
            topLimit++;
            for(int j=topLimit; j<bottomLimit; j++){
                if(vis[j][rightLimit-1]) continue;
                vec.push_back(matrix[j][rightLimit-1]);
                vis[j][rightLimit-1] = true;
            }
            rightLimit--;
            for(int k=rightLimit-1; k>=leftLimit; k--){
                if(vis[bottomLimit-1][k]) continue;
                vec.push_back(matrix[bottomLimit-1][k]);
                vis[bottomLimit-1][k] = true;
            }
            bottomLimit--;
            for(int l=bottomLimit-1; l>=topLimit; l--){
                if(vis[l][leftLimit]) continue;
                vec.push_back(matrix[l][leftLimit]);
                vis[l][leftLimit] = true;
            }
            leftLimit++;
        }
            
        return vec;
    }
};