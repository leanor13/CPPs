#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	if (N <= 0){
		std::cerr << "Invalid number of zombies." << std::endl;
		return nullptr;
	}

	// create zombie horde on heap
	// no need to protect from memory failure, is supposed to through exception
	// https://en.cppreference.com/w/cpp/memory/new/operator_new (Return value)
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return horde;
}