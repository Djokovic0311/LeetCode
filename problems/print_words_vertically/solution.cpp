class Solution {
public:
    vector<string> printVertically(string str) {
        int col=1,row=0,x;
        string temp;
        vector<string>s;
        //converting string to vector of strings, extracted words from string.
        stringstream iss(str);
        while (iss >> temp)
        {
            s.push_back(temp);
            col++;
            x=temp.size();
            row=max(row,x);
        }
        
        //created a 2d matrix
        int n=max(row,col);
        string a[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                a[i][j]=' ';
        }
        
        // storing each string column wise,
        // each time row (k) will be zero,
        // Column number will be equal to string number.
        // Row value(k) will increment, but not columnn value(j),
        // bcz we place all characters of a particular string in same column.
        int k,j; col=0;
        for(auto ti: s)
        {
            k=0,j=col;
            for(auto it : ti)
            {
                a[k][j]=it;
                k++;
            }
            col++;//next column for next string.
        }
        
        // converting 2d matrix back to strings row wise.
        vector<string>res;
        for(int i=0;i<row;i++)
        {
            temp="";
            for(int j=0;j<col;j++)
            {
                temp+=a[i][j];
            }
            while(*temp.rbegin()==' ' && !temp.empty())
                temp.pop_back();
            res.push_back(temp);
        }
        return res;
    }
};