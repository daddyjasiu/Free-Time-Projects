#include <iostream>
#include <iomanip>

int bin[8];
int n,k;
char a;

int dec_2_bin(int n){ //dec 2 bin
	
	for(int b=0;b<8;b++){
		
		bin[b]=0; //zerowanie tablicy
	}

	for(int b=0;n>0;b++){
		
		bin[b]=n%2; //wype³nianie tablicy
		n=n/2;
	}
	
	for(int b=7;b>=0;b--){
		
		std::cout << bin[b]; //wypisywanie tablicy od koñca
	}
}

void draw_rows(unsigned i) { //rysowanie wierszy
    
    std::cout << std::setw(2);
	dec_2_bin(i);
	a=i;
    std::cout << std::setw(4) << i << std::setw(2) << a << std::setw(2) << '|';
}
 
void draw_columns(unsigned n, unsigned k) { //wypisywanie wyników w kolumnach
   
	unsigned columns = (k-n+1)/32; //jeœli wynik <=1, jedna kolumna, jeœli wynik >1, dwie kolumny, jeœli wynik >2, trzy kolumny
	
	for(int i=n; i<n+32; i++){ //zapewnienie kolumn nie d³u¿szych, ni¿ 32 wiersze
	
		for(unsigned col = 0; col <= columns; ++col){

			unsigned value = col*32+i;
            
            if(value<=k) {
                
				draw_rows(value);
			}
		}
		std::cout << std::endl;	
	}
}
 
int main() {
	
	while(n<32||n>127||n>k||k>127){ //wymaganie poprawnego przedzialu
		
		std::cout << "Podaj dolny zakres (32-127): ";
		std::cin >> n;
		std::cout << "Podaj gorny zakres (32-127): ";
		std::cin >> k;
		std::cout << std::endl;
	}

    draw_columns(n, k);    
    
    return 0;
}
