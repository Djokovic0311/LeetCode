class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<pair<int,int>>jobs;
        
        int d_size = difficulty.size();
        for(int i=0;i<d_size;i++)
            jobs.push_back(make_pair(difficulty[i],profit[i]));
        
        sort(jobs.begin(),jobs.end());
        
        sort(worker.begin(),worker.end());
        
        int w_size = worker.size();
        int maxProfit = 0;
        int cprofit = 0;
        int cjob = 0;
        
        for(int i=0;i<w_size;i++)
        {

            while(cjob<d_size && jobs[cjob].first<=worker[i])
            {
                cprofit = max(cprofit,jobs[cjob].second);
                cjob++;
            }
            
            maxProfit+= cprofit;
        }
        
        return maxProfit;        
    }
};