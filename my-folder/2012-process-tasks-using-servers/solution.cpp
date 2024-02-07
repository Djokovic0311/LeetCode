class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = tasks.size();
        vector<int> res(n);
        int time = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available, notavailable;
        for(int i=0;i<servers.size();i++)
        {
            available.push({servers[i],i});
        }
        for(int i=0;i<n;i++)
        {
            time = max(time,i);
            if(available.empty() && notavailable.top().first > time)
            {
                time = notavailable.top().first;
            }
            while(!notavailable.empty() && notavailable.top().first <= time)
            {
                int idx = notavailable.top().second;
                available.push({servers[idx],idx});
                notavailable.pop();
            }
            if(!available.empty())
            {
                int idx = available.top().second;
                res[i] = idx;
                available.pop();
                notavailable.push({time+tasks[i], idx});
            }
        }        
        return res;
    }
};
