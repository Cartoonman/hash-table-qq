#pragma once

#include "hashTable.h" // The hashtable class is here
#include <iostream> // Necessary for any type of I/O interface
using std::string; // std::string is needed to use strings
/** very basic I/O functions for input and output **/
using std::cout;
using std::endl;
using std::cin;

/** Description: 
This file defines specific User Interface functions for use with the main program. This bridges the gap between
main and the hashTable class, controlling for specific data types and particular inputs. This isn't necessary for
using the hashTable.h class, this only makes it convenient to input custom values for what you want.**/

template<typename T>
bool InsertElem(T& s) //This is a template for the hashTable.get() function. The following below are specialized templates for specific input types. This particular one should ideally never run, as all types are well defined by main and are given specialization templates below.

{
    std::cerr << "Error" << '\n';
}

template<> 
bool InsertElem(hashTBL<double>& TBL) // Double Specialization
{
    double a;
	bool b;
	string s = "";
	cout << "Enter a double-type value you wish to insert: ";
	getline(cin,s);
	a = std::stod(s,nullptr);
	cout << endl << "Enter the string key associated with the data: ";
	getline(cin,s); 
	cout << endl << "Insert Status: ";
	b = TBL.set(a,s);
	b ? cout << "Success" << endl : cout << "Failure, an element already exists at the given location." << endl;
	return b;
}

template<> 
bool InsertElem(hashTBL<int>& TBL) // Int Specialization
{
    int a;
	bool b;
	string s = "";
	cout << "Enter a int-type value you wish to insert:";
	getline(cin,s);
	a = std::stoi(s,nullptr);
	cout << endl << "Enter the string key associated with the data: ";
	getline(cin,s); 
	cout << endl << "Insert Status: ";
	b = TBL.set(a,s);
	b ? cout << "Success" << endl : cout << "Failure, an element already exists at the given location." << endl;	
	return b;
}

template<> 
bool InsertElem(hashTBL<char>& TBL) // Char Specialization
{
    char a;
	bool b;
	string s = "";
	cout << "Enter a char-type value you wish to insert: ";
	getline(cin,s);
	a = s.c_str()[0];
	cout << endl << "Enter the string key associated with the data: ";
	getline(cin,s); 
	cout << endl << "Insert Status: ";
	b = TBL.set(a,s);
	b ? cout << "Success" << endl : cout << "Failure, an element already exists at the given location." << endl;
	return b;
}


template<> 
bool InsertElem(hashTBL<float>& TBL) // Float Specialization
{
    float a;
	bool b;
	string s = "";
	cout << "Enter a float-type value you wish to insert: ";
	getline(cin,s);
	a = std::stof(s,nullptr);
	cout << endl << "Enter the string key associated with the data: ";
	getline(cin,s); 
	cout << endl << "Insert Status: ";
	b = TBL.set(a,s);
	b ? cout << "Success" << endl : cout << "Failure, an element already exists at the given location." << endl;	
	return b;
}

template<typename C> 
C GetElem(hashTBL<C>& TBL) // A generalized function for hashTable.get()
{
	C a;
	string s = "";
	cout << "Enter the key of the data you wish to retrieve: ";
	getline(cin,s);
	cout << endl;
	a = TBL.get(s);
	a ? cout << "Success, element retrieved is: " << a << endl : cout << "Failure. Element not found" << endl;
	return a;
}

template<typename D> 
D DeleteElem(hashTBL<D>& TBL) // A generalized function for hashTable.deleteDat()
{
	D a;
	string s = "";
	cout << "Enter the key of the data you wish to delete: ";
	getline(cin,s);
	cout << endl;
	a = TBL.deleteDat(s);
	a ? cout << "Success, element deleted is: " << a << endl : cout << "Failure. No element to delete" << endl;
	return a;
}
