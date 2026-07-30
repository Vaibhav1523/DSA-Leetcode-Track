class Solution {
public:
int f(int ind, int buy, vector<int> &price, int n, int cap,vector<vector<vector<int>>> &dp){
        n = price.size();
        if(cap == 0) return 0;
        if(ind == n) return 0;
        long profit = 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
            profit = max(-price[ind] + f(ind+1, 0, price,n,cap,dp), 0 + f(ind+1, 1,price,n,cap,dp));
        }
        else{
            profit = max(price[ind] + f(ind+1, 1,price,n,cap-1,dp), 0+ f(ind+1, 0,price,n,cap,dp));
        }
        return dp[ind][buy][cap] = profit;


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,prices,n,2,dp);
    }
};