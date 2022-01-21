class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost=0,total_fuel=0,n=cost.size();
        for(int i=0;i<n;i++)
        {
            total_cost+=cost[i];
            total_fuel+=gas[i];
        }
        if(total_fuel<total_cost)
        {
            return -1;
        }
        int curr_fuel=0,start=0;  // start with zero fuel.
        for(int i=0;i<n;i++)
        {
            if(curr_fuel<0)
            {
                start=i;
                curr_fuel=0;
            }
            curr_fuel+=(gas[i]-cost[i]);
        }
        return start;        
    }
};
