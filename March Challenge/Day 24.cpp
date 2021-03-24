class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        int i,j,n=A.size();
        vector<int>v(n,-1),temp;
        for(i=0;i<n;++i)
        {
            pq.push(A[i]);
            p.push({B[i],i});
        }
        while(pq.size())
        {
            pair<int,int>t=p.top();
            p.pop();
            while(pq.size() && t.first>=pq.top())
            {
                temp.push_back(pq.top());
                pq.pop();
            }
            if(pq.size())
            {
                v[t.second]=pq.top();
                pq.pop();
            }
        }
        j=0;
        for(i=0;i<n;++i)
        {
            if(v[i]==-1)
            {
                v[i]=temp[j++];
            }
        }
        return v;
    }
};
/* Time complexity : O(nlogn)
   Space complexity : O(n)
 */