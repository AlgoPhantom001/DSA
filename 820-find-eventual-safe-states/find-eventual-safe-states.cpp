class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> safe(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(graph[i].size()==0) safe[i]=1;

        }

        for(int i=0;i<n;i++){
            dfs(i ,graph,safe,vis);

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;

        
    }

    void dfs(int node ,vector<vector<int>>& graph,vector<int> &safe,vector<int> &vis ){
        vis[node]=1;

        int s=graph[node].size();
        int count=0;

        for(auto adjnode : graph[node]){
            if(safe[adjnode]==1 && vis[adjnode]==1){
                count++;
                continue;
            }
            if(vis[adjnode]!=1){
                dfs(adjnode,graph,safe,vis);
            }
            if(safe[adjnode]==1)count++;



        }
        if(count==s) safe[node]=1;

    }
};