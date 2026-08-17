#include <iostream>
using namespace std;


void pattern(int n){
    for (int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < i ;j++ ){
            cout << "*";
        }
        cout << endl;

    }
    for (int j = 1 ; j <= n-1 ; j++){
        for(int i = n ; i > j ; i--){
            cout << "*";
        }
        cout << endl;

    }

}

int main(){
    pattern(5);
}