// main()

#include <iostream>
#include <set>
#include <Windows.h>
#include <list>

int main(int argc, char** argv)
{

	// CMD SET

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// VARIABLES

	unsigned int repeatNum = 0;
	int inputNum = 0;
	std::set<int> itemSet;
	std::list<int> outSet;

	// BODY

	std::cout << "[INPUT]\n";
	std::cout << "Количество вводов: "; 
	std::cin >> repeatNum;
	std::cout << "Ввод данных:\n";

	for (int i = 0; i < repeatNum; ++i)
	{
		std::cin >> inputNum;
		itemSet.insert(inputNum);
	}

	// PRINT

	std::cout << "\n[OUTPUT]\n";

	for (const auto& elem : itemSet)
	{
		std::cout << elem << '\n';
	}

	std::cout << "\nПо убыванию:\n";

	for (const auto& elem : itemSet)
	{
		outSet.push_back(elem);
	}

	outSet.sort();

	while (!outSet.empty())
	{
		std::cout << outSet.back() << '\n';
		outSet.pop_back();
	}

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // END OF main()