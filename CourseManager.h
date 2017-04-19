#ifndef CMSYS_COURSEMANGER_H
#define CMSYS_COURSEMANGER_H

#include <vector>
#include "Course.h"

using namespace std;

// �γ̹����ࣺ����ά���γ��б�ִ�пγ̴�������
class CourseManager {
    
public:
    // Ĭ�Ϲ��캯��
    CourseManager() = default;

    // ���캯�������ݿγ�vector����CourseManager
    CourseManager(const vector<Course>& courseVect); 

    // ��ȡ�γ��б���
    inline int GetCourseNum() { return courseList.size(); }
    
    // ����µĿγ�
    void AddCourse(const Course &course); 
    void AddCourse(const string& courseName); 
    
    // ɾ���γ̣�ɾ�����һ���γ�
    void RemoveLast();
    
    // ɾ���γ̣�ɾ��ָ�����ƵĿγ�
    void RemoveByName(const string &name); 
    
    // ɾ���γ̣�ɾ��ָ��ID�Ŀγ�
    void RemoveById(int id);
    
    // ��ӡ�γ��б���Ϣ
    void PrintAllCourse(); 

    // ���ݿγ����ƴ�ӡָ���γ���Ϣ
    void PrintCourse(const string &name); 

    // ���ݿγ�ID��ӡָ���γ���Ϣ
    void PrintCourse(int id); 

    // ��ӡ������Ŀγ�
    void PrintLongNameCourse();

private:

    // �洢�γ��б�
    vector<Course> courseList;
    
    // ���ݿγ����Ʋ��ҿγ̣����ؿγ��б��е�����ֵ���޷��ҵ�����-1
    int FindCourse(const string& name); 
    
    // ���ݿγ�ID���ҿγ̣����ؿγ��б��е�����ֵ���޷��ҵ�����-1
    int FindCourse(int id); 

};


#endif //CMSYS_COURSEMANGER_H