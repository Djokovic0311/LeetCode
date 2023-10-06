class Solution {
public:
   vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string,int>m;
    vector<string>ans;
    for(int i=0;i<names.size();i++){
      if(m.find(names[i])!=m.end())
       {
          int k = m[names[i]];
           string str;
          do{
           str = names[i]+'(';
          str += to_string(k);
              str += ')';
            m[names[i]]++;
            k++;
          }
          while(m.find(str)!=m.end());
          m[str]++ ;
          ans.push_back(str);
       }
       else
       {
          m[names[i]]++;
          ans.push_back(names[i]);
       }
    }
    return ans;
    }
};