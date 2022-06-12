class Solution {
public:
void isPalindrome(const string& s,const int& length,int left,int right, int& start, int& maxlen){
	while(left>=0 && right<length && s[left]==s[right]) --left,++right;
	if(maxlen < right-left-1)   maxlen = right-left-1, start = left+1;
}
string longestPalindrome(string s) {
	int n = s.size(),start=0,maxlen=0;
	if(n<2) return s;
	for(int i=0;i<n-1;++i){
		isPalindrome(s,n,i,i,start,maxlen); //aba
		isPalindrome(s,n,i,i+1,start,maxlen); //noon
	}
	return s.substr(start,maxlen);
}
};
