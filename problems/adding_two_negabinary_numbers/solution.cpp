class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		reverse(arr1.begin(),arr1.end());
		reverse(arr2.begin(),arr2.end());
		int len(max(arr1.size(),arr2.size()));
		int carry=0;
		vector<int> ans;
		for(int i=0;i<len+2;i++){
			int cur1=i<arr1.size() ? arr1[i]:0;
			int cur2=i<arr2.size() ? arr2[i]:0;
			int sum=cur1+cur2+carry;
			int r=sum%(-2);
			carry=sum/(-2);
            cout << r << ' ' << carry << endl;
			if(r<0){
				carry++;
				r+=abs(-2);
			}          
			ans.push_back(r);

		}
        cout << endl;
		while(ans.size()>1 && ans.back()==0){
			ans.pop_back();
		}
		reverse(ans.begin(),ans.end());
		return ans;
    }
};