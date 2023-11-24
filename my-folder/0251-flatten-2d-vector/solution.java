import java.util.NoSuchElementException;
class Vector2D {
    private int[][] vector;
    private int inner = 0;
    private int outer = 0;
    private void advanceToNext() {
        while (outer < vector.length && inner == vector[outer].length) {
            inner = 0;
            outer++;
        }
    }
    public Vector2D(int[][] vec) {
        vector = vec;
    }
    
    public int next() {
        if (!hasNext()) throw new NoSuchElementException();
        return vector[outer][inner++];
    }
    
    public boolean hasNext() {
        advanceToNext();
        return outer < vector.length;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(vec);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
