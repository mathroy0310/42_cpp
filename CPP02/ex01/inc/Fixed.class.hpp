/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.class.hpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:48:57 by maroy                                    */
/*   Updated: 2023/11/05 16:14:23 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
  public:
	//#=- CONSTRUCTOR / DESTRUCTOR -=#//

	// default constructor
	Fixed();
	// constructor with int argument
	Fixed(int const n);
	// constructor with float argument
	Fixed(float const n);
	// by default, copy constructor performs a shallow copy
	Fixed(Fixed const &src);
	// destructor
	~Fixed();

	// #=- OPERATION OVERLOAD -=# //

	// opeartor =
	Fixed &operator=(Fixed const &rhs);
	// operator <<
	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

	// #=- GETTER -=# //

	int getRawBits(void) const;
	// #=- SETTER -=# //

	void setRawBits(int const raw);
	// #=- OTHER -=# //

	void printRawBits(void) const;

	int toInt(void) const;
	float toFloat(void) const;

  private:
	int _rawBits;
	static const int _fractionalBits;
};

#endif // FIXED_H