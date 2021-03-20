class UndergroundSystem {
    unordered_map<int,pair<string,int>>m;
    unordered_map<string,unordered_map<string,pair<double,int>>>travel;
public:
    UndergroundSystem() {
        m.clear();
        travel.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int>p=m[id];
           
        if(travel[p.first].find(stationName)==travel[p.first].end())
        {
            travel[p.first][stationName]={t-p.second,1};
        }
        else
        {
            travel[p.first][stationName].first+=t-p.second;
            travel[p.first][stationName].second+=1;
            //cout<<travel[p.first][stationName].first<<" "<<travel[p.first][stationName].second<<endl;
        }
          
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<double,int>p=travel[startStation][endStation];
        return p.first/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
