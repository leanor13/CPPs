#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
	static const int MAX_IDEAS = 100; 
	std::string ideas[MAX_IDEAS];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif