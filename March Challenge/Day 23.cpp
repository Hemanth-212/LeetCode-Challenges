#define MOD 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int i,j,n=arr.size(),sum,cnt=0;
        vector<int>freq;
        for(i=0;i<n-2;++i)
        {
            freq.assign(101,0);
            for(j=i+1;j<n;++j)
            {
                sum=arr[i]+arr[j];
                if(target-sum>=0 && target-sum<=100)
                {
                    cnt=(cnt+freq[target-sum])%MOD;
                }
                ++freq[arr[j]];
            }
            
        }
        return cnt;
    }
};
/* Time complexity : O(n^2)
   Space complexity : O(n)
 */