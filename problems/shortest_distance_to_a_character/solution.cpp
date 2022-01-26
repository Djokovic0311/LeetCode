class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ioc; 
        int n=s.length();
        vector<int>ans(n); 
        
        for(int i=0;i<n;++i){
            if(s[i]==c) 
                ioc.push_back(i);
        }
        
        int m=ioc.size(); 
        int left=0,right=0;
        
        for(int i=0;i<n;++i){
            
            if(i>ioc[right]){
                left=right;
                if(right<m-1)
                    ++right;
            }
                        
            // difference = min(abs(right nearest 'c' - curr index),abs(left nearest 'c' - curr index))
            ans[i]=min(abs(ioc[right]-i),abs(ioc[left]-i)); 

        }
        
        return ans;        
    }
};