#include <bits/stdc++.h>

using namespace std;

double fun(double x){
    double c = cos(x);
    return ((c + 1)/3);
}

int main(){

    double x = 3.5;
    double prevX;

    while(true){
        prevX = x;
        x = fun(prevX);
        if(abs(prevX - x) < 0.000001){
            cout << x << endl;
            break;
        }
    }

    return 0;
}