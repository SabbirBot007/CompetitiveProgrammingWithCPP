#include <bits/stdc++.h>

using namespace std;

double func(double a){
    return 3 * a - (cos(a)) - 1;
}

int main(){

    double guess = 1;
    bool duplicate = false;
    double priv = 0;
    while(!duplicate){
        
        double guess2 = guess - (((guess - priv) * func(guess))/(func(guess) - func(priv)));
        priv = guess;
        guess = guess2;
        if(abs(priv - guess) < 0.000000001){
            duplicate = true;
        }
    }

    cout << "The approximate root is: " << guess << endl;


    return 0;
}