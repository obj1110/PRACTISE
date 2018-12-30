#include <iostream>
#include <vector>
#include <cstring>        // for strcat()
#include <io.h>
using namespace std;
 
vector<char*>  getFilesList(const char * dir);
int main()
{
 
	char dir[200];
	cout << "Enter a directory: ";
	cin.getline(dir, 200);
	vector<char*>allPath= getFilesList(dir);
 
	cout << "��������ļ���·����" << endl;
	for (size_t i = 0; i < allPath.size(); i++)
	{
		char *perPath = allPath.at(i);
		cout << perPath <<endl;
	}
 
	return 0;
}
 
vector<char*> getFilesList(const char * dir)
{
	vector<char*> allPath;
	char dirNew[200];
	strcpy(dirNew, dir);
	strcat(dirNew, "\\*.*");    // ��Ŀ¼�������"\\*.*"���е�һ������
 
	intptr_t handle;
	_finddata_t findData;
 
	handle = _findfirst(dirNew, &findData);
	if (handle == -1) {// ����Ƿ�ɹ�
		cout << "can not found the file ... " << endl;
		return allPath;
	}      
 
	do
	{
		if (findData.attrib & _A_SUBDIR)//// �Ƿ�����Ŀ¼
		{
			//������Ŀ¼Ϊ"."��".."���������һ��ѭ�������������Ŀ¼������������һ������
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
 
 
			//cout << findData.name << "\t<dir>\n";
			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			strcpy(dirNew, dir);
			strcat(dirNew, "\\");
			strcat(dirNew, findData.name);
			vector<char*> tempPath=getFilesList(dirNew);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //������Ŀ¼�������ļ���������ļ������ļ��Ĵ�С
		{
			char *filePath=new char[200];
			strcpy(filePath, dir);
			strcat(filePath, "\\");
			strcat(filePath, findData.name);
			allPath.push_back(filePath);
			//cout << filePath << "\t" << findData.size << " bytes.\n";
 
		}
	} while (_findnext(handle, &findData) == 0);
	_findclose(handle);    // �ر��������
	return allPath;
}

