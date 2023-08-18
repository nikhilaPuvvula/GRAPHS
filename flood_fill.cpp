//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        int visited[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                visited[i][j]=0;
            }
        }
        int color=image[sr][sc];
        image[sr][sc]=newColor;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int nr[4]={0,0,-1,1};
        int nc[4]={1,-1,0,0};
        while(!q.empty())
        {
           int r = q.front().first;
           int c = q.front().second;
           q.pop();
           if(visited[r][c]==0){
               visited[r][c]=1;
           for(int i=0;i<4;i++)
           {   
               
               int r1 = r+nr[i];
               int c1 = c+nc[i];
               if(r1>=0 && r1<n && c1>=0 && c1<m && visited[r1][c1]==0 && image[r1][c1]==color)
               {
                   image[r1][c1]=newColor;
                   q.push({r1,c1});
               }
           }
          }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends