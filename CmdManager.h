#ifndef CMSYS_CMDMANAGER_H
#define CMSYS_CMDMANAGER_H

#include "CourseManager.h"
#include "Cmd.h"

#include <map>
#include <istream>

using namespace std;

// ���������
class CmdManager {

public:
    // ���캯��
    CmdManager() = default;
    
    // ��ʼ����������ʼ��֧�ֵ�����γ���Ϣ
    void Init();

    // ��ӡ������Ϣ
    void PrintAllHelp() const;

    // ���������ѯ������Ϣ
    void PrintCmdHelp(const CourseCmd cmd) const;
    
    // �����������
    bool HandleCmd(const CourseCmd cmd);

    // ���ؿγ̹������
    CourseManager& GetCourseManager() { return manager; }; 

private:

    // �γ̹������
    CourseManager manager;
    
    // ʹ��map�洢���������Ϣ
    map<CourseCmd, string> cmdMap;
};


#endif //CMSYS_CMDMANAGER_H