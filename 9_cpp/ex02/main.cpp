# include "PmergeMe.hpp"
# include <sys/time.h>

time_t	ft_time_microsec(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

void	display_time(time_t spent_time, std::string name)
{
	std::cout  << "For " << name << ": ";
	if (spent_time / 1000000 > 0)
		std::cout << spent_time / 1000000 << "secs, ";
	if ((spent_time % 1000000) / 1000 > 0)
		std::cout << (spent_time % 1000000) / 1000 << "ms and ";
	std::cout << (spent_time % 1000) << "us" << std::endl;
}

#if TEMPLATE == 1

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Not a valid arg (not a sequence of positive ints).\n";
		return (1);
	}

	PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > s;
	PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > t;
	try
	{
		time_t	start = ft_time_microsec();
		time_t	spent_time;
		std::string str;

		str = s._SortStack(&argv[1], argc - 1);
		spent_time = ft_time_microsec() - start;
		std::cout << str;
		display_time(spent_time, "vector");

		start = ft_time_microsec();
		t._SortStack(&argv[1], argc - 1);
		spent_time = ft_time_microsec() - start;
		display_time(spent_time, "deque");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}

#elif TEMPLATE == 0

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Not a valid arg (not a sequence of positive ints).\n";
		return (1);
	}
	try
	{
		PmergeMe s;

		time_t	start = ft_time_microsec();
		time_t	spent_time;

		s.VSortMergeAlgo(&argv[1], argc - 1);
		spent_time = ft_time_microsec() - start;
		display_time(spent_time, "vector");
		{
			
			time_t	start = ft_time_microsec();
			time_t	spent_time;

			s.LSortMergeAlgo(&argv[1], argc - 1);
			spent_time = ft_time_microsec() - start;
			display_time(spent_time, "dqueue");
		}
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: "<< e.what() << '\n';
		return (1);
	}
	return (0);		
}
#endif