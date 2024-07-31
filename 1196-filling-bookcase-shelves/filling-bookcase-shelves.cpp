class Solution {
public:
    int solve(vector<vector<int>>& books,int W,int w ,int i,int h,vector<vector<int>>&dp){
        if(i>=books.size()){
            return h;
        }
        if(dp[w][i]!=-1) return dp[w][i];
        int take=INT_MAX;
        int not_take=INT_MAX;

        if(books[i][0]+w<=W){
            take=solve(books,W,w+books[i][0],i+1,max(h,books[i][1]),dp);
        }
        not_take=h+solve(books,W,books[i][0],i+1,books[i][1],dp);

        return  dp[w][i]=min(take,not_take);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return solve(books,shelfWidth,0,0,0,dp);
    }
};