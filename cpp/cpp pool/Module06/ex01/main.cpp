#include "Serializer.hpp"

int main()
{
	Data ptr2;
	ptr2.name = "Houssam";
	ptr2.n = 2;
	ptr2.next = NULL;

	Data ptr;
	ptr.name = "Lhaj";
	ptr.n = 1;
	ptr.next = &ptr2;


	std::cout << "Lhaj :" <<
				"\n\taddress: " << &ptr <<
				"\n\tname: " << ptr.name <<
				"\n\trank: " << ptr.n <<
				"\n\taddress next: " << ptr.next <<
	std::endl;
	std::cout << "Houssam :\n\taddress ptr2: " << &ptr2 <<
				"\n\tname: " << ptr2.name <<
				"\n\trank: " << ptr2.n <<
				"\n\taddress next: " << ptr2.next <<
	std::endl << std::endl;

	Serializer a;

	Data *reserial = a.deserialize(a.serialize(&ptr));

	std::cout << "After reserialize:" <<
				"\n\taddress: " << reserial <<
				"\n\tname: " << reserial->name <<
				"\n\trank: " << reserial->n <<
				"\n\taddress next: " << reserial->next <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tname: " << ptr2.name <<
				"\n\trank: " << ptr2.n <<
				"\n\taddress next: " << ptr2.next <<
	std::endl << std::endl;

	return (0);
}