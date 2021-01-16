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
    list(list<X>* pre,Array<X>* arr){
        array=arr;
        prev=pre;
        size=0;
    }
    ~list(){
        ~this->array;
        delete array
        if(next!=nullptr)
            ~this->next;
            delete next;
        if(prev!=nullptr)
            ~this->prev;
            delete prev;
    }
    void insert(Array<X>* arr){
        if(size==0){
            next=new list(this,arr);
            size+=1;
        }
        else{
            next->push_back(arr);
            size+=1;
        }
    }
    list<X>* getNext(){
        return next;
    }
    int remove(int num){
        if(array->getCourseNum()==num){//if this is the item-remove the item from the list 
            prev->next=this->next;
            next->prev=this->prev;
            delte this;
        }else{
            if(next==nullptr)
                return 1;//return 1 if the item does not  exist in the list
            next->remove(l);
        }
        return 0;
    }
    Array<X>* getItem(int num){
         if(array->getCourseNum()==num){//if this is the item-remove the item from the list 
            return array;
         }else{
            if(next==nullptr)
                return nullptr;//return null if the item is not in the list
            next->getItem(num);
         }
    }

};
    
