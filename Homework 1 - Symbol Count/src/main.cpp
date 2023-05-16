// main()

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void do_job(const std::vector<char>& vect);

int main(int argc, char** argv)
{
	// VARIABLES

	std::vector<char> wordLine{ 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '!'};

	// BODY

	std::cout << "[IN]: ";

	for (const auto& i : wordLine)
	{
		std::cout << i;
	}

	std::cout << '\n';

	do_job(wordLine);

	// EXIT

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;

} // END OF main()

void do_job(const std::vector<char>& vect)
{
	if (!vect.empty())
	{
		// VARIABLES

		std::vector<std::pair<int, char>> localVect;
		std::list<char> lis;
		char prev = '\0';
		char curr = '\0';
		unsigned int counter = 0;

		// BODY

		for (const auto& i : vect)
		{
			lis.push_back(i);
		}

		lis.sort();

		std::cout << '\n';

		while (!lis.empty())
		{
			curr = lis.front();
			lis.pop_front();

			if (prev == '\0')
			{				
				prev = curr;				

			}
			else
			{
				if (curr == prev)
				{
					++counter;					
					prev = curr;
				}
				else
				{
					std::pair<int, char> tmp;
					tmp.first = ++counter;
					tmp.second = prev;

					localVect.push_back(tmp);
					prev = curr;
					counter = 0;
				}
			}

			if (lis.empty())
			{
				std::pair<int, char> tmp;
				tmp.first = ++counter;
				tmp.second = prev;

				localVect.push_back(tmp);
				prev = curr;
				counter = 0;
			}

		} // END OF while (!lis.empty())

		lis.clear();
		std::sort(localVect.begin(), localVect.end());

		// print

		std::cout << "\n[OUT]:\n";

		for (int i = localVect.size(); i > 0; --i)
		{
			std::cout << localVect.at(i - 1).second << ": " << localVect.at(i - 1).first << std::endl;
		}

	}

} // do_job