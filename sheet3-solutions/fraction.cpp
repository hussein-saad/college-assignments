#include <bits/stdc++.h>
using namespace std;

struct fraction{
    int numerator;
    int denominator;

//     initialization
    fraction(){
        numerator = 0;
        denominator = 1; // to avoid division by zero
    }

};

// adding the two operands and return the result
fraction addition(fraction f1, fraction f2){
    fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

// subtracting the two operands and return the result
fraction subtraction(fraction f1, fraction f2){
    fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

//multiplying the two operands and return the result
fraction multiplication(fraction f1, fraction f2){
    fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}
// dividing the two operands and return the result
fraction division(fraction f1, fraction f2){
    fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    return result;
}

int main(){


    int a,b,c,d; // for numerator and denominator of two operands

    char div1,div2,sign; // for first and second division sign and for sign of result

    fraction f1,f2,ans;
    string check;

    while(true) {
        cout << "Enter the operation: ";
        cin >> a >> div1 >> b >> sign >> c >> div2 >> d;

        f1.numerator = a, f1.denominator = b;
        f2.numerator = c, f2.denominator = d;
        if (sign == '+')
            ans = addition(f1, f2);
        else if (sign == '-')
            ans = subtraction(f1, f2);
        else if (sign == '*')
            ans = multiplication(f1, f2);
        else
            ans = division(f1, f2);

        if (ans.denominator == 0)
            cout<<"Error division by zero\n"; // handle division by zero to avoid runtime error
        else
            cout << "the result is: " << ((double) ans.numerator / ans.denominator) << "\n";

        cout<<"Enter (n,no) to exit or (y,yes) to continue\n"; // keep looping while user don't exit
        cin>>check;
        if (check == "n" || check == "no")
            break;
    }


}