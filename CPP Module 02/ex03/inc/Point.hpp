/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Point.hpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/16 15:41:28 by maroy                                    */
/*   Updated: 2023/10/16 16:12:28 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/Fixed.hpp"

class Point{
	public:
		Point();
		Point( Fixed x, Fixed y );
		Point( Point const &src );

		~Point();

		Point	&operator=( Point const &rhs ) ;
		
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

		void 	setX(Fixed x );
		void 	setY(Fixed y );
	private:
		Fixed	const	_x;
		Fixed	const	_y;	
};