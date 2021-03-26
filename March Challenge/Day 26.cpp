class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string>v;
        vector<int>freq(26,0);
        int i,j;
        for(i=0;i<B.size();++i)
        {   vector<int>temp(26,0);
        
            for(j=0;j<B[i].size();++j)
            {
                int ind=B[i][j]-'a';
                ++temp[ind];
                freq[ind]=max(freq[ind],temp[ind]);
            }
        
        }
        for(i=0;i<A.size();++i)
        {
            vector<int>temp(26,0);
            for(j=0;j<A[i].size();++j)
            {
                ++temp[int(A[i][j]-'a')];
            }
            int f=1;
            for(int it=0;it<26;++it)
            {
                if(freq[it] && temp[it]<freq[it])
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                v.push_back(A[i]);
            }
        }
        return v;
    }
};