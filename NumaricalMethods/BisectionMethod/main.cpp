#include <bits/stdc++.h>

using namespace std;

double func(double a){
    double c = cos(a * (3.14159265358979323846/180));
    return ((3*a) - c - 1);
}

bool checkDulicate(vector <double> & v, double  current){
    // int size = v.size();
    // for(int i = 0; i < v.size(); i++){
    //     if(abs(v[i] - current) <= 0.00000001){
    //         return true;
    //     }
    // }
    // return false;

    if(v.empty()){
        return false;
    }
    
    int size = v.size();

    if(abs(v[size - 1] - current) < 0.00000001){
        return true;
    }else{
        return false;
    }
}

int main(){

    double a = 0; double b = 1;
    double c = 0;
    vector <double> v;
    bool duplicate = false;
    while(!duplicate){
        c = (a + b)/2;
        duplicate = checkDulicate(v, c);
        if(duplicate) break;
        v.push_back(c);

        double funcA = func(a);
        double funcC = func(c);
        double temp = funcA * funcC;
        if(temp <= 0){
            b = c;
        }else{
            a = c;
        }
        
    }

    cout << "The answer is: " << c << endl;

    return 0;
}
