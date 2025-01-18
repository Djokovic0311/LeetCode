class Solution 
{
public:
    string oddString(vector<string>& words) 
    {
        int w_size=words[0].size();
        int n=words.size();

		vector<int> temp(w_size-1);
        vector<vector<int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<w_size-1; j++){
                temp[j] = words[i][j+1]-words[i][j];
            }
            mp.push_back(temp);
        }

        vector<int> count(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mp[i] != mp[j])
                {
                    count[i]++;
                    count[j]++;
                }
            }
        }

        int maxi=INT_MIN, idx;
        for(int i=0; i<n; i++){
            if(count[i] > maxi){
                maxi = count[i];
                idx = i;
            }
        }
        return words[idx];
    }
};
