class Solution {
public:
    static bool cmp1(const vector<int> &a, const vector<int> &b)
    {
        return a[0] > b[0];
    }
    bool isvalid(int row, int col, int m, int n) {
        if(row < m && row >= 0 && col < n && col >= 0) return true;
        return false;
    }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>ans,res;
        // visited array
        vector<vector<bool>>seen(m,vector<bool>(n,false));
        // queue for BFS
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        //directions
        vector<vector<int>>dirs={{-1,0},{0,-1},{0,1},{1,0}};
        // distance
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p=q.front();
                    q.pop();
                // already visited cell
                if(seen[p.first][p.second])
                    continue;
                // found wall
                if(grid[p.first][p.second]==0)
                    continue;
                // make the cell visited ,if visiting first time
                seen[p.first][p.second]=true;
                // if the value is 1 then it is empty cell so first check it
                if(grid[p.first][p.second]!=1){
                    int val=grid[p.first][p.second];
                    // cell value should be in the range of price,if yes then push it to array or min-heap
                    if(val>=price[0] && val<=price[1])
                       res.push_back({dist,val,p.first,p.second});
                }
                // check other cells which you can reach from current cell
                for(auto & dir:dirs){
                    int row=p.first+dir[0],col=dir[1]+p.second;
                    if(row>=0 && row<m && col>=0 && col<n)
                        q.push({row,col});
                }      
            }
            dist++;
        }
        // sort the array, if you have used min-heap,then obviously there is no need
        sort(res.begin(),res.end());
        // first k values or whole vector,whatever is minimum
        for(int i=0;i<min(int(k),int(res.size()));i++)
            ans.push_back({res[i][2],res[i][3]});
        return ans;
        
    }
};
