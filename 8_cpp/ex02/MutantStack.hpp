#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# include <stack>

	template<typename T>
class MutantStack: public std::stack<T>
{
	private:
	protected:

	public:
		typedef typename std::stack<T>::container_type::iterator 	iterator;
		MutantStack() {};
		~MutantStack() {}
		MutantStack<T>(const MutantStack<T>& other): std::stack<T>(other) {}
		MutantStack<T>& operator= (const MutantStack<T>&){
			return (*this);
		}
		iterator begin(){
			return (this->c.begin());
		}
		iterator end(){
			return (this->c.end());
		}
};

#endif
