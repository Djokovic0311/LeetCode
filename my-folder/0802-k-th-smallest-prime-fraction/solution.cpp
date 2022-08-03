typedef pair<int,int> pr;
class Solution {
public:
    class Compare
    {
        public:
        bool operator() (const pr &p1, const pr &p2)
        {
            if(p1.first*p2.second < p1.second*p2.first){
                return 1;
            }
            return 0;
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n =  arr.size();
        priority_queue<pr,vector<pr>, Compare> pq;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                pq.push({arr[i],arr[j]});
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return vector<int>{pq.top().first,pq.top().second};
    }
};
