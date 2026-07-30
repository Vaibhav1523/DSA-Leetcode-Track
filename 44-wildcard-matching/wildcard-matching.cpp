class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(j>=0 && i<0){
            for(int l = 0; l<=j; l++){
                if(p[l] != '*') return false;
            }
        return true;
        }
        if(i>=0 && j<0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '?' || s[i] == p[j]) return dp[i][j] = f(i-1, j-1, s,p,dp);
        if(p[j] == '*'){
            return dp[i][j] = f(i, j-1, s,p,dp) | f(i-1,j,s,p,dp);
        } 
        return false;

    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1,m-1,s,p,dp);
    }
};