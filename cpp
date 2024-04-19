class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        auto bfs=[&](int r,int c){
            queue<pair<int, int>> q;
            q.push({r,c});
            grid[r][c]='2';
            while (!q.empty()){
                auto [i,j]=q.front();
                q.pop();
                for(auto [dx,dy]:dirs){
                    int x=i+dx;
                    int y=j+dy;
                    if(x<0||x==m||y<0||y==n){
                        continue;
                    }
                    if(grid[x][y]!='1'){
                        continue;
                    }
                    q.push({x,y});
                    grid[x][y]='2'; 
                }
            }
        };
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1'){
                    bfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
