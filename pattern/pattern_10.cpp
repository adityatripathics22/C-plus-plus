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
        
        cout << endl;
    }

    for(int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j < i ; j++){
            cout << " ";

        }
        for ( int k = (n*2)-((i+i)-1) ; k > 0 ; k--){
            cout << "*";
        }
        cout << endl;
    }
    
}
int main(){
    pattern(5);
}


