class Solution {
public:
    bool dfs(int node,vector<int>&col,vector<vector<int>>& graph,int colour){
        cout<<node;
        col[node]=colour;
        for(auto it:graph[node]){
            if(col[it]==-1){
                if(!dfs(it,col,graph,!colour)){
                    return 0;
                }
            }
            else{
                if(col[it]==colour){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1 && graph[i].size()>0){
                if(!dfs(i,col,graph,0)){
                    return false;
                }
            }
        }
        return true;
    }
};