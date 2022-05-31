#include "iter.hpp"

static	void	fn_string(std::string val)
{
	std::cout << val << std::endl;
}

static	void	fn_int(int val)
{
	std::cout << val << std::endl;
}

static	void	fn_float(float val)
{
	std::cout << val << std::endl;
}

static	void	fn_double(double val)
{
	std::cout << val << std::endl;
}

static	void	fn_char(char val)
{
	std::cout << val << std::endl;
}

int main(void)
{
	std::cout << "-------------------" << std::endl;
	std::string strArray[2] = {"Hello", "World"};
	iter(&strArray, sizeof(strArray) / sizeof(std::string), fn_string);

	std::cout << "-------------------" << std::endl;
	int intArray[2] = {42, 1337};
	iter(&intArray, sizeof(intArray) / sizeof(int), fn_int);

	std::cout << "-------------------" << std::endl;
	float floatArray[2] = { 4.2f, 13.37f };
	iter(&floatArray, sizeof(floatArray) / sizeof(float), fn_float);

	std::cout << "-------------------" << std::endl;
	double doubleArray[2] = {4.2,13.37};
	iter(&doubleArray, sizeof(doubleArray) / sizeof(double), fn_double);

	std::cout << "-------------------" << std::endl;
	char charArray[2] = {'a', 'b'};
	iter(&charArray, sizeof(charArray) / sizeof(char), fn_char);
	return (0);
}