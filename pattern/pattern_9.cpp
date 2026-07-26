#include <iostream>
using namespace std;

void pattern(int n){
    for(int i = 1 ; i <= n ; i++){
        for (int j = 0 ; j < i ; j++){
            cout << " ";

        }
        for ( int k = (n*2)-((i+i)-1) ; k > 0 ; k--){
            cout << "*";
        }
        for (int l = 0 ; l < i ; l++){
            cout << " ";

        }
        cout << endl;
    }
}
int main(){
    pattern(5);
}