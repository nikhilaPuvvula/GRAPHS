//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        
        
        int n = grid.size();
        int m = grid[0].size();
        int max = 0;
        int fCount = 0;
        int count=0;
        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        
        /*int k,l,v=0;
        for( k=0;k<n;k++)
        {
            for( l=0;l<m;l++)
            {
                if(grid[k][l]!=0)
                { 
                    v=1;
                    break;
                }
            }
        }
        if(v==0)
          return -1;*/
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)
                {
                    fCount++;
                }
            }
        }
        int crow[4] = {-1,1,0,0};
        int ccol[4] = {0,0,-1,1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            if(t>max)
              max=t;
            q.pop();
            for(int i=0;i<4;i++)
            {   
                int nrow=r+crow[i];
                int ncol = c+ccol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    count++;
                    vis[nrow][ncol]=2;
                }
            }
        }
        if(fCount!=count)
         return -1;
        else
         return max;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends