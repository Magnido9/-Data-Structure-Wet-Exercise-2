#ifndef HASH_TABLE 
#define HASH_TABLE


#include "list.h"
#include "array.h" 

  
class hashTable // a class for a Linked List implemantation of an hash table
{ 
    int size;    // amount of lists in the hash table 
    list<int> *table; //The hash table- maps course number to its "double array" that contains the lessons and some data about it
public: 
    hashTable(int size);  // Constructor 
    ~hashTable();
    // insert a course into the hash table 
    void insertItem(int course_number,Array<int>* array); 
  
    // delete a course from the hash table 
    int deleteItem(int course_number); 
  
    // basic modulo hash function to map values to key 
    int hashFunction(int x) { 
        return (x % size); 
    }
    Array<int>* getItem(int course_number); 


}; 
  
hashTable::hashTable(int size) 
{ 
    this->size =size; 
    table = new list<int>[size]; 
} 

hashTable::~hashTable()
{
  delete[] table;
}
  
void hashTable::insertItem(int course_number,Array<int>* array) 
{ 
    int index = hashFunction(course_number); 
    table[index].insert(array);  
    
} 
  
int hashTable::deleteItem(int course_number) 
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number); 
  return table[index].remove(course_number);
} 
Array<int>* hashTable::getItem(int course_number)
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number);
  if(table[index].getListSize()==0)//empty list
  {
    return nullptr;
  }
  else{
  return table[index].getItem(course_number);//get the item from the list
  }
} 
#endif
