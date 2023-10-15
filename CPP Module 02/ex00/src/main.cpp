/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:51:15 by maroy                                    */
/*   Updated: 2023/10/14 20:52:38 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;
	return EXIT_SUCCESS;
}