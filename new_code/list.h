#ifndef LIST_H
#define LIST_H

#include "array.h"
template<class X>
class list
{
    private:
    int size;
    Array<X>* array;
    list<X>* next;
    list<X>* prev;
    
    
    public:
    list()
    {
        size=0;
        array=nullptr;
        next=nullptr;
        prev=nullptr;

    }
    // list(list<X>* pre,Array<X>* arr){
    //     array=arr;
    //     prev=pre;
    //     size=1;
    // }
    ~list(){
        
        delete array;
        array=nullptr;
        if(next!=nullptr)
            delete next;
        
    }
    void insert(Array<X>* arr){
        if(size==0){
            array=arr;
            size+=1;
        }
        else{
            list<X>* temp=new list<X>;
            list<X>* list_end=this; 
            
            while (list_end->next!=nullptr)
            {
                list_end=list_end->next;
            }
            list_end->next=temp;
            temp->prev=list_end;
            
            size+=1;

        }
    }
    list<X>* getNext(){
        return next;
    }
    int remove(int num){
        if(size==0)// empty list
        {
            return 1;
        }
        if(array->getCourseNum()==num){//if this is the item-remove the item from the list 
            prev->next=this->next;
            next->prev=this->prev;
            delete this;
        }else{
            if(next==nullptr)
                return 1;//return 1 if the item does not  exist in the list
            next->remove(num);
        }
        return 0;
        /*
        list<X>* to_delete=this;
        
        while(to_delete->array->getCourseNum()!=num)
        {   
            if(to_delete->next==nullptr)
            {
                return 1;
            }
            else
            {
                to_delete=to_delete->next;
            }  
        }
        list<X>* next_list=to_delete->next;
        delete to_delete->array;
        to_delete->array=nullptr;

        while (next_list!=nullptr)
        {
            to_delete->array=next_list->array;
            to_delete=next_list;
            next_list=next_list->next;
        }
        if(to_delete->prev!=nullptr)
        {
            to_delete->prev->next=nullptr;
        }
        delete to_delete;
        size--;
        return 0;*/

    }
    Array<X>* getItem(int num){
        if(size==0)//fail, no elements in list;
        {
            return nullptr;
        }
         if(array->getCourseNum()==num){//if this is the item-remove the item from the list 
            return array;
         }else{
            if(next==nullptr)
                return nullptr;//return null if the item is not in the list
            next->getItem(num);
         }
        return nullptr;
    }

    int getListSize()
    {
        return size;
    }

};

#endif
    
