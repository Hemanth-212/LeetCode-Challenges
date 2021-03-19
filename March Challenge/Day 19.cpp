/* Using BFS checking if
   we can visit every node or rooms
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        unordered_set<int>visited;
        int i,j,n=rooms.size();
        q.push(0);
        
        while(q.size())
        {
            int ver=q.front();
            q.pop();
            visited.insert(ver);
            if(visited.size()==n)
            {
                return true;
            }
            for(int t:rooms[ver])
            {
                if(visited.find(t)==visited.end())
                {
                    visited.insert(t);
                    q.push(t);
                }
            }
            
        }
        return false;
        
        
    }
};