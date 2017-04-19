#ifndef CMSYS_COURSE_H
#define CMSYS_COURSE_H

#include <string>

using namespace std;

// �γ��ࣺ�洢�ʹ���γ���Ϣ
class Course {
    
    // ��Ԫ��������ȡ���봴���µĿγ�
    friend void read(istream &inputStream, Course &course);

public:
    // �޲������캯��
    Course();

    // �γ��๹�캯�������ݿγ����ƴ����γ̶���
    Course(const string& cName): Course() { name = cName; };
    
    // �γ��࿽�����캯��
    Course(const Course& course);
    
    // ��ӡ�γ���Ϣ
    virtual void PrintInfo() const;
    
    // ���ؿγ�����
    inline string GetName() const { return name; };
    
    // ���ÿγ�����
    inline void SetName(const string& newName) { name = newName; };

    // ���ؿγ�ID
    inline const int GetId() const { return id; };

    // ������<<���غ�������cout<<����γ���Ϣʱʹ��
    friend ostream& operator <<(ostream& out, const Course& course);

    
protected:

    // �γ�ID
    int id;
    
    // �γ�����
    string name;
    
    // ���þ�̬����������Ψһ��IDֵ
    static int currentId;
};


// �γ̷�Ϊ�����Σ���Ŀ�Σ����������ֲ�ͬ������
// ������Ϊ����Course�࣬����Ŀ�κ������ζ��̳л�����
// ��Ŀ�Σ��Ȼ����������˱�ǩ
class ProjectCourse: public Course {
public:
    // ���ñ�ǩ
    inline void SetTag(const string& newTag) { tag = newTag; };

    // ���ر�ǩ
    inline string GetTag() const { return tag; };

    // ��ӡ�γ���Ϣ
    virtual void PrintInfo() const override;
private:
    string tag;
};

// �����Σ��Ȼ�����������ʱ������
class JudgeCourse: public Course {
public:
    // ������ʱ
    inline void SetTime(int newTime) { time = newTime; };

    // ������ʱ
    inline int GetTime() { return time; };
    
    // ��ӡ�γ���Ϣ
    virtual void PrintInfo() const override;
private:
    int time;
};

#endif //CMSYS_COURSE_H