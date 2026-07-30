class Solution {
public:
    int f(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp){
        n = price.size();
        if(ind == n) return 0;
        long profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max(-price[ind] + f(ind+1, 0, price,n,dp), 0 + f(ind+1, 1,price,n,dp));
        }
        else{
            profit = max(price[ind] + f(ind+1, 1,price,n,dp), 0+ f(ind+1, 0,price,n,dp));
        }
        return dp[ind][buy] = profit;


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1, prices,n,dp);
    }
};