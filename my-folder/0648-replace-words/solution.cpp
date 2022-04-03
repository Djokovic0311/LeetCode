class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
	unordered_set<string> dict;
	for(string w:dictionary)
		dict.insert(w);

	string res = "", curr="";
	bool skip = false;
	for(int i=0;i<=sentence.length();i++)
	{
		if(sentence[i]==' ' or i==sentence.length())
		{
			res+=curr;
			if(i!=sentence.length())
				res+=" ";
			curr = "";
			skip = false;
		}            
		else if(not skip)
		{
			curr += sentence[i];
			if(dict.find(curr) != dict.end())
				skip = true;
		}

	}
	return res;        
    }
};
