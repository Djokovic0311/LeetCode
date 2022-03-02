class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int, int>> visited;
        visited.insert(make_pair(x, y));
        for (const auto& c : path) {
            if (c == 'N')
                y++;
            else if (c == 'S')
                y--;
            else if (c == 'W')
                x--;
            else if (c == 'E')
                x++;

            auto newPoint = make_pair(x, y);
            if (visited.count(newPoint))
                return true;
            else
                visited.insert(newPoint);
        }
        return false;        
    }
};
