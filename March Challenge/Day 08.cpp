bool isPalindrome(string st){
    int i=0,j=st.size()-1;
    while(i<j)
    {
        if(st[i]!=st[j])return 0;
        ++i;
        --j;
    }
    return 1;
}
class Solution {
public:
    int removePalindromeSub(string s) {
        if(!s.size())
        {
            return 0;
        }
        else if(isPalindrome(s))
        {
            return 1;
        }
        else
        {
            return 2;
        }
        
    }
};