class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int i,j,n=nums.size();
        
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0]=1;
        for(i=1;i<n;++i)
        {
            dp[i][0]=1;
            for(j=i-1;j>=0;--j)
            {
                if(dp[j][1]==0)
                {
                    if(nums[j]>nums[i] && dp[i][0]<1+dp[j][0])
                    {
                        dp[i][0]=1+dp[j][0];
                        dp[i][1]=-1;
                    }
                    else if(nums[j]<nums[i] && dp[i][0]<1+dp[j][0])
                    {
                        dp[i][0]=1+dp[j][0];
                        dp[i][1]=1;
                    }
                }
                else if(dp[j][1]==-1 && nums[i]>nums[j] && dp[i][0]<1+dp[j][0])
                {
                    dp[i][0]=1+dp[j][0];
                    dp[i][1]=1;
                }
                else if(nums[i]<nums[j] && dp[j][1]==1 && dp[i][0]<1+dp[j][0])
                {
                    dp[i][0]=1+dp[j][0];
                    dp[i][1]=-1;
                }
            }
        }
        int len=0;
        for(i=0;i<n;++i)
        {
            len=max(len,dp[i][0]);
        }
        return len;
    }
};
/* Time complexity : O(n^2)
   Space complexity : O(n)
 */