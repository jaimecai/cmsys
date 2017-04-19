#include <iostream>
#include "Course.h"

using namespace std;

// Course ���Ա����

// ��ʼ����̬��Ա��Ĭ�ϵ�һ���γ�IDΪ1
int Course::currentId = 1;

// �γ��๹�캯��
Course::Course(){
    // ��currentId��ǰֵ��ֵ��id���ٽ�currentID����
    id = currentId++;
    
    // Ĭ�Ͽγ�����Ϊ���ַ���
    name = "";
}

// �γ��࿽�����캯��
Course::Course(const Course& course){
    id = course.GetId();
    name = course.GetName();
}

// ��ӡ�γ���Ϣ
void Course::PrintInfo() const {
    cout << "Course: " << id << " : " << name << endl;
}

// ��Ԫ��������ȡ���봴���µĿγ�
void read(istream &is, Course &item){
    is >> item.name;
}

// ��Ԫ������������<<���غ�������cout<<����γ���Ϣʱʹ��
ostream &operator<<(ostream &os, const Course& course)
{
    os << "Course: " << course.id << " : " << course.name;
    return os;
}

// ProjectCourse ���Ա����
// ��ӡ�γ���Ϣ
void ProjectCourse::PrintInfo() const {
    cout << "ProjectCourse: " << id << " : " << name << " : " << tag << endl;
}


// JudgeCourse ���Ա����
// ��ӡ�γ���Ϣ
void JudgeCourse::PrintInfo() const {
    cout << "JudgeCourse: " << id << " : " << name << " : " << time << endl;
}











