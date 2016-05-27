#include <iostream> // Necessary for any type of I/O interface
/** very basic I/O functions for input and output **/
using std::string;
using std::cout;
using std::endl;

/** Description: This is the main file that contains both the string hash 
function and the hash table class. This is the core of the program.**/


/**
The following hash function is an prime number based bitwise XOR function that 
uses a char pointer to traverse the string while calculating a hash value 
that will be used in modulo of the given hashtable size. 

This function was borrowed from a source on the internet,
Author of this function: *** http://stackoverflow.com/a/8317622 ***

This function was chosen specifically for its excellent performance with
an input that wasn't uniformly distributed (e.g. input keys 'a', 'b', 'c', 'd',... etc and
have it map to pseudorandom locations while keeping collisions relatively low)
as well as it's O(n) runtime and simplicity.
**/

/**************************************************************/
#define A 71453
#define B 97861
unsigned long stringHash(const char* s,unsigned int sizeArray)
{
   unsigned h = 53; // prime seed
   while (*s) {
	   h = (h * A) ^ (s[0] * B); // bitwise XOR
	   s++; // increment pointer
	   }
   return (h%sizeArray);
}
/**************************************************************/



/**This is the class that implements the static hash table**/
template <typename T>
class hashTBL
{
	T* t; // Open-ended Datatype for Hash Table
	unsigned int S;	// size of hash table
	unsigned int elemCount; // number of elements in table
    public:
	
		// constructor(size), constructs new hash table with given size, all elements set to null, and initialize element count to 0.
		hashTBL(unsigned int size){t = new T[size](); S = size; elemCount = 0;}
		
		// boolean set(key, value). Inserts data with given key. inserts and returns true if spot is empty, returns false if item exists in the spot.
        bool set(T dat,string key){unsigned long keyVAL = stringHash(key.c_str(),S); return(t[keyVAL] ? false : (t[keyVAL] = dat) && ++elemCount);}
		
		// get(key) Retrieves the item at the given key location. Returns the element in the table or 0 if its empty.
	    T get(string key){return t[stringHash(key.c_str(),S)];} 
		
		// delete(key). Uses key to find elemet in table and deletes it if it exists. Returns the data element if found and deleted, otherwise returns 0 if not found.
		T deleteDat(string key){unsigned long keyVAL = stringHash(key.c_str(),S); T tmp; if(t[keyVAL]){t[keyVAL] = ((tmp = t[keyVAL]) == --elemCount-elemCount); return tmp;} return 0;}
		
		// float load(). returns the load factor using elemCount and table size S.
		float load(){cout << "Elements in Table: " << elemCount << endl; cout << "Size of Table: " << S << endl; return( (float)elemCount / (float)S);} 
		
		// A print function that simply prints out the table's contents to see what the hash table looks like with the elements inside.
		void print(){for (unsigned int i = 0;i < S; i++){cout << i+1 << " - " << t[i] << endl;}}
};