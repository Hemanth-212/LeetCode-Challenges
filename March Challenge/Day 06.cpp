bool comparator(string st1,string st2){
    return st1.size()<st2.size();
}

//Function that returns true if string t is a suffix of string s or else false
bool isSuffix(string s,string t){
    int i=1;
    while(i<=t.size())
    {
        if(s[s.size()-i]!=t[t.size()-i])
        {
            return 0;
        }
        ++i;
    }
    return 1;
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        /* 
            sort the strings according to their size
        */
        sort(words.begin(),words.end(),comparator);
        
        vector<string>temp; // contains the strings that aren't suffix to any other strings
        temp.push_back(words[words.size()-1]);
        int i,j,n=words.size(),len=0;
        for(i=n-2;i>=0;--i)
        {   int f=0;
            for(j=0;j<temp.size();++j)
            {
                if(isSuffix(temp[j],words[i]))  // check if the current string is suffix to strings having larger size
                {
                    f=1;
                    break;
                }
            }
            if(!f)
            {
                temp.push_back(words[i]);
            }
        }
        
        /* 
            Finally the length of shortedt encoding string 
        */
        for(i=0;i<temp.size();++i)
        {
            len+=temp[i].size()+1;
        }
        return len;
    }
};
/*  Time complexity : O(w*n^2) 
    Space complexity : O(n)
     where n= no of strings
           w= length of longest string 
           
           
    Note : Not an efficient solution 
           Efficient solution is by using Trie 
*/
           
 
