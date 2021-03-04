class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int sum=0,i,n=nums.size();
        for(i=0;i<n;++i)
        {
            sum+=nums[i];
        }
        long long int val=((n*(n+1))/2)-sum;
        return val;
    }
};