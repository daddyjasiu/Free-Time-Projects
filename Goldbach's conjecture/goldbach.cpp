#include <iostream>

int n;
int k=4;

bool prime(int n){
	
	for(int i=2; i<n; i++){
		
		if(n%i==0) return false;
	}
	
	return true;
}

using namespace std;

int main(){
	
	cout << "=======================================================================" << endl;
	cout << "|| ================================================================= ||" << endl;
	cout << "|| Hipoteza Goldbacha: rozklad liczby parzystej na czynniki pierwsze ||" << endl;
	cout << "|| ================================================================= ||" << endl;
	cout << "=======================================================================" << endl << endl << endl;
	
	cout << "                      Wprowadz zakres rozkladu: ";
	cin >> n;
	cout << endl << endl;
	for(int i=0; i<n/2-1; i++){
	
		for(int i=2; i<k; i++){
		
			for(int j=2; j<k; j++){
		
				if((prime(i)==1)&&(prime(j)==1)&&(i+j==k)) cout << "Liczba parzysta: " << k << "  ------------------------------->  I LP: " << i << "  II LP: " << j << endl; 
			}
		}
		
		k=k+2;
	}
	
	return 0;
}
