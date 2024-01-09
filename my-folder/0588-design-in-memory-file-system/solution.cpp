struct Node {
    map<string, Node*> dir = {};
    string content = "";
};
class FileSystem {
    Node* main;
public:
    FileSystem() {
        main = new Node();
    }
    
    vector<string> ls(string path) {
        vector<string> result;
        Node* pathNode = getNode(path);
        if(!pathNode->content.empty() && pathNode->content != "") {
            return {path.substr(path.find_last_of('/') + 1)};
        }

        for(auto const& [name, node] : pathNode->dir) {
            result.push_back(name);
        }
        return result;
    }
    
    void mkdir(string path) {
        getNode(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto node = getNode(filePath);
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto node = getNode(filePath);
        return node->content;
    }

    Node* getNode(string path) {
        stringstream ss(path);
        string currentPath = "";
        Node* currentNode = main;
        while(getline(ss, currentPath,'/')) {
            if((currentNode->dir).find(currentPath) == (currentNode->dir).end()) {
                currentNode->dir[currentPath] = new Node();
            }

            currentNode = currentNode->dir[currentPath];
        }
        return currentNode;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
