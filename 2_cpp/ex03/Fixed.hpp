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
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		//operators
		Fixed& operator= (const Fixed&);
		bool operator> (const Fixed&) const;
		bool operator>= (const Fixed&) const;
		bool operator< (const Fixed&) const;
		bool operator<= (const Fixed&) const;
		bool operator== (const Fixed&) const;
		bool operator!= (const Fixed&) const;

		Fixed operator+ (const Fixed&) const;
		Fixed operator- (const Fixed&) const;
		Fixed operator* (const Fixed&) const;
		Fixed operator/ (const Fixed&) const;

		Fixed operator++ ();
		Fixed operator++ (int post);
		Fixed operator-- ();
		Fixed operator-- (int post);

		//min max
		static Fixed&	min(Fixed&, Fixed&);
		static const Fixed&	min(const Fixed&, const Fixed&);
		static Fixed&	max(Fixed&, Fixed&);
		static const Fixed&	max(const Fixed&, const Fixed&);

};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
