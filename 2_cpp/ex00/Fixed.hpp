#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
	
		int					fixed_value;
		static const int	nb_fract_bits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed&);
		Fixed& operator= (const Fixed&);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
};


#endif
