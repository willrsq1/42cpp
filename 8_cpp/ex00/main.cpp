#include "easyfind.hpp"

int main()
{
	std::vector<int>	v(300);

	std::fill(v.begin(), v.end(), 10);
	std::fill(v.begin(), v.end() - 10, 15);
	try
	{
		easyfind(v, 10);
		std::vector<int> s(1000);
		s[717] = 15;
		easyfind(s, 15);
		easyfind(s, 9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
