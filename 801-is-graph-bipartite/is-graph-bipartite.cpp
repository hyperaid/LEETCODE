class Solution {
public:
    bool check(vector<vector<int>>& graph,int src,vector<int>&vis){
        cout<<src;
        int n=graph.size();
        queue<pair<int,int>>q;
        q.push({src,0});
        vis[src]=0;
        while(!q.empty()){
            int node=q.front().first;
            int colour=q.front().second;
            q.pop();
            for(auto it:graph[node]){
                if(vis[it]==-1){
                    if(colour==0){
                        vis[it]=1;
                        q.push({it,1});
                    }
                    else{
                        vis[it]=0;
                        q.push({it,0});
                    }
                }
                else{
                    if(vis[it]==colour) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(graph[i].size()==0) continue;
                else if(!check(graph,i,vis)){
                    return false;
                }
            }
        }
        return true;   
        
    }
};