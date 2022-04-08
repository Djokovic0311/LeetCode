class Solution {
public:
    bool isExpressive(string dst,string src) {
        int i=0,j=0;
        while(i<dst.size() && j<src.size()) {
           if(dst[i] != src[j]) return false;
		   int dstCount = 1,srcCount = 1;
		   
			// dst[++i] means increment the value of i then use it 
            while(i<dst.size() && dst[i]==dst[++i]) { dstCount++;} 
            while(j<src.size() && src[j]==src[++j]) { srcCount++;}
                  
            if(dstCount != srcCount && (srcCount > dstCount || dstCount <3))
                return false;
        }
        
        return i==dst.size() && j==src.size();
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        
        for(auto w : words) {
            res += isExpressive(S,w);
        }
        
        return res;
        
    }
};