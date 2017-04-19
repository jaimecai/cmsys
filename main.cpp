#include <iostream>

#include "CmdManager.h"

using namespace std;

// ������
int main() {

    // ���������
    int cmd;
    

    // ��������������
    CmdManager cmdManager;
    cmdManager.Init();

    // ��ӡ������Ϣ
    cmdManager.PrintAllHelp();

    cout << "New Command:";

    // ������ѭ��������������Ϣ
    while (cin >> cmd) {
        if (cin.good()) {
            bool exitCode = cmdManager.HandleCmd((CourseCmd)cmd);
            if (!exitCode)
                return 0;
        }

        cout << "-------------------------" << endl;
        cout << "New Command:";

        // ����������������ղ����е��ַ�Ӱ���������
        cin.clear();
        cin.ignore();
    }

    return 0;
}