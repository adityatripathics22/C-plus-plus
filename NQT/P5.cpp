
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){
    int V;
    int W;
    cin >> V >> W ;
    if(W % 2 != 0 || W < 2*V || W > 4*V){
        cout << "INVALID INPUT";
        return 0;
    }
    int FW = (W - 2*V)/2;
    int TW = V - FW;
    if(TW < 0 || FW < 0){
        cout << "INVALID INPUT";
       
    }
    else{
        cout<< TW << endl;
        cout << FW;
    }


}