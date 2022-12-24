class Trie{
    public:
        Trie(){}    // 构造函数

        void insert(string word){   // 插入
            Trie* node = this;
            for(int i=0; i<word.length(); i++){
                char c = word[i];
                if(node->next[c-'a']==nullptr){
                    node->next[c-'a'] = new Trie();
                }
                node = node->next[c-'a'];
            }
            node->flag = true;  // 单词串的尾节点为true
        }

        bool search(string word){   // 查找单词是否存在Trie中
            Trie* node = this;
            for(int i=0; i<word.length(); i++){
                char c = word[i];
                if(node->next[c-'a']==nullptr)  return false;
                node = node->next[c-'a'];
            }
            return node->flag;  // 如果该节点是串尾节点，则为true
        }

        bool starsWith(string prefix){  //查找前缀
            Trie * node = this;
            for(int i=0; i<prefix.length(); i++){
                char c = prefix[i];
                if(node->next[c-'a']==nullptr)  return false;
                node = node->next[c-'a'];
            }
            return true;
        }
    private:
        // 定义节点
        bool flag = false;
        Trie* next[26] = {nullptr};
};

class Solution {
public:
    int calculate(string str, Trie pos, Trie neg) {
        vector<string> arr;
            istringstream ss(str);
            string word;
            int res = 0;
            while(ss>>word) {
                if(pos.search(word)){
                    // cout << word << ' ';
                    res += 3;
                    continue;
                }
                else if(neg.search(word)){
                    res += -1;
                    continue;
                }
            }
        // cout << res << endl;
        return res;

    }
    
    static bool comp(const vector<int>&a,const vector<int>&b){
            if(a[1]!=b[1]) return a[1]>b[1];
            else return a[0]<b[0];
    }
    
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        Trie pos = Trie();
        Trie neg = Trie();
        for(string p : positive_feedback) pos.insert(p);
        for(string n : negative_feedback) neg.insert(n);
        // cout << m
        int n = report.size();
        vector<int> res;
        vector<vector<int>> record;
        
        for(int i = 0; i < n; i++) {
            int tmp = calculate(report[i], pos, neg);
            // cout << tmp << endl;
            record.push_back({student_id[i], tmp});
        }
        
        sort(record.begin(), record.end(), comp);
        for(int i = 0; i< k; i++) {
            res.push_back(record[i][0]);
        }
        
        return res;
    }
};
