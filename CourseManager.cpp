#include <stdexcept>
#include <iostream>

#include "CourseManager.h"

using namespace std;

//���캯��������Ϊ�γ�vector
CourseManager::CourseManager(const vector<Course> &course){
    for(auto curs = course.begin(); curs != course.end(); ++curs){
        courseList.push_back(*curs);
    }
}

//��ӿγ̺���������Ϊ�γ����ƣ�
void CourseManager::AddCourse(const string& courseName){
    Course course(courseName);
    courseList.push_back(course);
}

//��ӿγ̺���������Ϊ�γ̶���
void CourseManager::AddCourse(const Course &course){
    courseList.push_back(course);
}

//ɾ�����һ���γ�
void CourseManager::RemoveLast(){
    try
    {
        //����γ̷ǿգ���ɾ�����һ�ſγ�
        if (!courseList.empty())
        {
            courseList.pop_back();

            cout << "Deleted successfully!" << endl;
        }
        else
        {
            // �γ�Ϊ�գ������쳣�����쳣����catch����
            throw runtime_error("Deleted error, there is no course!");
        }
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }
}

//ɾ���γ̣�ɾ��ָ��ID�Ŀγ�
void CourseManager::RemoveById(int id){
    int index = FindCourse(id);
    
    if (index > 0)
        courseList.erase(courseList.begin()+index);
    else
        cout << "NOT FOUND" << endl;
}

//ɾ���γ̣�ɾ��ָ�����ƵĿγ�
void CourseManager::RemoveByName(const string &name){
    int index = FindCourse(name);
    
    if (index > 0)
        courseList.erase(courseList.begin()+index);
    else
        cout << "NOT FOUND" << endl;
}

//��ӡ�γ��б�
void CourseManager::PrintAllCourse(){
    cout << "CourseList:" << endl;

    //����courseList����ӡ������course��Ϣ
    for (auto curs = courseList.begin(); curs != courseList.end(); ++curs){
        cout << *curs << endl;
    }
}

//��ӡָ���γ�(ָ��ID)
void CourseManager::PrintCourse(int id){
    
    int index = FindCourse(id);
    
    if (index > 0)
        cout << courseList[index] << endl;
    else
        cout << "NOT FOUND" << endl;
}

//��ӡָ���γ�(ָ������)
void CourseManager::PrintCourse(const string &name){
    
    int index = FindCourse(name);
    
    if (index > 0)
        cout << courseList[index] << endl;
    else
        cout << "NOT FOUND" << endl;
}

// ��ӡ������Ŀγ�
void CourseManager::PrintLongNameCourse(){
    
    int maxLen = 0;
    
    //����courseList�����������
    for (auto curs = courseList.begin(); curs != courseList.end(); ++curs){
        int currentLen = curs->GetName().size();
        if (currentLen > maxLen)
            maxLen = currentLen;
    }
    
    //����courseList����ӡ����ƿγ�
    for (auto curs = courseList.begin(); curs != courseList.end(); ++curs){
        if (curs->GetName().size() == maxLen)
            cout << *curs << endl;
    }
}

//����ID���ҿγ̣����ؿγ���vector�е�����
int CourseManager::FindCourse(int id){
    
    int i = 0;
    
    for (; i<courseList.size(); i++){
        if(courseList[i].GetId() == id){
            return i;
        }
    }

    return -1;
}

//�������ֲ��ҿγ̣����ؿγ���vector�е�����
int CourseManager::FindCourse(const string& name){
    
    int i = 0;
    
    for (; i<courseList.size(); i++){
        if(courseList[i].GetName() == name){
            return i;
        }
    }

    return -1;
}
