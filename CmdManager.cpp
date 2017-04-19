#include <stdexcept>
#include <iostream>

#include "CmdManager.h"

using namespace std;

// ��ʼ������
void CmdManager::Init(){

    // ��ʼ���γ��б�
    manager.AddCourse("Linux");
    manager.AddCourse("NodeJS");
    manager.AddCourse("C++");
    manager.AddCourse("Python");
    manager.AddCourse("Spark");
    manager.AddCourse("Hadoop");
    manager.AddCourse("Ruby");
    manager.AddCourse("Java");

    // ��ʼ�������б�
    cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintHelp, "Help Info"));
    cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintCourse, "Course List"));
    cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintCourseNum, "Course Number"));
    cmdMap.insert(pair<CourseCmd, string>(Cmd_PrintLongName, "Longest Course Name"));
    cmdMap.insert(pair<CourseCmd, string>(Cmd_RemoveLastCourse, "Remove Last Course"));
    cmdMap.insert(pair<CourseCmd, string>(Cmd_Exit, "Exit"));
}

// ��ӡ������Ϣ
void CmdManager::PrintAllHelp() const{
    
    cout << "Cmd List:" << endl;
    
    for (auto iter = cmdMap.begin(); iter != cmdMap.end(); iter++)
        cout << iter->first << ":" << iter->second << endl;
}

// �������ѯ������Ϣ
void CmdManager::PrintCmdHelp(const CourseCmd cmd) const{
    auto iter = cmdMap.find(cmd);
    
    if (iter != cmdMap.end())
        cout << iter->first << ":" << iter->second << endl;
    else
        cout << "NOT FOUND" << endl;
}

// ��������������������false���ʾ�˳����������������true
bool CmdManager::HandleCmd(const CourseCmd cmd){
    auto iter = cmdMap.find(cmd);
    
    if (iter == cmdMap.end()) {
        cout << "NOT FOUND" << endl;
        return true;
    }
    
    switch(cmd) {
        case Cmd_PrintHelp: PrintAllHelp(); break;
        case Cmd_PrintCourse: manager.PrintAllCourse(); break;
        case Cmd_PrintCourseNum: cout << manager.GetCourseNum() << endl; break;
        case Cmd_PrintLongName: manager.PrintLongNameCourse(); break;
        case Cmd_RemoveLastCourse: manager.RemoveLast(); break;
        case Cmd_Exit: return false;
        default: break;
    }
    
    return true;
}



























 