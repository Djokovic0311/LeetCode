class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int res = INT_MAX;
        int mod = 1e9+7;
        int start = 1, end = 1e9+7;
        while(start <= end) {
            int mid = start + (end-start) /2 ;
            if(isValid(dist, hour, mid)) {
                res = min(res, mid);
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }

        return res == INT_MAX ? -1 : res;
    }
    bool isValid(vector<int>&arr,double &hour,int &mid)
    {
        double time=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            time=time+ceil(arr[i]/(mid*1.00));
        }
        time=time+(arr[arr.size()-1]/(mid*1.00));
        return time <= hour;
    }
};
