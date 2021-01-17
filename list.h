#include "array.h"
template<class X>
class list
{
    private:
    int size;
    Array<int>* array;
    list<X>* next;
    list<X>* prev;
    
    
    public:
    
    list(){
        size=-1;
        next=nullptr;
        prev=nullptr;
        array=nullptr;
    }
    list(list<X>* pre,Array<int>* arr){
        array=arr;
        prev=pre;
        size=0;
        next=nullptr;
    }
    ~list(){
        delete array;
        if(next!=nullptr)
            delete next;
        if(prev!=nullptr)
            delete prev;
    }
    void insert(Array<int>* arr){
        if(size==-1){
            array=arr;
            size=0;
        }else if(size==0){
            next=new list(this,arr);
            size+=1;
        }
        else{
            next->insert(arr);
            size+=1;
        }
    }
    void insertList(list<X>* in){
        if(size==-1){
            array=in->array;
            size=0;
        }else if(size==0){
            next=in;
            size+=1;
        }
        else{
            next->insertList(in);
            size+=1;
        }
    }
    list<X>* getNext(){
        return next;
    }
    list<X>* remove(int num){
        if(array->getCourseNum()==num){//if this is the item-remove the item from the list
            if(prev!=nullptr){
                prev->next=this->next;
                next->prev=this->prev;
                delete this;
            }else{
                delete array;
                if(next!=nullptr){
                    next->prev=nullptr;
                    return next;
                }else{
                    return nullptr;
                }
            }
            
        }else{
            if(next==nullptr)
                return nullptr;//return 1 if the item does not  exist in the list
            next->remove(num);
        }
        return this;
    }
    Array<int>* getItem(int num){
        if(size==-1){
            return nullptr;
        }
         if(array->getCourseNum()==num){//if this is the item-remove the item from the list 
            return array;
         }else{
            if(next==nullptr)
                return nullptr;//return null if the item is not in the list
            return next->getItem(num);
         }
         return nullptr;//this will never happen, here just for the warning
    }    
    Array<int>* getArray(){
        return array;
    }
    int getSize(){
        return size;
    }


};
    
