#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		std::cout << "Unexpected Random" << std::endl;
	return (NULL);
	}
}

static void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(Test))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(Test))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &Test)
{
	while (i < 3)
	{

		try
		{
			if (i == 0)
			{
				Base &ref = dynamic_cast<A &>(Test);
				(void)ref;
			}
			else if (i == 1)
			{
				Base &ref = dynamic_cast<B &>(Test);
				(void)ref;
			}
			else if (i == 2)
			{
				Base &ref = dynamic_cast<C &>(Test);
				(void)ref;
			}
			else
				std::cout << "unknow type" << std::endl;
		}
		catch (std::exception &e)
		{
			i++;
			identify(Test);
			return;
		}
		std::cout << classes[i] << " is the identified type" << std::endl;
		i = 0;
		break;
	}
}

int main()
{
	srand(time(NULL));
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}