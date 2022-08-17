class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int i = 0, j = 0, k = maxLetters, sz = s.size(), maxmO = 0, cnt = 0 ;
        unordered_map<char, int> umap ; unordered_map<string, int> umap_2 ;
        
        while(j<sz)
        {
            umap[s[j]]++ ; 
            
            while(j-i+1 > minSize || umap.size()>k)
            {
                umap[s[i]]-- ; 
                if(umap[s[i]] == 0){umap.erase(s[i]) ;} 
                i++ ; 
            }
            
            if(j-i+1 >= minSize && j-i+1 <= maxSize && umap.size()<=k)
            {
                 maxmO = max(maxmO, ++umap_2[s.substr(i, minSize)]) ;
            }
            j++ ;
        }
        return maxmO ;
    }
};
