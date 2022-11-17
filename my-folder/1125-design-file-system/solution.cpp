struct Node {
    int value;
    unordered_map<string, Node *> children;
    Node()
    {
        value = 0;
    }
};
class FileSystem {
public:
    FileSystem() {
        root = new Node();
    }
    
    bool createPath(string path, int value) {
        vector<string> str_list = split(path);
        Node *curr;
        curr = root;
        string fname;
        int i, n = str_list.size();
        for(i = 0; i < n; i++) {
            fname = str_list[i];
            if(curr->children[fname] == nullptr) {
                break;
            }
            curr = curr->children[fname];
        }

        if(i == n-1) {
            curr->children[fname] = new Node;
            curr->children[fname]->value = value;
            return true;
        }
        return false;
    }
    
    int get(string path) {
        if(!root) return -1;
        string fname;

        vector<string> str_list = split(path);
        int i, entries = str_list.size();
        
        Node *curr = root;
        for (i = 0; i < entries; i++) {
            fname = str_list[i];
            if (curr->children[fname] == nullptr) {
                return -1;
            }
            curr = curr->children[fname];
        }
        return curr->value;

    }
private:
    Node* root;
    vector<string> split(string path)
    {
        path = path.substr(1, path.length());
        stringstream ss(path);
        string fname;
        vector<string> str_list;

        while (getline(ss, fname, '/')) {
            str_list.push_back(fname);
        }

        return str_list;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
