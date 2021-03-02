#include "list.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	List list1;
	int listSize = 0, number = 0, deleteSize = 0, deleteNumber = 0;

	string fileName = argv[1];

	ifstream file;
	file.open(fileName.c_str());

	if (file)
	{
		file >> listSize;
		for (int i = 0; i < listSize; i++)
		{
			file >> number;
			list1.add(number);
		}

		list1.print();

		file >> deleteSize;
		for (int i = 0; i < listSize; i++)
		{
			file >> deleteNumber;
			list1.remove(deleteNumber);
		}

		list1.print();
	}

	return 0;
}
