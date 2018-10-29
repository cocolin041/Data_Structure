# Hash Table

## Create a hash function
Function: ```int hashFunction(string s, int M)```
@param - M: size of hashing table<br>
@param - s: input string<br>
return index of where the string should be placed in the hash table, the index will be the sum the ASCII values of the letters in the string<br>

## check how many collisions with a given hash table size
Function: ```int countCollisions (int M, vector<string> inputs)```
@param - M: size of hashing table<br>
@param - s: input a vector of strings<br>
everytime collision happens, the number of collision will be increased by one
return the total number of collision with a given hash table size after these strings being input