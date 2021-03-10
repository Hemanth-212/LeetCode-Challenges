class Solution {
public:
    string intToRoman(int n) {
        string M[4] = {"","M","MM","MMM"};
        string C[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string X[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string I[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return M[n/1000]+C[(n/100)%10]+X[(n/10)%10]+I[n%10];
        
    }
};