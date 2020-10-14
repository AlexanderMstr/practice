#include<iostream>
#include<String>
#include<bitset>
#include<fstream>
using namespace std;
ifstream& openFile()
{
	ifstream* pFileStream = 0;
	for (;;)
	{
		string sFileName;
		cout << "введите имя файла с целыми числами: ";
		cin >> sFileName;
		pFileStream = new ifstream(sFileName.c_str());
		if (pFileStream->good())
		{
			pFileStream->seekg(0);
			cerr << "Успешно открыт файл" << sFileName << endl;
			break;
		}
		cerr << "не открывается файл" << sFileName << endl;
		delete pFileStream;
	}
	return *pFileStream;
}

int main()
{
	setlocale(LC_ALL, "RU");
	ifstream& fileStream = openFile();
	while (!fileStream.eof())
	{
		int nValue = 0;
		fileStream >> nValue;
		if (fileStream.fail())
		{
			break;
		}
		cout << nValue << endl;
	}




	system("pause");
	return 0;
}