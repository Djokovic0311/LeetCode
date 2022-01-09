class Solution {
public:
    bool func2(vector<int>& nums){
		set<int> arr;
		pair<set<int>::iterator,bool> pr;
		for(vector<int>::iterator it=nums.begin();it<nums.end();it++){
			pr = arr.insert(*it);
			if(pr.second==false){
				return true;
			}
		}
		return false;
	} 

    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++) {
            set<int> arr;
            pair<set<int>::iterator,bool> pr;
            for(vector<int>::iterator it = matrix[i].begin(); it < matrix[i].end(); it++) {
                pr = arr.insert(*it);
                if(pr.second==false) {
                    return false;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            set<int> arr;
            pair<set<int>::iterator,bool> pr;
            for(int j = 0; j < n; j++) {
                pr = arr.insert(matrix[j][i]);
                if(pr.second==false) {
                    return false;
                }
            }
        }
        return true;
    }
};