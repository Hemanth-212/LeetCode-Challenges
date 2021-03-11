/* 
    Recursion approach 
*/
int solve(vector<int>&coins,int n,int &amount,int sum){
    if(sum==amount)return 0;
    if(sum>amount)return INT_MAX-1;
    if(!n)return INT_MAX-1;
    return min(1+solve(coins,n,amount,sum+coins[n-1]),solve(coins,n-1,amount,sum));
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        /* 
            Dynamic Programming approach 
        */
        int i,j,n=coins.size();
        int dp[n+1][amount+1];
        for(i=1;i<=n;++i)dp[i][0]=0;
        for(i=0;i<=amount;++i)dp[0][i]=INT_MAX-1;
        for(i=1;i<=n;++i){
            for(j=1;j<=amount;++j){
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
      
        
    }
};