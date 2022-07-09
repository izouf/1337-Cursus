#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout<< "---------------------------------" << std::endl;
    const Animal* meta2 = new Animal();
    const Dog* k = new Dog();
    const Cat* l = new Cat();
    std::cout<< "---------------------------------" << std::endl;
    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();
    std::cout<< "---------------------------------" << std::endl;
    const WrongAnimal* wrongmeta2 = new WrongAnimal();
    const WrongCat* wl = new WrongCat();
    std::cout<< "---------------------------------" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout<< "---------------------------------" << std::endl;
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    std::cout << meta2->getType() << " " << std::endl;
    std::cout<< "---------------------------------" << std::endl;
    std::cout << wrongmeta->getType() << " " << std::endl;
    std::cout << wi->getType() << " " << std::endl;
    std::cout<< "---------------------------------" << std::endl;
    std::cout << wrongmeta2->getType() << " " << std::endl;
    std::cout << wl->getType() << " " << std::endl;
    std::cout<< "---------------------------------" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout<< "---------------------------------" << std::endl;
    k->makeSound();
    l->makeSound();
    meta2->makeSound();
    std::cout<< "---------------------------------" << std::endl;
    wi->makeSound();
    wrongmeta->makeSound();
    std::cout<< "---------------------------------" << std::endl;
    wl->makeSound();
    wrongmeta2->makeSound();
    std::cout<< "---------------------------------" << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout<< "---------------------------------" << std::endl;
    delete meta2;
    delete k;
    delete l;
    std::cout<< "---------------------------------" << std::endl;
    delete wi;
    delete wrongmeta;
    std::cout<< "---------------------------------" << std::endl;
    delete wl;
    delete wrongmeta2;
    std::cout<< "---------------------------------" << std::endl;
    return (0);
}