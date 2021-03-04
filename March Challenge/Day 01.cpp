class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int i,n=candyType.size();
        
        unordered_set<int>st;
        
        for(i=0;i<n;++i)
        {
            st.insert(candyType[i]);
        }
        
        n>>=1;
       
        return n>=st.size()?st.size():n;
    }
};