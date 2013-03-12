#include <iostream>
#include "ObjectCategory.h"
using namespace std;

int main(int argc, char *argv[])
{
	ObjCat objCat;

	cout<<"start training"<<endl;
	objCat.train();

	cout<<"training finished."<<endl;
	cout<<"input the test file name[default folder: ../resource/test/]"
		<<endl<<"(type 'exit' to exit)"<<endl;
	string testFilePath;
	cin>>testFilePath;
	while (testFilePath != "exit")
	{

		string defaultPath = "../resource/test/"+testFilePath;
		cout<<"using file: "<<defaultPath<<endl;
		FILE *pFile = fopen(defaultPath.c_str(), "r");
		if (pFile == NULL)
		{
			cout<<defaultPath<<" not found, using: "<<testFilePath<<endl;
			pFile = fopen(testFilePath.c_str(), "r");
			if (pFile == NULL)
			{
				cout<<testFilePath<<" not found, failed to test this image."
					<<endl;
			} else {
				fclose(pFile);
				objCat.test(testFilePath);
			}
		} else {
			fclose(pFile);
			objCat.test(defaultPath);
		}
		
		cin>>testFilePath;
	}
	return 0;
}
