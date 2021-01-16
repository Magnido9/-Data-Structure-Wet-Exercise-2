#ifndef HASH_TABLE 
#define HASH_TABLE


#include "list.h"
#include "array.h" 
using namespace std; 
  
class hashTable // a class for a Linked List implemantation of an hash table
{ 
    int size;    // amount of lists in the hash table 
    list<Array<int>*> *table; //The hash table- maps course number to its "double array" that contains the lessons and some data about it
public: 
    hashTable(int size);  // Constructor 
  
    // insert a course into the hash table 
    void insertItem(int course_number,Array<int>* array); 
  
    // delete a course from the hash table 
    void deleteItem(int course_number); 
  
    // basic modulo hash function to map values to key 
    int hashFunction(int x) { 
        return (x % size); 
    }
    Array<int>* getItem(int course_number); 
    Array<int>* getArray(); 

}; 
  
hashTable::hashTable(int size) 
{ 
    this->size =size; 
    table = new list<Array<int>*>[size]; 
} 
  
void hashTable::insertItem(int course_number,Array<int>* array) 
{ 
    int index = hashFunction(course_number); 
    table[index].insert(array);  
} 
  
void hashTable::deleteItem(int course_number) 
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number); 
  int i=0;
  // find the course in the hash table
  list <Array<int>*> *t=&table[index];// a temporary pointer to travel the list 
  for (i = 0; i<= table[index].getSize(); i++) { 
    if (t->getArray()->getCourseNum() == course_number) 
      break; 
    t=t->getNext();
  } 
  
  // if we found the course- remove it
  if (i != table[index].getSize()) 
    table[index]=*table[index].remove(t->getArray()->getCourseNum());//return 0 if the course was foudn and 1 otherwise

} 
Array<int>* hashTable::getItem(int course_number)
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number);
  return table[index].getItem(course_number);//get the item from the list
} 
#endif
