#include <bits/stdc++.h>

using namespace std;

double func(double a){
    return 3 * a - (cos(a)) - 1;
}

double diffFunc(double a){
    return 3 + sin(a);
}

int main(){

    double guess = 1;
    bool duplicate = false;
    while(!duplicate){
        double priv = guess;
        guess = guess - (func(guess)/diffFunc(guess));
        if(abs(priv - guess) < 0.000000001){
            duplicate = true;
        }
    }

    cout << "The approximate root is: " << guess << endl;


    return 0;
}