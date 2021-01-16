#include"library2.h"
#include"CoursesManager.h"
#include <stdio.h>
#include <iostream>
void *Init(){
    return new CoursesManager();
}

StatusType AddCourse (void *DS, int courseID)
{
    if(DS==nullptr||courseID<=0)
    {
        return INVALID_INPUT;
    }
    if(((CoursesManager*)DS)->courseExsit(courseID))//log(N) N-courses in struct
    {
        return FAILURE;
    }
    else
    {
        try
        {
            ((CoursesManager*)DS)->addCourse(courseID);//O(numOfClassses+log(N))
        }
        catch(const std::bad_alloc& e)
        {
             return ALLOCATION_ERROR;
        }
        catch(const std::exception& e)// i don't think it will get here
        {
            return INVALID_INPUT;
        }
        
    }
    return SUCCESS;
    
}

StatusType AddClass(void* DS, int courseID, int* classID)
{
    if(DS==nullptr||courseID<=0)
    {
        return INVALID_INPUT;
    }
    if(!((CoursesManager*)DS)->courseExsit(courseID))//o(1)
    {
         return FAILURE;
    }
    try{
        *classID=((CoursesManager*)DS)->numOfClasses(courseID);
        ((CoursesManager*)DS)->addClass(courseID);
    }
    catch(const std::bad_alloc& e)
    {
            return ALLOCATION_ERROR;
    }
    

    return SUCCESS;
}    


StatusType RemoveCourse(void *DS, int courseID){
    if(DS==nullptr||courseID<=0)
    {
        return INVALID_INPUT;
    }
    if(!((CoursesManager*)DS)->courseExsit(courseID))//O(1)
    {
        return FAILURE;
    }
    try
    {
        ((CoursesManager*)DS)->removeCourse(courseID);
    }
    catch(const std::bad_alloc& e)
    {
            return ALLOCATION_ERROR;
    }
    return SUCCESS;
    
}

StatusType WatchClass(void *DS, int courseID, int classID, int time)
{
    if(time<=0||DS==nullptr||courseID<=0||classID<0)
    {
        return INVALID_INPUT;
    }

    if(!((CoursesManager*)DS)->courseExsit(courseID))//O(log(N). N- number of courses(<<num of classes)
    {
        return FAILURE;
    }

    if(!((CoursesManager*)DS)->classExisitInCourse(courseID,classID))//o(log(N))
    {
        return INVALID_INPUT;
    }
    else
    {
        try
        {
            ((CoursesManager*)DS)->addWatch(courseID,classID,time);//o(log(N)+log(M))
        }
        catch(const std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
        catch(const std::exception& e)
        {
            return INVALID_INPUT;
        }


    }
    return SUCCESS;
    
    
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed){
    if(DS==nullptr||courseID<=0||classID<0)
    {
        return INVALID_INPUT;
    }
    if(!((CoursesManager*)DS)->courseExsit(courseID))//O(log(N). N- number of courses(<<num of classes)
    {
        return FAILURE;
    }
    if(((CoursesManager*)DS)->numOfClasses(courseID)<classID+1)
    {
        return INVALID_INPUT;
    }
    try
    {
        *timeViewed=(((CoursesManager*)DS)->getTimeViewed(courseID,classID));
    }
    catch(const std::bad_alloc& e)
    {
            return ALLOCATION_ERROR;
    }
    
    return SUCCESS;

}
StatusType GetIthWatchedClass(void* DS, int i, int* courseID, int* classID)
{
    if(DS==nullptr||i<=0)
    {
        return INVALID_INPUT;
    }
    if(((CoursesManager*)DS)->getWatchedClasses()<i)
    {
        return FAILURE;
    }
    else
    {
        try
        {
            ((CoursesManager*)DS)->getMostWatched(i,courseID,classID);
        }
        catch(const std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
        catch(const std::exception& e)
        {
            return INVALID_INPUT;
        }
        
    }
    return SUCCESS;


}


void Quit(void** DS){
    delete (CoursesManager*)*DS;
    *DS=nullptr;

}

