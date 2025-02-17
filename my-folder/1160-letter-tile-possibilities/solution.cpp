class Solution {
public:
    void generateSequence(string tiles, vector<bool>& used, unordered_set<string>& sequences, string current) {
        sequences.insert(current);
        for(int pos = 0; pos < tiles.length(); pos++) {
            if(!used[pos]) {
                used[pos] = true;
                generateSequence(tiles, used, sequences, current+ tiles[pos]);
                used[pos] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> sequences;
        vector<bool> used(tiles.length(), false);
        generateSequence(tiles, used, sequences, "");
        return sequences.size() - 1;
    }
};
