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
        if(size==-1)
            return;
        if(array!=nullptr)
            delete array;
        if(next!=nullptr)
            delete next;
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
        if(in==nullptr){
            return;
        }
        if(size==-1){
            array=in->array;
            size=0;
        }else if(size==0){
            next=in;
            next->size=0;
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
        if(next!=nullptr){ 
            if (this->getArray()->getCourseNum() == num){ 
                
                this->next->prev=nullptr;
                delete array;
                return next;
            }
            list<X>* t=next;
            while(t!=nullptr) { 
                if (t->getArray()->getCourseNum() == num){ 
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    delete t->array;
                    break;
                }
                t->size-=1;
                t=t->getNext();
            }
            return this;
        }
        else{
            delete array;
            this->size=-1;
            array=nullptr;
            return this;
        } /*
        if(array->getCourseNum()==num){//if this is the item-remove the item from the list
            if(prev!=nullptr){
                delete array;
                prev->next=next;
                next->prev=prev;
            }else{
                delete array;
                if(next!=nullptr){
                    next->prev=nullptr;
                    return next;
                }else{
                    return new list();
                }
            }
        }else{
            if(next==nullptr)
                return nullptr;
            next->remove(num);
        }
        return this;*/
    }
    Array<int>* getItem(int num){
        if(size==-1){
            return nullptr;
        }
         if(array==nullptr){
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
    
