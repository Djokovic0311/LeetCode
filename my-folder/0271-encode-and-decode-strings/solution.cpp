class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        std::string result;

        for (string str : strs) 
             result += std::to_string(str.size()) + "#" + str;

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        std::vector<string> result;
        int start = 0;
        int end   = s.find("#");

        while (end != std::string::npos) {
            
            int size = std::stoi(s.substr(start, end - start));
            result.push_back(s.substr(end+1, size));
            start = end+size+1;
            end   = s.find("#", start);
        }

        return result;
    }
};   
