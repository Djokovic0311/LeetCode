class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
       unordered_map<int, unordered_set<int>> hashmap; // Key => Integer | Value => Set
        
        for(auto& single_point: points) 
            hashmap[single_point[0]].insert(single_point[1]); 
        int minimum_area = INT_MAX; // Vairable to store the minimum area
        
        for(int i = 0; i < points.size(); i++) { // Iterator corresponding to different A points
            for(int j = i + 1; j < points.size(); j++) { 
			
                int x1 = points[i][0], y1 = points[i][1];  // Coordinates of Point A
				int x2 = points[j][0], y2 = points[j][1];  // Coordinates of Point B
                
                if(x1 != x2 && y1 != y2) // Point A & B must form a diagonal of the rectangle.
                    if( hashmap[x1].find(y2) != hashmap[x1].end() 
											&& 
					hashmap[x2].find(y1) != hashmap[x2].end() ) 
                        minimum_area = min( minimum_area , abs(x1-x2) * abs(y1-y2) );
            }
        }
        return minimum_area != INT_MAX ? minimum_area : 0;        
    }
};
