class Solution {
public:
    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(),boxTypes.end(),myfunction);
        int ans=0;
        for(auto box: boxTypes){
            int x=min(box[0],truckSize); 
            ans+=(x*box[1]);  //adding units in ans
            truckSize-=x;  //reduce the capacity
            if(!truckSize) break;  //capacity full
        }
        return ans;        
    }
};
