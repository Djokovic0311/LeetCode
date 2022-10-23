class Solution {
public:
    string mx(string e1, string e2) {
        int start1 = stoi(e1.substr(0,2)), start2 = stoi(e2.substr(0,2));
        int end1 = stoi(e1.substr(3)), end2 = stoi(e2.substr(3));
        if(start1 != start2)
            return (start1 > start2 ? e1 : e2);
        else
            return (end1> end2 ? e1 : e2);
    }
    string mi(string e1, string e2) {
        int start1 = stoi(e1.substr(0,2)), start2 = stoi(e2.substr(0,2));
        int end1 = stoi(e1.substr(3)), end2 = stoi(e2.substr(3));
        if(start1 != start2)
            return (start1 < start2 ? e1 : e2);
        else
            return (end1 < end2? e1 : e2);
    }
    bool compare(string e1, string e2) {
        int start1 = stoi(e1.substr(0,2)), start2 = stoi(e2.substr(0,2));
        int end1 = stoi(e1.substr(3)), end2 = stoi(e2.substr(3));
        if(start1 != start2)
            return start1 < start2;
        else
            return end1 <= end2;        
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string l = mx(event1[0], event2[0]);
        string r = mi(event1[1], event2[1]);
        // cout << l << " " << r;
        return compare(l, r);
    }
};
