class Solution {
public:
    int split(string &s){
        istringstream iss(s);
        vector<string> strs;

         string temp;
         while(getline(iss, temp, ' ')){
            strs.emplace_back(move(temp));
         }
        return strs.size();
    }
    static bool cmp(pair<string, int>&a, pair<string, int>&b)
    {   
        if(a.second != b.second)
            return a.second<b.second;
        else{
            return a.first < b.first;
        }
        
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = senders.size();
        map<string,int> mp;
        vector<pair<string,int>> v;
        for(int i = 0; i < n; i++) {
            int cnt = split(messages[i]);
            if(mp.find(senders[i]) != mp.end())
                mp[senders[i]] += cnt;
            else
            {mp[senders[i]] = cnt;}
                
        }
        for(auto it = mp.begin(); it!=mp.end(); it++) {
            v.push_back({it->first,it->second});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i : v) {
            cout << i.first << ' ' << i.second << endl;
        }
        return v[v.size()-1].first;
    }
};
