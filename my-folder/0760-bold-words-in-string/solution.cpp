class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        vector<pair<int, int>> intervals;
        
        // Mark all the intervals in the string s that need to be bolded
        for (const auto& word : words) {
            size_t start = s.find(word, 0);
            while (start != string::npos) {
                intervals.push_back({start, start + word.size()});
                start = s.find(word, start + 1);
            }
        }
        
        // Sort the intervals
        sort(intervals.begin(), intervals.end());

        // Merge the overlapping intervals
        vector<pair<int, int>> merged;
        for (const auto& interval : intervals) {
            if (merged.empty() || merged.back().second < interval.first) {
                merged.push_back(interval);
            } else {
                merged.back().second = max(merged.back().second, interval.second);
            }
        }
        
        // Insert the <b> and </b> tags
        string result;
        int prevEnd = 0;
        for (const auto& interval : merged) {
            result += s.substr(prevEnd, interval.first - prevEnd);
            result += "<b>";
            result += s.substr(interval.first, interval.second - interval.first);
            result += "</b>";
            prevEnd = interval.second;
        }
        result += s.substr(prevEnd);

        return result;        
    }
};
