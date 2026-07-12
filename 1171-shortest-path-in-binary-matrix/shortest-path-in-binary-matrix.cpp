class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>>  vis(n,vector<int> (n,0));
        queue <pair<pair<int,int>,int>> que;
        vector<vector<int>> dis(n,vector<int> (n,-1));

        
        

        que.push({{0,0},1});
        
        vector<int> nrow=   {0,0,1,-1,1,1,-1,-1};
        vector<int> ncolumn={1,-1,0,0,1,-1,1,-1};

        if(grid[0][0]==1) return -1;

        
        dis[0][0]=1;
        vis[0][0]=1;



        while(!que.empty()){
            int i=que.front().first.first;
            int j=que.front().first.second;
            int dist =que.front().second;

            que.pop();
            
            for(int l=0;l<8;l++){
                int drow= i+nrow[l];
                int dcolumn=j+ncolumn[l];

                if(drow>=0 && drow<n && dcolumn>=0 && dcolumn<n && grid[drow][dcolumn]==0 && vis[drow][dcolumn]==0 ){
                    dis[drow][dcolumn]=dist+1;
                    vis[drow][dcolumn]=1;
                    que.push({{drow,dcolumn},dist+1});
                }
            }

        }
        if( dis[n-1][n-1]==-1)return -1 ;
        return dis[n-1][n-1];





        
    }
};