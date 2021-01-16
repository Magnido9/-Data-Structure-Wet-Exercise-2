#ifndef HASH_TABLE 
#define HASH_TABLE


#include "list.h"
#include "Array.h" 
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
    table = new list<Array<int>*>[size]; 
} 
  
void hashTable::insertItem(int course_number,Array<int>* array) 
{ 
    int index = hashFunction(course_number); 
    if(table[index]==nullptr){//if the list is empty, create a new list
        table[index]=new list(nullptr,array);
    }else{//otherwise, add the item to the list
        table[index].insert(array);  
    }
} 
  
int hashTable::deleteItem(int course_number) 
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number); 
  int i=0;
  // find the course in the hash table
  list <Array<int>*> *t=table[index];// a temporary pointer to travel the list 
  for (i = 0; i< table[index].size(); i++) { 
    if (t.getArray().getCourseNum() == course_number) 
      break; 
    t=t.getNext();
  } 
  
  // if we found the course- remove it
  if (i != table[index].size()-1) 
    return table[index].remove(l->array->getCourseNum());//return 0 if the course was foudn and 1 otherwise
} 
Array<int>* getItem(int course_number)
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number);
  return table[index].getArr(course_number);//get the item from the list
} 
#endif
