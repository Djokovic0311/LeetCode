class Solution {
	public:
		static bool comp(vector<int>& a,vector<int>& b){
			if(a[0]==b[0])return a[1]>b[1];
			return a[0]<b[0];
		}

		int numberOfWeakCharacters(vector<vector<int>>& pro) {
			int n=pro.size();
			sort(pro.begin(),pro.end(),comp);
			int maxdef=INT_MIN;
			int count=0;
			for(int i=n-1;i>=0;i--){
				if(pro[i][1]<maxdef) count++;
				maxdef=max(maxdef,pro[i][1]);
			}
			return count;
		}
	};
