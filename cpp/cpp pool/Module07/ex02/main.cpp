#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
#define MIN_VAL 30
int main(int, char**)
{
	/*
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//


	Array<int> numberstest(MIN_VAL);
	for (size_t i = 0; i <= MIN_VAL; i++)
	{
		try
		{
			numberstest[i] = MIN_VAL- i;
		}
		catch(const std::exception& e)
		{
			std::cerr << "This error is caused because we are trying to set index 30! " << e.what() << '\n';
		}
	}

	for (size_t i = 0; i < MIN_VAL; i++)
	{
		std::cout << "Value of numberstest[" << i << "] is: " << numberstest[i] << std::endl;
	}

	Array<std::string>strs(2);
	strs[0] = "Hello";
	strs[1] = "World";
	try
	{
		strs[2] = "Srsly !";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << strs[0] << std::endl;
	std::cout << strs[1] << std::endl;
	*/

	Array<int> a(6);
	Array<int> b(5);

	a = b;
	return (0);
}