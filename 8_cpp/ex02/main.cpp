#include "MutantStack.hpp"
#include <iostream>
#include <list>
int main()
{

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Number at the top of the stack : " << mstack.top() << std::endl;
	mstack.pop(); // remove the element from the top of the stack
	std::cout << "Stack size now: " << mstack.size() << std::endl;
	std::cout << "Number at the top of the stack now: " << mstack.top() << std::endl;

	mstack.push(3); 
	mstack.push(23); 
	mstack.push(737); // add numbers to the top of the stack

	std::cout << "The numbers have been added " << std::endl;

	std::cout << "Number at the top of the stack now: " << mstack.top() << std::endl;


	MutantStack<int>::iterator it = mstack.begin(); // Create an iterator pointing to the beginning of the stack
	MutantStack<int>::iterator ite = mstack.end(); // Create an iterator pointing to the end of the stack
	++it;
	--it;
	std::cout << "List of numbers in the stack :" << std::endl;

	while (it != ite) 
	{

		std::cout << *it << std::endl;
		++it;

	 }

	// std::stack<int> s(mstack); // Creates a new stack s by copying the mstack
	
	std::cout << "Now zith an std::list: same result" << std::endl;


	std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Number at the top of the list : " << mlist.back() << std::endl;
    mlist.pop_back(); // remove the element from the back of the list
    std::cout << "List size now: " << mlist.size() << std::endl;
    std::cout << "Number at the top of the list now: " << mlist.back() << std::endl;

    mlist.push_back(3);
    mlist.push_back(23);
    mlist.push_back(737); // add numbers to the back of the list

    std::cout << "The numbers have been added " << std::endl;

    std::cout << "Number at the top of the list now: " << mlist.back() << std::endl;

    std::list<int>::iterator it2 = mlist.begin(); // Create an iterator pointing to the beginning of the list
    std::list<int>::iterator ite2 = mlist.end(); // Create an iterator pointing to the end of the list
    
    std::cout << "List of numbers in the list :" << std::endl;
    
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }


    return 0;
}