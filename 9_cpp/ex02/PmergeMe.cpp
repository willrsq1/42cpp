#include "PmergeMe.hpp"

#if TEMPLATE == 1

int	my_atoi(char *s)
{
	long	result;
	size_t	i;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw Empty();
	while (s[i] && s[i] <= '9' && s[i] >= '0' && i < 12)
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] || result > INT_MAX)
	{
		std::cout << s;
		throw BadArg();
	}
	return (result);
}

const char* Doubles::what() const throw()
{
	return (": number in double");
}
const char* Empty::what() const throw()
{
	return ("parsing: empty arg");
}
const char* BadArg::what() const throw()
{
	return (": not a positive int");
}

#elif TEMPLATE == 0

PmergeMe::PmergeMe()
{
	CLASS("Constructor", "PmergeMe");
}


PmergeMe::~PmergeMe()
{
	CLASS("Destructor", "PmergeMe");
}


PmergeMe::PmergeMe(const PmergeMe& other)
{
	CLASS("Constructor by copy", "PmergeMe");
	if (this == &other)
		return ;
}


PmergeMe& PmergeMe::operator= (const PmergeMe& other)
{
	CLASS("Operand = Constructor", "PmergeMe");
	if (this == &other)
		return (*this);
	return (*this);
}

void PmergeMe::VSortMergeAlgo(char **tab, int size)
{
    for (int i = 0; i < size; i++) {
        try {
            int num = std::atoi(tab[i]);
            this->Vnumbers.push_back(num);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid argument: " << tab[i] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Argument out of range: " << tab[i] << std::endl;
        }
    }
	
	std::vector<int> double_check;
	std::vector<int>::iterator V_it;
	std::vector<int>::iterator V_ite;
	V_it = Vnumbers.begin();
	V_ite = Vnumbers.end();
	while (V_it != V_ite)
	{
		if (std::find(double_check.begin(), double_check.end(), *V_it) != double_check.end())
		{
			std::cout << "Multiple iterations of the number " << *V_it << std::endl;
			throw PmergeMe::Doubles();
		}
		double_check.push_back(*V_it);
		V_it++;
	}
	std::cout << "Before:   ";
	Vprint_main(Vnumbers);
	Vmain();
}

void PmergeMe::Vmain()
{
	this->VcreatePairs();
	this->VsortPairs();
	this->VinsertByFirst();
	this->VinsertmergeSeconds();
}

void	Vprint_main(std::vector<int> v)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	it = v.begin();
	ite = v.end();
	while (it != ite)
	{
		std::cout << (*it) << ' ';
		it++;
	}
	std::cout << std::endl;
}

void	Vprint(std::vector<std::pair<int, int> > v)
{
	std::cout << "\n hey \n";
	std::vector<std::pair<int, int> >::iterator it;
	std::vector<std::pair<int, int> >::iterator ite;
	it = v.begin();
	ite = v.end();
	while (it != ite)
	{
		std::cout << (*it).first << " and " << (*it).second << '\n';
		it++;
	}
}

void PmergeMe::VcreatePairs()
{
	int 	a;
	int		b;

	Vmain_it = Vnumbers.begin();
	Vmain_ite = Vnumbers.end();
	Vmain_ite_plus_one = ++Vnumbers.end();
	Vmain_ite_minus_one = --Vnumbers.end();
	while (Vmain_it != Vmain_ite && Vmain_it != Vmain_ite_minus_one)
	{
		a = *Vmain_it;
		++Vmain_it;
		b = *Vmain_it;
		V.push_back(std::pair<int, int>(a, b));
		++Vmain_it;
	}
	this->Vimpair = 0;
	if (Vmain_it == Vmain_ite_minus_one)
		this->Vimpair = *(Vmain_ite_minus_one);
	// Vprint(this->V);
}

void PmergeMe::VsortPairs()
{
	Vit = V.begin();
	Vite = V.end();
	while (Vit != Vite)
	{
		if ((*Vit).first > (*Vit).second)
			std::swap((*Vit).first, (*Vit).second);
		Vit++;
	}
}

void PmergeMe::VinsertByFirst()
{
	std::vector<std::pair<int, int> >::iterator Vmap_ite_minus_one;
	
	Vmap_it = Vmap.begin();
	Vmap_ite = --Vmap.end();
	Vmap.insert(Vmap_it, *V.begin());
	V.erase(V.begin());
	Vmap.push_back(*V.begin());
	V.erase(V.begin());
	Vit = V.begin();
	Vite = V.end();
	std::cout << "here" << std::endl;
	if ((*Vmap.begin()).first > (*(--Vmap.end())).first)
		std::swap((*Vmap.begin()), (*(--Vmap.end())));
	while (Vit != Vite)
	{
		Vmap_it = Vmap.begin();
		Vmap_ite = --Vmap.end();
		while (Vmap_ite >= Vmap_it && (*Vit).first < (*(Vmap_ite)).first)
			Vmap_ite--;
		Vmap.insert(++Vmap_ite, *Vit);
		V.erase(Vit);
		Vit = V.begin();
		Vite = V.end();
	std::cout << "there" << std::endl;
	}
}

void PmergeMe::VinsertmergeSeconds()
{
	Vnumbers.clear();
	Vmap_it = Vmap.begin();
	Vmap_ite = Vmap.end();
	while (Vmap_it != Vmap_ite)
	{
		Vnumbers.push_back((*Vmap_it).first);
		Vmap_it++;
	}
	if (this->Vimpair)
	{
			Vmain_it = Vnumbers.begin();
			Vmain_ite = --Vnumbers.end();
			while (Vmain_ite >= Vmain_it && this->Vimpair < *(Vmain_ite))
				Vmain_ite--;
			Vnumbers.insert(++Vmain_ite, this->Vimpair);
	}
	Vit = Vmap.begin();
	Vite = Vmap.end();
	while (Vit != Vite)
	{
			Vmain_it = Vnumbers.begin();
			Vmain_ite = --Vnumbers.end();
			while (Vmain_ite >= Vmain_it && (*Vit).second < *(Vmain_ite))
				Vmain_ite--;
			Vnumbers.insert(++Vmain_ite, (*Vit).second);
		Vit++;
	}
	std::cout << "After:    ";
	Vprint_main(Vnumbers);
}


void PmergeMe::LSortMergeAlgo(char **tab, int size)
{
    for (int i = 0; i < size; i++) {
        try {
            int num = std::atoi(tab[i]);
            this->Lnumbers.push_back(num);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid argument: " << tab[i] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Argument out of range: " << tab[i] << std::endl;
        }
    }
	
	std::deque<int> double_check;
	std::deque<int>::iterator L_it;
	std::deque<int>::iterator L_ite;
	L_it = Lnumbers.begin();
	L_ite = Lnumbers.end();
	while (L_it != L_ite)
	{
		if (std::find(double_check.begin(), double_check.end(), *L_it) != double_check.end())
		{
			std::cout << "Multiple iterations of the number " << *L_it << std::endl;
			throw PmergeMe::Doubles();
		}
		double_check.push_back(*L_it);
		L_it++;
	}
	// std::cout << "Before:   ";
	// Lprint_main(Lnumbers);
	Lmain();
	

    std::deque<int>::iterator it = Lnumbers.begin();
    std::deque<int>::iterator ite = it + 1;

    while (ite != Lnumbers.end())
    {
        if (*it > *ite)
        {
            std::cout << "Stack is not ordered: " << *it << " is bigger than " << *ite << std::endl;
            return ;
        }
        it++;
        ite++;
    }
    std::cout << "Stack is ordered !" << std::endl;


}

void PmergeMe::Lmain()
{
	this->LcreatePairs();
	this->LsortPairs();
	this->LinsertByFirst();
	this->LinsertmergeSeconds();
}

void	Lprint_main(std::deque<int> v)
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator ite;
	it = v.begin();
	ite = v.end();
	while (it != ite)
	{
		std::cout << (*it) << ' ';
		it++;
	}
	std::cout << std::endl;
}

void	Lprint(std::deque<std::pair<int, int> > v)
{
	std::cout << "\n hey \n";
	std::deque<std::pair<int, int> >::iterator it;
	std::deque<std::pair<int, int> >::iterator ite;
	it = v.begin();
	ite = v.end();
	while (it != ite)
	{
		std::cout << (*it).first << " and " << (*it).second << '\n';
		it++;
	}
}

void PmergeMe::LcreatePairs()
{
	int 	a;
	int		b;

	Lmain_it = Lnumbers.begin();
	Lmain_ite = Lnumbers.end();
	Lmain_ite_plus_one = ++Lnumbers.end();
	Lmain_ite_minus_one = --Lnumbers.end();
	while (Lmain_it != Lmain_ite && Lmain_it != Lmain_ite_minus_one)
	{
		a = *Lmain_it;
		++Lmain_it;
		b = *Lmain_it;
		L.push_back(std::pair<int, int>(a, b));
		++Lmain_it;
	}
	this->Limpair = 0;
	if (Lmain_it == Lmain_ite_minus_one)
		this->Limpair = *(Lmain_ite_minus_one);
	// Lprint(this->L);
}

void PmergeMe::LsortPairs()
{
	Lit = L.begin();
	Lite = L.end();
	while (Lit != Lite)
	{
		if ((*Lit).first > (*Lit).second)
			std::swap((*Lit).first, (*Lit).second);
		Lit++;
	}
}

void PmergeMe::LinsertByFirst()
{
	std::deque<std::pair<int, int> >::iterator Lmap_ite_minus_one;
	
	Lmap_it = Lmap.begin();
	Lmap_ite = --Lmap.end();
	Lmap.insert(Lmap_it, *L.begin());
	L.erase(L.begin());
	Lmap.push_back(*L.begin());
	L.erase(L.begin());
	Lit = L.begin();
	Lite = L.end();
	if ((*Lmap.begin()).first > (*(--Lmap.end())).first)
		std::swap((*Lmap.begin()), (*(--Lmap.end())));
	while (Lit != Lite)
	{
		Lmap_it = Lmap.begin();
		Lmap_ite = --Lmap.end();
		while (Lmap_ite >= Lmap_it && (*Lit).first < (*(Lmap_ite)).first)
			Lmap_ite--;
		Lmap.insert(++Lmap_ite, *Lit);
		L.erase(Lit);
		Lit = L.begin();
		Lite = L.end();
	}
}

void PmergeMe::LinsertmergeSeconds()
{
	Lnumbers.clear();
	Lmap_it = Lmap.begin();
	Lmap_ite = Lmap.end();
	while (Lmap_it != Lmap_ite)
	{
		Lnumbers.push_back((*Lmap_it).first);
		Lmap_it++;
	}
	if (this->Limpair)
	{
			Lmain_it = Lnumbers.begin();
			Lmain_ite = --Lnumbers.end();
			while (Lmain_ite >= Lmain_it && this->Limpair < *(Lmain_ite))
				Lmain_ite--;
			Lnumbers.insert(++Lmain_ite, this->Limpair);
	}
	Lit = Lmap.begin();
	Lite = Lmap.end();
	while (Lit != Lite)
	{
			Lmain_it = Lnumbers.begin();
			Lmain_ite = --Lnumbers.end();
			while (Lmain_ite >= Lmain_it && (*Lit).second < *(Lmain_ite))
				Lmain_ite--;
			Lnumbers.insert(++Lmain_ite, (*Lit).second);
		Lit++;
	}
	// std::cout << "After:    ";
	// Lprint_main(Lnumbers);
}

const char *	PmergeMe::Doubles::what() const throw()
{
	return "has doubles";
}

#endif