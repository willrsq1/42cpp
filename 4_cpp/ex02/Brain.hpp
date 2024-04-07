#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# define SIZE_TAB 100
class Brain
{
	private:
		void		fill_ideas();
		std::string	ideas[SIZE_TAB];
	public:
		Brain();
		~Brain();
		Brain(const Brain&);
		Brain& operator= (const Brain&);
		void	showIdea(int n);
};

#endif