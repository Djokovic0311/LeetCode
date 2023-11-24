class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[][] points = {p1, p2, p3, p4};
        long[] distances = new long[6]; // There are 6 distances to check
        int index = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                distances[index++] = dist(points[i], points[j]);
            }
        }
        Arrays.sort(distances); // Sort the distances
        // Check if the smallest 4 are equal and non-zero, and if the largest 2 are equal
        return distances[0] != 0 && distances[0] == distances[1] && distances[0] == distances[2] 
                && distances[0] == distances[3] && distances[4] == distances[5];        
    }
    private long dist(int[] a, int[] b) {
        // Calculate square of the distance to avoid floating point operations
        return (long) (a[0] - b[0]) * (a[0] - b[0]) + (long) (a[1] - b[1]) * (a[1] - b[1]);
    }
}
