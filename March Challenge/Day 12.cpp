/* 
    To calculate the power value
*/
long long int binPow(int k){
    long long int res=1,val=2;
    while(k)
    {
        if(k&1)
        {
            res*=val;
            
        }
        k>>=1;
        val*=val;
    }
    return res;
}
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long int i,j,n=s.size(),val=binPow(k),num=0,cnt=1;
        if(n-k+1<val)
        {
            return 0;
        }
        vector<bool>v(val,false);
        for(i=0;i<k;++i)
        {   num<<=1;
            if(s[i]=='1')
            {
                num+=1;
            }
            
           
        }
        v[num]=true;
        for(i=1;i<=n-k;++i)
        {   
            if(s[i-1]=='1')
            {
                num=num-(val/2);
                
            }
            num<<=1;
            if(s[i+k-1]=='1')
            {
                num+=1;
            }
            
            if(!v[num])
            {   
                v[num]=true;
                ++cnt;
                
            }
            
           
        }
        
        return cnt==val;
        
    }
};

/* 
 Time complexity : O(n-k+1)
 Space complexity: O(2^k)
 */