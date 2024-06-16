class Solution {
public:
    bool dfs(int node,vector<int>&vis,stack<int>&s,vector<vector<int>>& adj,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        // cout<<node<<"  "<<endl;
        for(auto it:adj[node]){
            // cout<<it;
            if(vis[it]==-1){
                if(dfs(it,vis,s,adj,pathvis)){
                    return true;
                }
                
            }
            else if(pathvis[it]==1) return true;

        }
        pathvis[node]=-1;
        s.push(node);
        return false;
    }
    vector<int> findOrder(int a, vector<vector<int>>& b) {
        vector<vector<int>>adj(a+1);
        vector<int>pathvis(a,-1);
        int n=b.size();  
        for(int i=0;i<n;i++){
           adj[b[i][1]].push_back(b[i][0]);
        }
        
        vector<int>vis(a,-1);
        stack<int>st;
        for(int i=0;i<a;i++){
            if(vis[i]==-1 ){
                // cout<<i<<endl;
                if(dfs(i,vis,st,adj,pathvis)){
                    return {};
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};