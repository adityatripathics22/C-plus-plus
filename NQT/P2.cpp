#include <iostream>
using namespace std;
#include <vector>

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n ;
	    cin >> n;
	    int prod = 1;
	    vector<int> arr(n);
	    
	    for(int i = 0 ; i < n ; i++){
	        cin >> arr[i];
	        prod *= arr[i];
	        
	        
	        
	    }
	    
	    for(int i = 0 ; i < n ; i++){
	        cout << prod / arr[i] << endl;
	        
	    }
	}return 0;

}
