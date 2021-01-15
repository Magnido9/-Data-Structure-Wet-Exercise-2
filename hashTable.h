#ifndef HASH_TABLE 
#define HASH_TABLE


#include <bits/stdc++.h>
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
    void deleteItem(int course_number); 
  
    // basic modulo hash function to map values to key 
    int hashFunction(int x) { 
        return (x % size); 
    } 
}; 
  
hashTable::hashTable(int size) 
{ 
    this->size =size; 
    table = new list<Array<int>*>[size]; 
} 
  
void hashTable::insertItem(int course_number,Array<int>* array) 
{ 
    int index = hashFunction(course_number); 
    table[index].push_back(array);  
} 
  
void hashTable::deleteItem(int course_number) 
{ 
  // get the hash index of course number 
  int index = hashFunction(course_number); 
  
  // find the course in the hash table
  list <Array<int>*> :: iterator i; 
  for (i = table[index].begin(); i != table[index].end(); i++) { 
    if ((*i)->getCourseNum() == course_number) 
      break; 
  } 
  
  // if we found the course- remove it
  if (i != table[index].end()) 
    table[index].erase(i); 
} 

#endif
