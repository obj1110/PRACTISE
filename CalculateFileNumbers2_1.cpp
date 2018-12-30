#include <vector>
#include <string>
#include <iostream> //for cout
#include <io.h>     //for _finddata_t�� _findnext
using namespace std;
 
vector<string>  getFilesList(string dir);
int main()
{
 
	char dir[200];
	cout << "Enter a directory: ";
	cin.getline(dir, 200);
	vector<string>allPath = getFilesList(dir);
 	
 	long cts=0;
 	
	cout << "��������ļ���·����" << endl;
	for (size_t i = 0; i < allPath.size(); i++)
	{
		string  perPath = allPath.at(i);
		cout << perPath << endl;
		cts++;
	}
 	printf("�ļ�����Ϊ:%d",cts/5);
	return 0;
}
 
vector<string> getFilesList(string dir)
{
	vector<string> allPath;
	// ��Ŀ¼�������"\\*.*"���е�һ������
	string dir2= dir + "\\*.*";
 
	intptr_t handle;
	_finddata_t findData;
 
	handle = _findfirst(dir2.c_str(), &findData);
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
 
			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			string dirNew = dir + "\\" + findData.name;
			vector<string> tempPath = getFilesList(dirNew);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //������Ŀ¼�������ļ���������ļ������ļ��Ĵ�С
		{
			string filePath = dir + "\\" + findData.name;
			allPath.push_back(filePath);
			//cout << filePath << "\t" << findData.size << " bytes.\n";
		}
	} while (_findnext(handle, &findData) == 0);
	_findclose(handle);    // �ر��������
	return allPath;
}

