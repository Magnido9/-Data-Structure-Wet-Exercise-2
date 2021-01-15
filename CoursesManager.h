#ifndef COURSE_MENAGER
#define COURSE_MENAGER
#include"rank_tree.h"
#include "classTuple.h"
#include"hashTable.h"
#include"node.h"
#include "assert.h"
#define INITIAL_SIZE 100

class CoursesManager
{
private:
    int num_of_courses;
    int total_num_of_classes;
    int num_watched_classes;
    hashTable* courses_array;
    AvlTree<ClassTuple,ClassTuple*>* viewed_classes_tree;
    
    
    
public:
     CoursesManager();
    ~CoursesManager();
    void addCourse(int course_id, int num_of_classes);
    void removeCourse(int course_id);
    void addWatch(int course_id, int class_id, int time_to_add);
    int getTimeViewed(int course_id,int class_id);
    void getMostWatched(int wanted, int* course,int* classes);
    bool courseExsit(int course_id);
    bool classExisitInCourse(int course_id,int class_id);
    int getTotalClasses();
    int numOfClasses(int course_id);

};

CoursesManager::CoursesManager(/* args */)
{
    num_of_courses=0;
    total_num_of_classes=0;
    num_watched_classes=0;
    courses_array=new hashTable(INITIAL_SIZE);
    viewed_classes_tree =new AvlTree<ClassTuple,ClassTuple*>;

}

CoursesManager::~CoursesManager()
{
    delete viewed_classes_tree;
    delete courses_array;
}

/*add a new course to the struct
don't give a course that is in the tree */
void CoursesManager::addCourse(int course_id,int num_of_classes)
{
    
    Array<int>* class_array=new Array<int> (course_id);
    courses_array->insertItem(course_id,class_array);
    num_of_courses++;
    total_num_of_classes+=num_of_classes;
    
}

int CoursesManager::numOfClasses(int course_id)
{
    Array<int>* class_array=courses_array.get(course_id);
    int num_of_classes=class_array->getNumOfClasses();
    return num_of_classes;
}

/*remove the course from the data struct
make sure it exists*/
void CoursesManager::removeCourse(int course_id)
{
    Array<int>* need_to_remove_course=courses_array.get(course_id);//o(1)
    int num_of_classes=need_to_remove_course->getNumOfClasses();//o(1)
    int num_of_watched_classes=need_to_remove_course->getNumOfUndifined();//o(1)
    for(int i=0;i<num_of_classes;i++)//o(num of classes in removed course)
    {
        if(need_to_remove_course->at(i)!=0)//this class was watched
        {
            viewed_classes_tree->Delete(ClassTuple(course_id,i,need_to_remove_course->at(i)));//o(log(total classes in struct))
        }
        
    }
    num_watched_classes-=num_of_watched_classes;
    courses_array->deleteItem(course_id);//o(1)
    total_num_of_classes-=num_of_classes;
    num_of_courses--;
}
/*this will add the watch time to the class of the course you ask for
give it course that exists and classs that exists*/
void CoursesManager::addWatch(int course_id, int class_id, int time_to_add)
{
    Array<int>* course=courses_array.get(course_id);//o(1)
    int class_watched_time=course->at(class_id);//O(1)
    if(class_watched_time!=0)//this classs was watched before
    {
        viewed_classes_tree->Delete(ClassTuple(course_id,class_id,class_watched_time));//o(log(total classes in struct))
    }
    
    (*course)[class_id]+=time_to_add;
    ClassTuple* new_class_data=new ClassTuple(course_id,class_id,course->at(class_id));
    viewed_classes_tree->insert(*new_class_data,new_class_data);
}

/*make sure to give this function a valid course id and class id*/   
int CoursesManager::getTimeViewed(int course_id,int class_id)
{
    return (courses_array->get(course_id)->at(course_id));
}


/*r
returuns if a courst is in the strcut alraedy
time complax o(N) 
*/
 bool CoursesManager::courseExsit(int course_id)
 {
     return courses_array->exist(course_id);
 }
 /*returns if a class of the course is in the struct alraedy
 time complax O(N)*/
 bool CoursesManager::classExisitInCourse(int course_id,int class_id)
 {
     if(this->courseExsit(course_id))
     {
         if(courses_array->get(course_id)->getNumOfClasses()>class_id)
         {
             return true;
         }
     }
     return false;
 }
 int CoursesManager::getTotalClasses()
 {
     return total_num_of_classes;
 }

 void CoursesManager::getMostWatched(int wanted, int* course,int* classes)
 {
     ClassTuple* t= viewed_classes_tree->getiVertex(wanted);
     *course=t->getCourseID();
     *classes=t->getClassID();
     
 }

#endif
