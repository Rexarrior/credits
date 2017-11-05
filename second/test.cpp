
#include "stdafx.h"
#include <string>
#include <vector>
#include "dictionary.h"



int main(int count, char* args[])
{
	setlocale(LC_ALL, "ru");
	
	const int testCollectionsSize = 10;


	dictionary<int, string> dict(testCollectionsSize);
	dict.printlnInConsole();
	cout << "Enter  strs: " << endl;
	vector<string> strs(0);
	for (int i = 0; i< testCollectionsSize ; ++i)
	{
		
		cout << "Enter str №" << i;
		string s; 
		getline(cin, s);
		strs.push_back(s);



		dict.add(i, s);

	}
	dict.printlnInConsole();



	bool isSizeWork = dict.size() == testCollectionsSize;

	bool isFindWork = true;
	for (int i = 0; i < testCollectionsSize; i++)
	{
		pair<int, string> elem = *(dict.find(i));
		isFindWork = isFindWork && (elem.second == strs[i]);
	}


	dict.remove(5);
	bool isFindLessdWork = dict.find(5) == dict.end();

	cout << "Size check is " <<( isSizeWork ? "" : "not ") << "work. " << endl; 
	cout << "Find existing is   " << (isFindWork ? "" : "not ") << "work. " << endl;
	cout << "Find not existing is   " << (isFindWork ? "" : "not ") << "work. " << endl;

	for (auto i = dict.begin(); i != dict.end(); ++i)
		cout << (*i).first << ':' << (*i).second << ' ';

	system("pause");
	return 0;
}
