#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

	template<typename T>
void	print(T& a)
{
	std::cout << "Printed: " << a << std::endl;
}
	template<typename T>
void	incr(T& a)
{
	a += 1;
}	

	template<typename T>
void	decr(T& a)
{
	a -= 1;
}	

	template<typename T>
void	iter(T* tab, size_t size, void(f)(T&))
{
	for (size_t i = 0; i < size; i++)
	{
		f(tab[i]);
	}
	
}

#endif
