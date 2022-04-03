class Encrypter {
public:
    vector<char> K;
    vector<string> V, D;
    vector<string> record;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        K = keys;
        V = values;
        // D = dictionary;
        record.resize(26);
        for(int i = 0; i < keys.size(); i++) {
            record[keys[i]-'a'] = values[i];
        }
        for(auto s : dictionary) {
            string res = "";
            for(char c : s) {

                res += record[c-'a'];
            }
            D.push_back(res);
        }

    }
    
    string encrypt(string word1) {
        string res = "";
        for(char c : word1) {
            
            res += record[c-'a'];
        }
        return res;
    }
     
    int decrypt(string word2) {
        int res = 0;
        for(string s : D) {
            if(s == word2) res++;
        }
        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */