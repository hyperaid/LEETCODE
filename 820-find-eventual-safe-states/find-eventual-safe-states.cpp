class Solution {
public:
    bool check(int node,vector<int>&pathvis,vector<int>&vis,vector<vector<int>>& graph){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(vis[it]==-1){
                if(check(it,pathvis,vis,graph)){
                    return true;
                }
            }
            else if(pathvis[it]==1){
                return true;
            }
        }
        pathvis[node]=-1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>pathvis(n,-1);
        vector<int>vis(n,-1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!check(i,pathvis,vis,graph)){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};