#include <iostream>
#include <iomanip>

int n;

using namespace std;

int main(){
	
	cout << "===================================| |" << endl;
	cout << "Wprowadz zakres tabliczki mnozenia: ";
	cin >> n;
	
	cout << endl << endl;
	cout << "  | ";
	
	for(int i=1; i<=n; i++) {
	
		cout << i << "  ";
	}
	
	cout << endl;
	
	cout << "--+";
	
	for (int k=0; k<n*3; k++) cout <<"-";
	
	cout << endl;
	
	for (int i=1; i<=n; i++){
		
		cout << i << " ";
		cout << "| ";
		
		for(int j=1; j<=n; j++){
		
			if(j*i<10) cout << j*i << "  ";
			else cout << j*i << " ";
		
		}
		
		cout << endl << endl;
	}
	
	return 0;
}
