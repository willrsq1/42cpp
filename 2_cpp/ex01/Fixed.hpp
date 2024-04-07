#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
	
		int					fixed_value;
		static const int	nb_fract_bits;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed&);
		Fixed& operator= (const Fixed&);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
