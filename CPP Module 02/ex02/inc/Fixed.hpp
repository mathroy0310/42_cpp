/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.hpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:48:57 by maroy                                    */
/*   Updated: 2023/10/16 14:24:31 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
# define FIXED_H

#include "common.hpp"

class Fixed{

	public:

		//#=- CONSTRUCTOR / DESTRUCTOR -=#//

		// default constructor
		Fixed();
		// constructor with int argument
		Fixed( int const n );
		// constructor with float argument
		Fixed( float const n );
		// by default, copy constructor performs a shallow copy
		Fixed( Fixed const & src );
		// destructor
		~Fixed();

		// #=- OPERATION OVERLOAD -=# //
		
		// -- Comparison operators -- //
		
		// opeartor `=`
		Fixed &	operator=( Fixed const & rhs );
		// operator `<`
		bool	operator<( Fixed const & rhs ) const;
		// operator `>`
		bool	operator>( Fixed const & rhs ) const;
		// operator `<=`
		bool	operator<=( Fixed const & rhs ) const;
		// operator `>=`
		bool	operator>=( Fixed const & rhs ) const;
		// operator `==`
		bool	operator==( Fixed const & rhs ) const;

		// -- Arithmetic operators -- //
		
		// operator `+`
		Fixed	operator+( Fixed const & rhs ) const;
		// operator `-`
		Fixed 	operator-( Fixed const & rhs ) const;
		// operator `*`
		Fixed	operator*( Fixed const & rhs ) const;
		// operator `/`
		Fixed	operator/( Fixed const & rhs ) const;

		// -- Increment / Decrement operators -- //

		// operator `++` prefix
		Fixed&	operator++( void );
		// operator `++` postfix
		Fixed	operator++( int );
		// operator `--` prefix
		Fixed&	operator--( void );
		// operator `--` postfix
		Fixed	operator--( int );

		// -- Bitshift operators ? -- //
		// operator `<<`
		friend ostream & operator<<( ostream& os, const Fixed& fixed ) ;

		// #=- GETTER -=# //
		
		int		getRawBits( void ) const;
		// #=- SETTER -=# //

		void	setRawBits( int const raw );
		// #=- OTHER -=# //

		void	printRawBits( void ) const;
		void	printBits( string name ) const;

		int		toInt( void ) const;
		float	toFloat( void ) const;
		//min and max
		static const Fixed &	min( const Fixed & a, const Fixed & b );
		static const Fixed &	max( const Fixed & a, const Fixed & b );

	private:

		int					_rawBits;
		static const int	_fractionalBits;
};

#endif // FIXED_H