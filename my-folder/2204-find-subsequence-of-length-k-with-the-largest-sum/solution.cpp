class Solution {
public:
            typedef pair<int,int> PII;
    static bool cmp1(PII a, PII b){
	        return a.second<b.second;
        }    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> res;
        vector<int> res_;


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > small_queue;
        for(int i=0; i<nums.size(); ++i){
            if(i<k){
                small_queue.push({nums[i],i});
            }
            else{
                if(nums[i]>small_queue.top().first){
                    small_queue.pop();
                    small_queue.push({nums[i],i});
                }
            }
        }
        for(int i = 0; i < k; i++) {
            cout << small_queue.top().first << ' ';
            res.push_back(small_queue.top());
            small_queue.pop();
        }
        sort(res.begin(), res.end(),cmp1);
        for(int i = 0; i < k; i++) {
            res_.push_back(res[i].first);
        }
        return res_;
    }
};
