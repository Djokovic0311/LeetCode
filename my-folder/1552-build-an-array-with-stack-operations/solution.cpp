class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int currElem=1; 
        for(int i=0;i<target.size();i++){
            while(currElem!=target[i]){ 
                ans.push_back("Push");  
                ans.push_back("Pop");
                currElem++;
            }
            ans.push_back("Push"); 
            currElem++;
        }
        return ans;        
    }
};
