#ifndef  CMSYS_CMD_H
#define CMSYS_CMD_H

// ֧�ֵ�����
enum CourseCmd
{
    // ��ӡ���������Ϣ
	Cmd_PrintHelp = 0,
    // ��ӡ�γ���Ϣ
	Cmd_PrintCourse = 1,
    // ��ӡ�γ�����
	Cmd_PrintCourseNum = 2,
    // ��ӡ��Ŀγ�����
	Cmd_PrintLongName = 3,
    // ɾ�����һ���γ�
	Cmd_RemoveLastCourse = 4,
    // �˳�����
	Cmd_Exit = 5,
};

#endif // CMSYS_CMD_H