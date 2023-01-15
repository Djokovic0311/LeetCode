class Solution {
public:
    vector<vector<int>> mat;
    int M, N;
void updateQuery(int from_x, int from_y,
                 int to_x, int to_y,
                 int k, vector<vector<int>>& aux)
{
    // Update top cell
    aux[from_x][from_y] += k;
 
    // Update bottom left cell
    if (to_x + 1 < N)
        aux[to_x + 1][from_y] -= k;
 
    // Update bottom right cell
    if (to_x + 1 < N && to_y + 1 < M)
        aux[to_x + 1][to_y + 1] += k;
 
    // Update top right cell
    if (to_y + 1 < M)
        aux[from_x][to_y + 1] -= k;
}
 void printMatrix(vector<vector<int>> mat)
{
    // Traverse each row
    for (int i = 0; i < N; i++) {
 
        // Traverse each columns
        for (int j = 0; j < M; j++) {
 
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
void updateMatrix(vector<vector<int>>& mat, vector<vector<int>>& aux)
{
 
    // Compute the prefix sum of all columns
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            aux[i][j] += aux[i][j - 1];
        }
    }
 
    // Compute the prefix sum of all rows
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < N; j++) {
            aux[j][i] += aux[j - 1][i];
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
 
            mat[i][j] += aux[i][j];
        }
    }
}

void matrixQuery(vector<vector<int>>& mat, int Q,
 vector<vector<int>> q)
{
 
    vector<vector<int>> aux(N, vector<int>(N,0));
 
    for (int i = 0; i < Q; i++) {
 
        // Update Query
        updateQuery(q[i][0], q[i][1],
                    q[i][2], q[i][3],
                    1, aux);
        // printMatrix(aux);
    }
 
    // Compute the final answer
    updateMatrix(mat, aux);
    
 
}
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        this->mat.resize(n, vector<int>(n));
        this->M = this->N = n;
        matrixQuery(mat, q, queries);
        return mat;
        
    }
};
