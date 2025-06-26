#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor is called.\n";
	for (int i=0; i < 100; i++) {
		std::stringstream ss;
		ss << "Genereal Idea " << i;	
		_ideas[i] = ss.str();
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor is called.\n";
}

/*  
	Here's a new object - set up its memory and copy everything into it
	_ideas is being initialized for the first time 
	Array initialization from another array is allowed at this stage
*/
Brain::Brain(const Brain& other) : _ideas(other._ideas) {
	std::cout << "Copy constructor is called.\n";
}

/*  
	Happens after the object already exists 
	now replace its content with those of another
*/
Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}

	std::cout << "Copy assignment operator is called.\n";
	return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index > 100)
		std::cout << "Error: Index must be 0 - 99\n";
	_ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) {
	if (index < 0 || index > 100) {
		std::cout << "Error: Index must be 0 - 99\n";
		return NULL;
	}
	return _ideas[index];
}