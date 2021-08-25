# include <stdlib.h>
class Solution {
public:
    int real(string num) {
        int pos = num.find('+',0);
        // cout<<pos<<endl;

        int real = stoi(num.substr(0, pos));
        // cout<<"real " << real << endl;
        return real;
    }
    int imag(string num) {
        int pos = num.find('+',0);

        int imag = stoi(num.substr(pos+1,num.length()-pos-2));
        // cout << "imag " << imag << endl;
        return imag;
    }
    string complexNumberMultiply(string num1, string num2) {
        int real1 = real(num1);
        int real2 = real(num2);
        int imag1 = imag(num1);
        int imag2 = imag(num2);
        int new_real = 0, new_imag = 0;
        cout<<real1<<real2<<endl;
        cout<<imag1<<imag2<<endl;
        
        new_real = (real1 * real2) - (imag1 * imag2);
        new_imag = imag1*real2 + imag2*real1;
        return to_string(new_real) + '+' + to_string(new_imag) + 'i';
    }
};
