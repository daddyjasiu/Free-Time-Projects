#include <iostream>
#include <string>

using namespace std;
void tree(int *rozmiar){
	
	std::cout << std::endl << std::endl <<" X LIKE A BEAUTIFUL XMAS TREE!" << std::endl << std::endl; 
	int stars = 1;
	int pienw = *rozmiar/3;
	int piensz = *rozmiar/2;

	for( int total=*rozmiar; total>0; total--)
	{
		
		for(int i=(total-1); i>0; i--)
			std::cout << " ";

		for(int j=0; j<stars ; j++)
			std::cout << "*";

		stars = stars + 2;

		std::cout << std::endl;
	}


	//pien
	for(int i=0; i<pienw; i++)
	{
		//odstepy do srodka choinki
		for(int j=0; j<(*rozmiar-(piensz-(piensz/2))); j++)
			std::cout << " ";

		for(int k=0; k<piensz; k++)
			std::cout << "*";

		std::cout << '\n';
	}	
}

void carol(int *number){
	
	if(*number==1){
		
		std::cout << std::endl << std::endl << "M LIKE MUSIC! LET'S SING TOGETHER!" << std::endl << std::endl;
		std::cout << "We wish you a Merry Christmas" << std::endl <<
					 "We wish you a Merry Christmas" << std::endl <<
					 "We wish you a Merry Christmas and a happy New Year" << std::endl <<
					 "Good tidings we bring to you and your kin" << std::endl <<
					 "We wish you a Merry Christmas and a happy New Year" << std::endl << std::endl <<
					 
					 "Oh, bring us some figgy pudding" << std::endl <<
					 "Oh, bring us some figgy pudding" << std::endl <<
					 "Oh, bring us some figgy pudding" << std::endl <<
					 "And bring it right here" << std::endl << std::endl <<
					 
					 "Good tidings we bring to you and your kin" << std::endl <<
					 "We wish you a Merry Christmas and a happy New Year" << std::endl <<
					 "We won't go until we get some" << std::endl <<
					 "We won't go until we get some" << std::endl <<
					 "We won't go until we get some" << std::endl <<
					 "So bring it right here" << std::endl << std::endl <<
					 
					 "Good tidings we bring to you and your kin" << std::endl <<
					 "We wish you a Merry Christmas and a happy New Year" << std::endl <<
					 "We all like our figgy pudding" << std::endl <<
					 "We all like our figgy pudding" << std::endl <<
					 "We all like our figgy pudding" << std::endl <<
					 "With all its good cheers" << std::endl << std::endl <<
					 
					 "Good tidings we bring to you and your kin" << std::endl <<
					 "We wish you a Merry Christmas and a happy New Year" << std::endl <<
					 "We wish you a Merry Christmas" << std::endl <<
					 "We wish you a Merry Christmas" << std::endl <<
					 "We wish you a Merry Christmas and a happy New Year";
	}
	
	else if(*number==2){
		
		std::cout << std::endl << std::endl << "M LIKE MUSIC! LET'S SING TOGETHER!" << std::endl << std::endl;
		std::cout << "Jingle bells, jingle bells," << std::endl <<
					 "Jingle all the way." << std::endl <<
					 "Oh! what fun it is to ride" << std::endl <<
					 "In a one-horse open sleigh." << std::endl <<
					 "Jingle bells, jingle bells," << std::endl <<
					 "Jingle all the way;" << std::endl <<
					 "Oh! what fun it is to ride" << std::endl <<
					 "In a one-horse open sleigh." << std::endl << std::endl <<
					 
					 "Dashing through the snow" << std::endl <<
					 "In a one-horse open sleigh" << std::endl <<
					 "Over the fields we go" << std::endl <<
					 "Laughing all the way" << std::endl <<
					 "Bells on bobtail ring" << std::endl <<
					 "Making spirits bright" << std::endl <<
					 "What fun it is to laugh and sing" << std::endl <<
					 "A sleighing song tonight!" << std::endl << std::endl <<
					 
					 "Jingle bells, jingle bells," << std::endl <<
					 "Jingle all the way." << std::endl <<
					 "Oh! what fun it is to ride" << std::endl <<
					 "In a one-horse open sleigh." << std::endl <<
					 "Jingle bells, jingle bells," << std::endl <<
					 "Jingle all the way;" << std::endl <<
					 "Oh! what fun it is to ride" << std::endl <<
					 "In a one-horse open sleigh." << std::endl << std::endl;
		
	}
	
	else if(*number==3){
		
		std::cout << std::endl << std::endl << "M LIKE MUSIC! LET'S SING TOGETHER!" << std::endl << std::endl;
		std::cout << "Twinkle, twinkle, little star" << std::endl <<
					 "How I wonder what you are" << std::endl <<
					 "Up above the world so high" << std::endl <<
					 "Like a diamond in the sky" << std::endl <<
					 "Twinkle, twinkle little star" << std::endl <<
					 "How I wonder what you are" << std::endl << std::endl <<
					 
					 "When the blazing sun is gone" << std::endl <<
					 "When he nothing shines upon" << std::endl <<
					 "Then you show your little light" << std::endl <<
					 "Twinkle, twinkle, all the night" << std::endl <<
					 "Twinkle, twinkle, little star" << std::endl <<
					 "How I wonder what you are" << std::endl << std::endl;		 
		
	}
	
}

void postcard(){
	
	cout << endl << endl <<"                      S LIKE SENDING!" << endl << endl;
	cout<<"#############################################################"<<endl;
	cout<<"#           *      * _     *           *               *    #"<<endl;  
	cout<<"#   *              -=\\`\\    SANTA IN A PLANE   *            #"<<endl;  
	cout<<"#              |\\ ____\\_\\__                            *    #"<<endl;  
	cout<<"#        *   -=\\c`\"\"\"\"\"\"\" \"`)   *               *           #"<<endl;  
	cout<<"#  *            `~~~~~/ /~~`\         *    *                 #"<<endl; 
	cout<<"#            *    -==/ /                                 *  #"<<endl;  
	cout<<"#     *             '-'       *    PRESENTS ON THE WAY!     #"<<endl;  
	cout<<"#                 *_  _                                     #"<<endl;  
	cout<<"#          *      ( `   )_    *     *           *     *     #"<<endl;  
	cout<<"#                (    )    `)             *               * #"<<endl;  
	cout<<"#    *         (_   (_ .  _) _)               *      *      #"<<endl;  
	cout<<"#                                    *        _             #"<<endl;  
	cout<<"# *        *        *        *               (  )      *    #"<<endl;  
	cout<<"#             _ .       from: Me      *   ( `  ) . )        #"<<endl;  
	cout<<"#    *      (  _ )_    to: Mr Jureczko   (_, _(  ,_)_)      #"<<endl;  
	cout<<"#       * (_  _(_ ,)  *         *            *         *    #"<<endl;  
	cout<<"#############################################################"<<endl;
}

void naughtyornice(std::string *pname, int *pnice, int *pnaughty){
	
	std::string what;
	
	if(*pnice>*pnaughty) what = "NICE";
	else if(*pnaughty>*pnice) what = "NAUGHTY";
	else what = "EQUAL";
	
	cout << endl << *pname << "... YOU'VE BEEN " << what << "!";
	
}

int main(){
	
	char letter;
	char* let = &letter;
	
do{
	
	std::cout << "CHRISTMAS 2019! PICK A LETTER (X,M,A or S): ";
	std::cin >> letter;
	
	if(*let=='X'){
		int rozmiar = 13;
		int *size = &rozmiar;
		tree(size);
	}
	
	else if(*let=='M'){
		
		int number;
		std::cout << "PICK A NUMBER (1-3): ";
		std::cin >> number;
		int *num=&number;
		carol(num);
	}
	
	else if(*let=='A'){
	
		std::string name;
		int nice;
		int naughty;
		
		std::string *pname = &name;
		int *pnice = &nice;
		int *pnaughty = &naughty;
		
		cout << endl << endl;
		cout << "A LIKE ATTITUDE! LET'S SEE IF YOU'VE BEEN NICE THIS YEAR!" << endl << endl;
		cout <<	"ENTER YOU NAME: ";
		cin >> name;
		cout << "HOW MANY TIMES HAVE YOU BEEN NICE? ";
		cin >> nice;
		cout << "HOW MANY TIMES HAVE YOU BEEN NAUGHTY? ";
		cin >> naughty;
		
		naughtyornice(pname, pnice, pnaughty);		
	}
	
	else if(*let=='S'){
		
		postcard();
	}
	
	cin.get();
	cin.ignore();
	system("CLS");
	
}while(*let!='Q');
	
	return 0;
}











