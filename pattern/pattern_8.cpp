#include <iostream>
using namespace std;

void pattern(int n){
    for(int i = 1 ; i <= n ; i++){
        for (int j =n-i ; j >0 ; j--){
            cout << " ";

        }
        for ( int k = 1 ; k <= (i*2)-1 ; k++){
            cout << "*";
        }
        for (int l =n-i ; l >0 ; l--){
            cout << " ";

        }
        cout << endl;
    }
}
int main(){
    pattern(5);
}