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
    int* B;
    int* C;

    int current_size;
    int used_cells;
    int number_of_classes;
    int course_number;

    public:
    Array(int course_number):current_size(START_SIZE),used_cells(0), number_of_classes(0),course_number(course_number)
    {
        arr=new X[START_SIZE];
        B= new int[START_SIZE];
        C=new int[START_SIZE]; 
        
        
        

    }
    ~Array()
    {
        delete[]arr;
        delete[]B;
        delete[]C;
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
    if(this->is_initialized(i))
    {
        return arr[i];
    }
    else
    {
        return INITIAL_VALUE;
    }

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
        int * b_temp= new int[current_size*NEW_SIZE];
        int* c_temp =new int[current_size*NEW_SIZE];
        
        for(int j=0;j<current_size;j++)
        {
            temp[j]=arr[j];
            b_temp[j]=B[j];
            c_temp[j]=C[j];
        }
        delete[] arr;
        delete[]B;
        delete[]C;
        arr=temp;
        B=b_temp;
        C=c_temp;
        current_size=current_size*NEW_SIZE;

    }
    if(!is_initialized(i))
    {
        C[used_cells]=i;
        B[i]=used_cells;
        used_cells++;
    }
    return arr[i];
}
template<class X>
bool Array<X>::is_initialized(int i)const
{
    return(B[i]<used_cells&&B[i]>=0&&C[B[i]]==i);
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

