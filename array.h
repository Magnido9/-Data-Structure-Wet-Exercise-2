#ifndef ARRAY_H
#define ARRAY_H

#define INITIAL_VALUE 0
#define NEW_SIZE 2
#define START_SIZE 100

#include <exception>
template<class X>
class Array
{
    X* arr;
    
    int current_size;
    int used_cells;
    int number_of_classes;
    int course_number;

    public:
    Array(int course_number):current_size(START_SIZE),used_cells(0), number_of_classes(0),course_number(course_number)
    {
        arr=new X[START_SIZE]{0};
    
    }
    ~Array()
    {
        if(arr!=nullptr)
            delete[] arr;
        
    }
    X at(int i)const;
    X& operator [](int i);
    void push (X value);
    bool is_initialized(int i)const ;
    void addClass();
    int getCourseNum();
    int getNumOfClasses();
    int getNumOfUndifined();

};


template <class X>
X Array<X>::at(int i)const
{
    if(i>=number_of_classes)
    {
        throw std::exception();
    }
    
        return arr[i];
    
    

}

template <class X>
X& Array<X>::operator [](int i)
{   if(i>=number_of_classes)
    {
        throw std::exception();
    }
    if(i>=current_size)
    {
        X* temp=new X[current_size*NEW_SIZE];
        
        
        for(int j=0;j<current_size;j++)
        {
            temp[j]=arr[j];
           
        }
        delete[] arr;
        
        arr=temp;
        for(int j=current_size;j<current_size*NEW_SIZE;j++){
            arr[j]=0;
        }
        current_size=current_size*NEW_SIZE;

    }
    if(arr[i]==0)
    {
        used_cells++;
    }
    return arr[i];
}

//to increase the number of classes in this coures by 1
template<class X>
void Array<X>::addClass()
{
    number_of_classes++;
}

template<class X>
 int Array<X>::getCourseNum()
 {
     return course_number;
 }

 template<class X>
 int Array<X>::getNumOfClasses()
 {
     return number_of_classes;
 }

template<class X>
int Array<X>::getNumOfUndifined()
{
    return number_of_classes-used_cells;
}


#endif