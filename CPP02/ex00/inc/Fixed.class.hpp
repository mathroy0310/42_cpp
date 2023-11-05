/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Fixed.hpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:48:57 by maroy                                    */
/*   Updated: 2023/10/16 12:43:22 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
# define FIXED_H

class Fixed{

	public:

		Fixed();
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &	operator=( Fixed const & rhs );

		// #=- GETTER -=# //
		
		int		getRawBits( void ) const;
		// #=- SETTER -=# //
		
		void	setRawBits( int const raw );
		// #=- OTHER -=# //

		void	printRawBits( void ) const;

	private:

		int					_rawBits;
		static const int	_fractionalBits;
};

#endif // FIXED_H
