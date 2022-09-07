class StringIterator {
public:

    queue <pair<char, int>> q;

    StringIterator(string s) {
        int i = 0;
        char c;
        int num = 0;
        while (i < s.size()) {

            if (isalpha(s[i])) {
                num = 0;
                c = s[i];
                i++;
            }

            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                num *= 10;
                num += s[i] - '0';
                i++;
            }

            q.push({c, num});
        }
    }

    char next() {

        if (hasNext()) {
            auto &i = q.front();

            i.second--;
            char ret = i.first;

            if (i.second == 0) {
                q.pop();
            }

            return ret;
        } else {
            return ' ';
        }

    }

    bool hasNext() {
        return !q.empty();
    }
};
/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
