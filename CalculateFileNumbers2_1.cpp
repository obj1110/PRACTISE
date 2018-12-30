#include <vector>
#include <string>
#include <iostream> //for cout
#include <io.h>     //for _finddata_t、 _findnext
using namespace std;
 
vector<string>  getFilesList(string dir);
int main()
{
 
	char dir[200];
	cout << "Enter a directory: ";
	cin.getline(dir, 200);
	vector<string>allPath = getFilesList(dir);
 	
 	long cts=0;
 	
	cout << "输出所有文件的路径：" << endl;
	for (size_t i = 0; i < allPath.size(); i++)
	{
		string  perPath = allPath.at(i);
		cout << perPath << endl;
		cts++;
	}
 	printf("文件总数为:%d",cts/5);
	return 0;
}
 
vector<string> getFilesList(string dir)
{
	vector<string> allPath;
	// 在目录后面加上"\\*.*"进行第一次搜索
	string dir2= dir + "\\*.*";
 
	intptr_t handle;
	_finddata_t findData;
 
	handle = _findfirst(dir2.c_str(), &findData);
	if (handle == -1) {// 检查是否成功
		cout << "can not found the file ... " << endl;
		return allPath;
	}
	do
	{
		if (findData.attrib & _A_SUBDIR)//// 是否含有子目录
		{
			//若该子目录为"."或".."，则进行下一次循环，否则输出子目录名，并进入下一次搜索
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;
 
			// 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
			string dirNew = dir + "\\" + findData.name;
			vector<string> tempPath = getFilesList(dirNew);
			allPath.insert(allPath.end(), tempPath.begin(), tempPath.end());
		}
		else //不是子目录，即是文件，则输出文件名和文件的大小
		{
			string filePath = dir + "\\" + findData.name;
			allPath.push_back(filePath);
			//cout << filePath << "\t" << findData.size << " bytes.\n";
		}
	} while (_findnext(handle, &findData) == 0);
	_findclose(handle);    // 关闭搜索句柄
	return allPath;
}

