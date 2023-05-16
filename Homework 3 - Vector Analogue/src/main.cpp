// main function

#include "..\headers\vect.hpp"
#include <iostream>
#include <Windows.h>

int main(int argc, char** argv)
{
	// CONSOLE SET

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	// VARIABLES

	jinx::vector<int> vect(3);			// ������ �� 3 �������� int
	jinx::vector<double> vect_d(3);		// ������ �� 3 �������� double

	// BODY

	// ------------------------------- INT

	std::cout << "-------------------------------- INT TYPE --------------------------------\n\n";

	std::cout << "����� jinx::vector<T>, ���� int:\n";

	std::cout << "\nsize = " << vect.size();
	std::cout << "\ncapacity = " << vect.capacity();

	std::cout << "\n\n��������� �������� ����� vect.push_back(T), 3 ��������";

	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect.size();
	std::cout << "\ncapacity = " << vect.capacity();

	std::cout << "\n\n��������� �������� ����� vect.push_back(T), ��� 3 ��������";

	vect.push_back(5);
	vect.push_back(6);
	vect.push_back(7);

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect.size();
	std::cout << "\ncapacity = " << vect.capacity();

	std::cout << "\n\n��������� �������� ����� vect.push_back(T), ��� 3 ��������";

	vect.push_back(8);
	vect.push_back(9);
	vect.push_back(10);

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect.size();
	std::cout << "\ncapacity = " << vect.capacity();

	std::cout << "\n\n�������� shrink_to_fit()";	

	vect.shrink_to_fit();

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect.size();
	std::cout << "\ncapacity = " << vect.capacity();

	std::cout << "\n\n�������� ������ ����� ������� ������� �������� � at(index):";

	std::cout << "\n\n����� ��������:\n";

	for (int i = 0; i < vect.size(); ++i)
	{
		std::cout << vect.at(i) << ' ';
	}

	std::cout << "\n\n�������� ������ ����� ������� ������� �������� � [index]:";

	std::cout << "\n\n����� ��������:\n";

	for (int i = 0; i < vect.size(); ++i)
	{
		std::cout << vect[i] << ' ';
	}

	// ----------------------------------- CLEAR

	std::cout << std::endl;
	system("pause");
	system("cls");

	// ----------------------------- DOUBLE

	std::cout << "-------------------------------- DOUBLE TYPE --------------------------------\n\n";

	std::cout << "����� jinx::vector<T>, ���� double:\n";

	std::cout << "\nsize = " << vect_d.size();
	std::cout << "\ncapacity = " << vect_d.capacity();

	std::cout << "\n\n��������� �������� ����� vect.push_back(T), 3 ��������";

	vect_d.push_back(1.5);
	vect_d.push_back(2.5);
	vect_d.push_back(3.5);

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect_d)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect_d.size();
	std::cout << "\ncapacity = " << vect_d.capacity();

	std::cout << "\n\n��������� �������� ����� vect.push_back(T), ��� 3 ��������";

	vect_d.push_back(5.5);
	vect_d.push_back(6.5);
	vect_d.push_back(7.5);

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect_d)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect_d.size();
	std::cout << "\ncapacity = " << vect_d.capacity();

	std::cout << "\n\n��������� �������� ����� vect.push_back(T), ��� 3 ��������";

	vect_d.push_back(8.5);
	vect_d.push_back(9.5);
	vect_d.push_back(10.5);

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect_d)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect_d.size();
	std::cout << "\ncapacity = " << vect_d.capacity();

	std::cout << "\n\n�������� shrink_to_fit()";

	vect_d.shrink_to_fit();

	std::cout << "\n\n����� ��������:\n";

	for (const auto& element : vect_d)
	{
		std::cout << element << ' ';
	}

	std::cout << "\nsize = " << vect_d.size();
	std::cout << "\ncapacity = " << vect_d.capacity();

	std::cout << "\n\n�������� ������ ����� ������� ������� �������� � at(index):";

	std::cout << "\n\n����� ��������:\n";

	for (int i = 0; i < vect_d.size(); ++i)
	{
		std::cout << vect_d.at(i) << ' ';
	}

	std::cout << "\n\n�������� ������ ����� ������� ������� �������� � [index]:";

	std::cout << "\n\n����� ��������:\n";

	for (int i = 0; i < vect_d.size(); ++i)
	{
		std::cout << vect_d[i] << ' ';
	}

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // END OF main()