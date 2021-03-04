class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long int i,n=nums.size();
        long long int sum=0,sqrSum=0;
        vector<int>v(2);
        for(i=0;i<n;++i)
        {
            sum+=nums[i];
            sqrSum+=nums[i]*nums[i];
        }
        int x,y;
        /* Equations obtained are 
            1. x-y=sum - (n*(n+1))/2 
            2. x^2 - y^2 =sqrSum - (n*(n+1)*(2*n+1))/6 
             
            Where x = repeated number 
                  y = missing number 
            Then by evaluation values of x and y can be obtained */
        
        sum-=(n*(n+1))/2;
        sqrSum-=(n*(n+1)*(2*n+1))/6;
        sqrSum/=sum;
        x=(sqrSum+sum)/2;
        y=x-sum;
        v[0]=x;
        v[1]=y;
        return v;
        
        
    }
};