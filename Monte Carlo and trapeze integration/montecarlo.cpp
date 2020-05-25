#include <iostream>
#include <cstdlib>
#include <ctime>

double a, b;
double P=1000000.0, N=1000000.0;


double function(double x){ // wzor funkcji

	return (x*x*x-8);
}

double integrMC(double a, double b, double P){ // metoda monte carlo

	double length = b-a; // dlugosc przedzialu a i b
	double S = 0;

	for(int i=1; i<=N; i++){
 	
		S = S + function(a + ((double)rand() / (double)(RAND_MAX+1) * length));
	}

	return S = length * S / P;
}

double integrT(double a, double b, double N){

	double h = (b-a)/N; // wysokosæ trapezów
	double S = 0.0; // suma pól trapezów
	double base_a = function(a), base_b;

	for(int i=1;i<=N;i++) // przeskakiwanie do kolejnych trapezow i liczenie sumy podstaw
	{
		base_b = function(a+h*i);
		S = S + (base_a + base_b);
		base_a = base_b;
	}

	return S*0.5*h;
}


int main(){

	srand(time(NULL));

	std::cout << "Wprowadz przedzial calkowania: \n\n";
	std::cout << "A: ";
	std::cin >> a;
	std::cout << "B: ";
	std::cin >> b;

	std::cout << "\nCalka obliczona metoda Monte Carlo: " << integrMC(a,b,P) << std::endl;
	std::cout << "Calka obliczona metoda trapezow: " << integrT(a,b,N);

	return 0;
}

