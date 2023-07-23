class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    vector<string> result;
        for (const auto& word : words) {
            stringstream ss(word);
            string item;
            while (getline(ss, item, separator)) {
                if (!item.empty()) {
                    result.push_back(item);
                }
            }
        }
        return result;
    }
};
