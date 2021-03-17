class Solution {
    double r;
    double xCenter;
    double yCenter;
    
    
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        xCenter=x_center;
        yCenter=y_center;
    }
    
    vector<double> randPoint() {
        vector<double>v(2);
        double ang=2*3.141592653589*(double(rand())/RAND_MAX);
        double d=r*sqrt((double(rand())/RAND_MAX));
        
        v[0]=xCenter+d*cos(ang);
        v[1]=yCenter+d*sin(ang);
        return v;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */