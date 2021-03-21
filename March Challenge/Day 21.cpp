class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(!(N&(N-1)))
        {
            return true;
        }
        long long int i,j,val,d1,d2,f=0;
        d1=int(log10(N))+1;
        vector<int>freq(10,0);
        while(N)
        {
            ++freq[N%10];
            N/=10;
        }
        for(i=0;i<=31;++i)
        {
            val=pow(2,i);
            d2=int(log10(val))+1;
            if(d1==d2)
            {
                vector<int>temp(10,0);
                while(val)
                {
                    ++temp[val%10];
                    val/=10;
                }
                f=1;
                for(j=0;j<10;++j)
                {
                    if(freq[j]!=temp[j])
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                {
                    return true;
                }
            }
            else if(d1<d2)
            {
                break;
            }
            
        }
        return false;
    }
};