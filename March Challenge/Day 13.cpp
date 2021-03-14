#define MOD 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,long long int>m;
        sort(arr.begin(),arr.end());
        long long int total,t,i,j,n=arr.size(),ans=0;
        for(i=0;i<n;++i)
        {
            total=1;
            for(j=0;j<i && arr[j]<=sqrt(arr[i]);++j)
            {   
                if(arr[i]%arr[j]==0)
                {
                    if(arr[j]==arr[i]/arr[j])
                    {
                        total=(total+(m[arr[j]]*m[arr[j]])%MOD)%MOD;
                    }
                    else if(m.find(arr[i]/arr[j])!=m.end())
                    {
                        total=(total+(m[arr[j]]*m[arr[i]/arr[j]]*2)%MOD)%MOD;
                    }
                }
                
            }
            m[arr[i]]=total;
            ans=(ans+total)%MOD;
        }
        return ans;
        
    }
};