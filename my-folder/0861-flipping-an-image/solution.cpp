class Solution {
public:
    void flip(vector<int>& vec) {
        int n = vec.size();
        for(int i = 0; i < n/2; i++) {
            swap(vec[i],vec[n-1-i]);
        }
    }
    void invert(vector<int>& vec) {
        int n = vec.size();
        for(int i = 0; i < n; i++) {
            vec[i] = vec[i] ^ 1;
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0; i < n; i++) {
            flip(image[i]);
            invert(image[i]);
        }
        return image;
    }
};
