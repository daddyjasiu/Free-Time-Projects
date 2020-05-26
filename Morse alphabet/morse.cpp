#include <iostream>

void morse(const char *pnapis, int n, void dot(), void line(), void nextline(), void space()){
	
	for(int i=0; i<n; i++){
		
			  if(*(pnapis+i)=='A'||*(pnapis+i)=='a'){dot(); line(); nextline();}
		else if (*(pnapis+i)=='B'||*(pnapis+i)=='b'){line(); dot(); dot(); dot(); nextline();}
		else if (*(pnapis+i)=='C'||*(pnapis+i)=='c'){line(); dot(); line(); dot(); nextline();}
		else if (*(pnapis+i)=='D'||*(pnapis+i)=='d'){line(); dot(); dot(); nextline();}
		else if (*(pnapis+i)=='E'||*(pnapis+i)=='e'){dot(); nextline();}
		else if (*(pnapis+i)=='F'||*(pnapis+i)=='f'){dot(); dot(); line(); dot(); nextline();}
		else if (*(pnapis+i)=='G'||*(pnapis+i)=='g'){line(); line(); dot(); nextline();}
		else if (*(pnapis+i)=='H'||*(pnapis+i)=='h'){dot(); dot(); dot(); dot(); nextline();}
		else if (*(pnapis+i)=='I'||*(pnapis+i)=='i'){dot(); dot(); nextline();}
		else if (*(pnapis+i)=='J'||*(pnapis+i)=='j'){dot(); line(); line(); line(); nextline();}
		else if (*(pnapis+i)=='K'||*(pnapis+i)=='k'){line(); dot(); line(); nextline();}
		else if (*(pnapis+i)=='L'||*(pnapis+i)=='l'){dot(); line(); dot(); dot(); nextline();}
		else if (*(pnapis+i)=='M'||*(pnapis+i)=='m'){line(); line(); nextline();}
		else if (*(pnapis+i)=='N'||*(pnapis+i)=='n'){line(); dot(); nextline();}
		else if (*(pnapis+i)=='O'||*(pnapis+i)=='o'){line(); line(); line(); nextline();}
		else if (*(pnapis+i)=='P'||*(pnapis+i)=='p'){dot(); line(); line(); dot(); nextline();}
		else if (*(pnapis+i)=='Q'||*(pnapis+i)=='q'){line(); line(); dot(); line(); nextline();}
		else if (*(pnapis+i)=='R'||*(pnapis+i)=='r'){dot(); line(); dot(); nextline();}
		else if (*(pnapis+i)=='S'||*(pnapis+i)=='s'){dot(); dot(); dot(); nextline();}
		else if (*(pnapis+i)=='T'||*(pnapis+i)=='t'){line(); nextline();}
		else if (*(pnapis+i)=='U'||*(pnapis+i)=='u'){dot(); dot(); line(); nextline();}
		else if (*(pnapis+i)=='V'||*(pnapis+i)=='v'){dot(); dot(); dot(); line(); nextline();}
		else if (*(pnapis+i)=='W'||*(pnapis+i)=='w'){dot(); line(); line(); nextline();}
		else if (*(pnapis+i)=='X'||*(pnapis+i)=='x'){line(); dot(); dot(); line(); nextline();}
		else if (*(pnapis+i)=='Y'||*(pnapis+i)=='y'){line(); dot(); line(); line(); nextline();}
		else if (*(pnapis+i)=='Z'||*(pnapis+i)=='z'){line(); line(); dot(); dot(); nextline();}
						  else if (*(pnapis+i)=='-'){space(); nextline();} 	
	}
}

void dot(){
	
	std::cout << ".";
}

void line(){
	
	std::cout << "_";
}

void nextline(){
	
	std::cout << "|";
}

void space(){
	
	std::cout << "    ";
}


int main(){
	
	int n;
	std::cin >> n;
	
	char napis[n];
	const char *pnapis = &napis[0];
	
	void (*pdot)() = &dot;
	void (*pline)() = &line;
	void (*pnextline)() = &nextline;
	void (*pspace)() = &space;
	
	for(int i=0; i<n; i++) std::cin >> napis[i];
	
	std::cout << "|";
	
	morse(pnapis, n, dot, line, nextline, space);
	
	return 0;
}






