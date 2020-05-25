#include <iostream>
#include <string>
#include <cstdlib>

const int n=20;
int k=10;
int x,y;
std::string key;

void zeroing(int tab[][n], int copytab[][n], int n){		//zerowanie tablic
	
	for(int i=0; i<n; i++){ 	

		for(int j=0; j<n; j++){

			tab[i][j]=0;
			copytab[i][j]=0;
		}
	}
}

void setValues(int tab[][n], int copytab[][n], int x, int y, std::string key){		//wpisywanie wartoœci pocz¹tkowych i start programu
	
	do{

		std::cout << "Wprowadz wspolrzedne X i Y (po spacji): ";
		std::cin >> x >> y;

		tab[x][y]=1;
		copytab[x][y]=1;
		
		std::cout << std::endl << "Wprowadz klucz startowy: ";
		std::cin >> key;
		std::cout << std::endl;

	}while((key!="START")&&(key!="start"));
	
}

void display(int tab[][n], int n){		//wyœwietlanie planszy
	
	system("cls");
	for(int i=0; i<n; i++){

		for(int j=0; j<n; j++){

			std::cout << " " <<  tab[i][j];
		}

		std::cout << std::endl;
	}
	
	std::cout << std::endl << std:: endl << "== Wcisnij przycisk ENTER aby przejsc ==" << std:: endl << "========= do kolejnej generacji ========";
	
	std::cin.get();
	std::cin.ignore();
	
}

int neighbours(int copytab[][n], int i, int j){		//liczenie s¹siadów
	
	int suma=0;

	suma = copytab[i-1][j-1]+copytab[i-1][j]+copytab[i-1][j+1]+copytab[i+1][j-1]+copytab[i+1][j]+copytab[i+1][j+1]+copytab[i][j+1]+copytab[i][j-1];

//	if(copytab[i-1][j-1]==1) suma++;
//  if(copytab[i-1][j]==1) suma++;
//	if(copytab[i-1][j+1]==1) suma++;   
//	if(copytab[i+1][j-1]==1) suma++;
//	if(copytab[i+1][j]==1) suma++;    
//	if(copytab[i+1][j+1]==1) suma++;	    
//	if(copytab[i][j+1]==1) suma++;  
//	if(copytab[i][j-1]==1) suma++;
		    
	if(copytab[i][j]==1 && (suma==2 ||suma==3)) return 1;
	else if( copytab[i][j]==0 && suma==3) return 1;
	else return 0;

}

void overwrite(int tab[][n], int copytab[][n]){			//nadpisywanie tablic
	
	for(int i=1; i<=n; i++){
        
		for(int j=1; j<=n; j++){
            
			tab[i][j]=neighbours(copytab, i, j);
        }
    }

    for(int i=0; i<n; i++){
        
		for(int j=0; j<n; j++){
        	
            copytab[i][j]=tab[i][j];
        }
    }

}

int main(){

	int tab[n][n];
	int copytab[n][n];
	
	zeroing(tab, copytab, n);
	setValues(tab, copytab, x, y, key);
	display(tab,n);
	
	do{
		overwrite(tab, copytab);
		display(tab, n);		

	}while(k--);

	return 0;
}



