#include "cmdlinefns.h" //Functions specific to this main command line program, the Hash table class is included in the cmdlinefns.h file.
#include <fstream> // Only needed for Predefined Test, gives ability to use file input and output.


/**Note:
This program uses some C++11 functions for string->data conversion.
For some older gcc compilers, please use flag -std=c++0x or -std=c++11 
to compile if it prints errors related to functions not being part of std.**/

/** Description: 
This is the user interface program that links to the hashTable and
cmdlinefns files for implementing hashtables specially defined by the user. Contains 
two primary modes, Predefined Test and Manual Input Test. Predefined test takes in 
values from the supplied test.txt file and generates a hashtable from it. Manual Input
Test puts you in control of making a hashtable, and you are given a blank hashtable to
work with. **/


int main(){
	/** Initializing variables that will be used for user choices **/
	string tmp;
	unsigned int sel;
	unsigned int type;
	
	Start: cout << "1 - Predefined Test" << endl << "2 - Manual Input Test" << endl << "Selection: ";
	getline(cin, tmp); type = std::stoul(tmp,nullptr);
	/*********** PREDEFINED TEST ************/
	if(type == 1){
		cout << "Constructing a predefined float hashtable of size 100 and 100 inputs with randomized keys that can be found in test.txt\n\n" << endl;
		std::ifstream input;
		hashTBL<float> table(100);
		input.open("./test.txt");  // start input of data. test.txt MUST be in same folder as executable.
		if(!input) { // file couldn't be opened
			std::cerr << "Error: file could not be opened\ntest.txt missing" << endl;
			goto Start;
		} 
	// File Input Function:
	string lineread;
	unsigned int count1, count2;
	while(!input.eof()){
		lineread = "";    
		getline(input, lineread);
		count1 = 0;  //Initial pos of text
		count2 = 0;  //length of text
		float ftmp;
		string fstr;
	    for(unsigned int trav = 0; trav < lineread.length(); trav++){    //string splicer
         count2++;
         if (lineread.substr(trav, 1).compare(" ") == 0){
			ftmp = std::stof(lineread.substr(count1,count2-1),nullptr);
		 count1 = trav+2;
         count2 = -1;
		 continue;
		 }
		 if (lineread.substr(trav, 1).compare(",") == 0){
			fstr = lineread.substr(count1,count2-1);
			table.set(ftmp,fstr);
			break;		
			}
		}
	}
	// User Interface with Predefined Hash Table:
	cout << "Hash table built!\n" << endl;
	MainMenu: cout << "Main Menu: \n1 - Insert element in hash table" << endl << "2 - Delete element in hash table" << endl << "3 - Get element from hash table" << endl << "4 - View Load Factor" << endl << "5 - Print Table" << endl << "6 - Quit" << endl << "Selection: ";
			getline(cin,tmp); sel = std::stoul(tmp,nullptr);
			cout << endl;
			switch(sel){
				case 1:goto Insert;
				case 2:goto Delete;
				case 3:goto Get;
				case 4:goto Load;
				case 5:goto Print;
				case 6:goto End;
				default: cout << "Invalid selection" << endl; goto MainMenu;
			}	
			Insert: InsertElem(table); goto MainMenu;
			Delete: DeleteElem(table); goto MainMenu;
			Get: GetElem(table); goto MainMenu;
			Load: cout << "Load Factor: " << table.load()	<< endl; goto MainMenu;
			Print: table.print(); goto MainMenu;
			End: return 0;
	}
	/*********** PREDEFINED TEST ************/
	
	
	
	else if (type == 2) goto manualTest;
	else cout << "Invalid input" << endl; goto Start;

	
	/************** MANUAL TEST **************/
	manualTest:
	unsigned int size;

	cout << "Pick a datatype for the hash table:" << endl;
	cout << "1 - double" << endl << "2 - int" << endl << "3 - char" << endl << "4 - float" << endl << "Choice: ";
	getline(cin, tmp); type = std::stoul(tmp,nullptr);
	cout << "Enter the size of the hash table you wish to construct: ";
	getline(cin, tmp); size = std::stoul(tmp,nullptr);

	switch(type){ //Each type is cased into individual segments so that type initializations dont get too crazy and initializes only what we need.
		case 1: { /**Double**/
	
			hashTBL<double> table(size);
			cout << "Table of size " << size << " was made. \n\n"<< endl;
	
			dMainMenu: cout << "Main Menu: \n1 - Insert element in hash table" << endl << "2 - Delete element in hash table" << endl << "3 - Get element from hash table" << endl << "4 - View Load Factor" << endl << "5 - Print Table" << endl << "6 - Quit" << endl << "Selection: ";
			getline(cin,tmp); sel = std::stoul(tmp,nullptr);
			cout << endl;
			switch(sel){
				case 1:goto dInsert;
				case 2:goto dDelete;
				case 3:goto dGet;
				case 4:goto dLoad;
				case 5:goto dPrint;
				case 6:goto dEnd;
				default: cout << "Invalid selection" << endl; goto dMainMenu;
			}	
			/***** These functions are defined in cmdlinefns.h *****/
			dInsert: InsertElem(table); goto dMainMenu;
			dDelete: DeleteElem(table); goto dMainMenu;
			dGet: GetElem(table); goto dMainMenu;
			dLoad: cout << "Load Factor: " << table.load()	<< endl; goto dMainMenu;
			dPrint: table.print(); goto dMainMenu;
			dEnd: break;
		}
		case 2: { /**Int**/
			hashTBL<int> table(size);
			cout << "Table of size " << size << " was made. \n\n"<< endl;
	
			iMainMenu: cout << "Main Menu: \n1 - Insert element in hash table" << endl << "2 - Delete element in hash table" << endl << "3 - Get element from hash table" << endl << "4 - View Load Factor" << endl << "5 - Print Table" << endl << "6 - Quit" << endl << "Selection: ";
			getline(cin,tmp); sel = std::stoul(tmp,nullptr);
			cout << endl;
			switch(sel){
				case 1:goto iInsert;
				case 2:goto iDelete;
				case 3:goto iGet;
				case 4:goto iLoad;
				case 5:goto iPrint;
				case 6:goto iEnd;
				default: cout << "Invalid selection" << endl; goto iMainMenu;
			}	
			/***** These functions are defined in cmdlinefns.h *****/
			iInsert: InsertElem(table); goto iMainMenu;
			iDelete: DeleteElem(table); goto iMainMenu;
			iGet: GetElem(table); goto iMainMenu;
			iLoad: cout << "Load Factor: " << table.load()	<< endl; goto iMainMenu;
			iPrint: table.print(); goto iMainMenu;
			iEnd: break;
			}
		case 3: { /**Char**/
			hashTBL<char> table(size);
			cout << "Table of size " << size << " was made. \n\n"<< endl;
			
			cMainMenu: cout << "Main Menu: \n1 - Insert element in hash table" << endl << "2 - Delete element in hash table" << endl << "3 - Get element from hash table" << endl << "4 - View Load Factor" << endl << "5 - Print Table" << endl << "6 - Quit" << endl << "Selection: ";
			getline(cin,tmp); sel = std::stoul(tmp,nullptr);
			cout << endl;
			switch(sel){
				case 1:goto cInsert;
				case 2:goto cDelete;
				case 3:goto cGet;
				case 4:goto cLoad;
				case 5:goto cPrint;
				case 6:goto cEnd;
				default: cout << "Invalid selection" << endl; goto cMainMenu;
			}	
			/***** These functions are defined in cmdlinefns.h *****/
			cInsert: InsertElem(table); goto cMainMenu;
			cDelete: DeleteElem(table); goto cMainMenu;
			cGet: GetElem(table); goto cMainMenu;
			cLoad: cout << "Load Factor: " << table.load()	<< endl; goto cMainMenu;
			cPrint: table.print(); goto cMainMenu;
			cEnd: break;
			}
	
		case 4:{ /**Float**/
			hashTBL<float> table(size);
			cout << "Table of size " << size << " was made. \n\n"<< endl;
	
			fMainMenu: cout << "Main Menu: \n1 - Insert element in hash table" << endl << "2 - Delete element in hash table" << endl << "3 - Get element from hash table" << endl << "4 - View Load Factor" << endl << "5 - Print Table" << endl << "6 - Quit" << endl << "Selection: ";
			getline(cin,tmp); sel = std::stoul(tmp,nullptr);
			cout << endl;
			switch(sel){
				case 1:goto fInsert;
				case 2:goto fDelete;
				case 3:goto fGet;
				case 4:goto fLoad;
				case 5:goto fPrint;
				case 6:goto fEnd;
				default: cout << "Invalid selection" << endl; goto fMainMenu;
			}	
			/***** These functions are defined in cmdlinefns.h *****/
			fInsert: InsertElem(table); goto fMainMenu;
			fDelete: DeleteElem(table); goto fMainMenu;
			fGet: GetElem(table); goto fMainMenu;
			fLoad: cout << "Load Factor: " << table.load()	<< endl; goto fMainMenu;
			fPrint: table.print(); goto fMainMenu;
			fEnd: break;
		}
	};	
	/************** MANUAL TEST **************/
	return 0;
}
