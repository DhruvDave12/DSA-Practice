#include <bits/stdc++.h>
using namespace std;

bool flipMatrix(vector<vector<int>> &vec, int r, int c){
	if(vec[r][c] == 1){
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(vec[i][j] == 0) vec[i][j] = 1;
                else if(vec[i][j] == 1) vec[i][j] = 0;
			}
		}
		return true;
	}
	return false;
}

int minCount(vector<vector<int>> &vec){
	int x = vec.size() - 1;
	int y = vec[0].size() - 1;
	int minFlips = 0;
	while(x >= 0 && y >= 0){
		minFlips += flipMatrix(vec,x,y);
		if(x != y){
			minFlips += flipMatrix(vec,y,x);
		}

		if(x > 0){
			x--;
		} else {
			y--;
			x = y;
		}
	}

	return minFlips;
}

int main() {
	int n;
	cin>>n;

	vector<vector<int>> vec(n, vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>vec[i][j];
		}
	}

	int ans = minCount(vec);

	cout<<ans<<"\n";

	return 0;

}
