class Solution {
public:
   vector<vector<int>> dist;

    bool check(vector<vector<int>> &dist, int limit)
    {
        int n = dist.size();

        if(dist[0][0] < limit)
            return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            if(r==n-1 && c==n-1)
                return true;

            for(auto &d:dir)
            {
                int nr = r+d[0];
                int nc = c+d[1];

                if(nr<0 || nc<0 || nr>=n || nc>=n)
                    continue;

                if(vis[nr][nc])
                    continue;

                if(dist[nr][nc] < limit)
                    continue;

                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        dist.assign(n, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();

            for(auto &d:dir)
            {
                int nr=r+d[0];
                int nc=c+d[1];

                if(nr<0 || nc<0 || nr>=n || nc>=n)
                    continue;

                if(dist[nr][nc]!=INT_MAX)
                    continue;

                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }

        int low=0;
        int high=2*n;

        int ans=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(dist,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return ans;

    }
};