#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iostream>
# include <vector>
# include <ctime>
# include <deque>
# include <algorithm>
# include <exception>
# include <sstream>
# include <limits.h>

# ifndef CLASS
#  define CLASS(x, y) std::cout << ""
// #  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# ifndef TEMPLATE
# 	define TEMPLATE 0
# endif

# ifdef TEMPLATE
#  if TEMPLATE > 1 || TEMPLATE < 1
#   undef TEMPLATE
#   define TEMPLATE 1
#  endif
# endif
// DEFINES IF WE WILL USE YHE TEMPLATE CLASS OR THE CLASS WITH TWO DIFFERENT CONTAINERS IMPLEMANTED MANUALLY. EITHER 0 OR 1.

int	my_atoi(char *s);

# if TEMPLATE == 0

class PmergeMe
{
	private:
		std::vector<int>								Vnumbers;

		std::vector<int>::iterator	 					Vmain_it;
		std::vector<int>::iterator 						Vmain_ite;
		std::vector<int>::iterator 						Vmain_ite_plus_one;
		std::vector<int>::iterator 						Vmain_ite_minus_one;

		std::vector<std::pair<int, int> >				V;
		std::vector<std::pair<int, int> >::iterator		Vit;
		std::vector<std::pair<int, int> >::iterator		Vite;

		std::vector<std::pair<int, int> > 				Vmap;	
		std::vector<std::pair<int, int> >::iterator 	Vmap_it;
		std::vector<std::pair<int, int> >::iterator 	Vmap_ite;

		int												Vimpair;

		void											Vmain();
		void											VcreatePairs();
		void											VsortPairs();
		void											VinsertByFirst();
		void											VinsertmergeSeconds();
		
		std::deque<int>									Lnumbers;

		std::deque<int>::iterator	 					Lmain_it;
		std::deque<int>::iterator 						Lmain_ite;
		std::deque<int>::iterator 						Lmain_ite_plus_one;
		std::deque<int>::iterator 						Lmain_ite_minus_one;

		std::deque<std::pair<int, int> >					L;
		std::deque<std::pair<int, int> >::iterator		Lit;
		std::deque<std::pair<int, int> >::iterator		Lite;

		std::deque<std::pair<int, int> > 				Lmap;	
		std::deque<std::pair<int, int> >::iterator 		Lmap_it;
		std::deque<std::pair<int, int> >::iterator 		Lmap_ite;

		int												Limpair;

		void											Lmain();
		void											LcreatePairs();
		void											LsortPairs();
		void											LinsertByFirst();
		void											LinsertmergeSeconds();
	protected:

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator= (const PmergeMe&);
		void	VSortMergeAlgo(char **, int);


		void	LSortMergeAlgo(char **, int);


		class Doubles: public std::exception
		{
			const char* what() const throw();
		};
};

void	Vprint_main(std::vector<int> v);
void	Lprint_main(std::deque<int> v);
void	Vprint(std::vector<std::pair<int, int> > v);

 //END OF FIXED CLASS
# elif TEMPLATE == 1

// WITH TEMPLATE

template <typename Container, typename Pairs>
class PmergeMe
{
	private:

		Container											_numbers;
		typename Container::iterator	 					_numbers_it;
		typename Container::iterator 						_numbers_ite;

		Pairs												_pairs;
		typename Pairs::iterator							_pairs_it;
		typename Pairs::iterator							_pairs_ite;

		int													_impair;

		void												_CreateStack(char**, int);
		void												_createPairs();
		void												_sortPairs();
		void												_MergeInsertSort();
		void												_print_Sort(Container v);

		std::stringstream									out;

	protected:

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator= (const PmergeMe&);
		std::string	            _SortStack(char **, int);
        size_t                  _ShowSize();

};

class Doubles: public std::exception
{
	const char* what() const throw();
};
class Empty: public std::exception
{
	const char* what() const throw();
};
class BadArg: public std::exception
{
	const char* what() const throw();
};

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe()
{
    CLASS("Constructor", "PmergeMe");
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::~PmergeMe()
{
    CLASS("Destructor", "PmergeMe");
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe(const PmergeMe& other)
{
    CLASS("Constructor by copy", "PmergeMe");
	if (this == &other)
		return ;
	this->_numbers = other._numbers;
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>& PmergeMe<Container, Pairs>::operator= (const PmergeMe& other)
{
    CLASS("Operand = Constructor", "PmergeMe");
	if (this == &other)
		return (*this);
	this->_numbers = other._numbers;
    return (*this);
}
template <typename Container, typename Pairs>
size_t  PmergeMe<Container, Pairs>::_ShowSize()
{
    return (_numbers.size());
}


template <typename Container, typename Pairs>
std::string PmergeMe<Container, Pairs>::_SortStack(char **tab, int size)
{
	this->_CreateStack(tab, size);
    this->out << "Before:   ";
    this->_print_Sort(_numbers);
    this->_createPairs();
    this->_sortPairs();
	std::sort(_pairs.begin(), _pairs.end());
    this->_MergeInsertSort();
    this->out << "After:    ";
    this->_print_Sort(_numbers);
	return (this->out.str());
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_CreateStack(char **tab, int size)
{
    for (int i = 0; i < size; i++) {
            int num = my_atoi(tab[i]);
            this->_numbers.push_back(num);
    }
    Container double_check;
    _numbers_it = _numbers.begin();
    _numbers_ite = _numbers.end();
    while (_numbers_it != _numbers_ite)
    {
        if (std::find(double_check.begin(), double_check.end(), *_numbers_it) != double_check.end())
        {
            std::cout << *_numbers_it;
            throw Doubles();
        }
        double_check.push_back(*_numbers_it);
        _numbers_it++;
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_createPairs()
{
    int     a;
	typename Container::iterator 						_numbers_ite_minus_one;

    _numbers_it = _numbers.begin();
    _numbers_ite = _numbers.end();
    _numbers_ite_minus_one = --_numbers.end();
    while (_numbers_it != _numbers_ite && _numbers_it != _numbers_ite_minus_one)
    {
        a = *_numbers_it;
        ++_numbers_it;
        _pairs.push_back(std::pair<int, int>(a, *_numbers_it));
        ++_numbers_it;
    }
    this->_impair = 0;
    if (_numbers_it == _numbers_ite_minus_one)
        this->_impair = *(_numbers_ite_minus_one);
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_sortPairs()
{
    _pairs_it = _pairs.begin();
    _pairs_ite = _pairs.end();
    while (_pairs_it != _pairs_ite)
    {
        if ((*_pairs_it).first > (*_pairs_it).second)
            std::swap((*_pairs_it).first, (*_pairs_it).second);
        _pairs_it++;
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_MergeInsertSort()
{
    _numbers.clear();
    _pairs_it = _pairs.begin();
    _pairs_ite = _pairs.end();
    while (_pairs_it != _pairs_ite)
    {
        _numbers.push_back((*_pairs_it).first);
        _pairs_it++;
    }
    if (this->_impair)
    {
            _numbers_it = _numbers.begin();
            _numbers_ite = --_numbers.end();
            while (_numbers_ite >= _numbers_it && this->_impair < *(_numbers_ite))
                _numbers_ite--;
            _numbers.insert(++_numbers_ite, this->_impair);
    }
    _pairs_it = _pairs.begin();
    _pairs_ite = _pairs.end();
    while (_pairs_it != _pairs_ite)
    {
            _numbers_it = _numbers.begin();
            _numbers_ite = --_numbers.end();
            while (_numbers_ite >= _numbers_it && (*_pairs_it).second < *(_numbers_ite))
                _numbers_ite--;
            _numbers.insert(++_numbers_ite, (*_pairs_it).second);
        _pairs_it++;
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_print_Sort(Container v)
{
    typename Container::iterator it;
    typename Container::iterator ite;
    it = v.begin();
    ite = v.end();
    while (it != ite)
    {
        this->out << (*it) << ' ';
        it++;
    }
    this->out << '\n';
}
 //END OF TEMPLATE
# endif
#endif
