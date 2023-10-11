class Solution {
public:


    bool isSubsequence(string temp , string str){
        int j=0;
        for(int i=0;i<temp.length();i++){
            if(temp[i] == str[j]) j++;
            if(j>=str.length()) return true;
        }
        return false;
    }



    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0 , high = removable.size() -1 ;
        int ans = -1;
        while( low <= high ){
          int mid = (low+high)>>1;
          string temp=s;
          for(int i=0;i<=mid;i++){
             temp[removable[i]] = '.';
          }
          if(isSubsequence(temp,p)){
                ans=max(ans,mid);
                low = mid+1;
          }
          else high = mid - 1;
        }
        return ans+1;

    }
};
