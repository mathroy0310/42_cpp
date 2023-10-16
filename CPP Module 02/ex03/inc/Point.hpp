/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Point.hpp                                         ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/16 15:41:28 by maroy                                    */
/*   Updated: 2023/10/16 16:53:56 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"
#include "../inc/Fixed.hpp"

class Point{
	public:
		Point();
		Point( Fixed const x, Fixed const y );

		~Point();
 		
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
		
		void	printPoint( Point const &point ) const;
	private:
		Fixed	const	_x;
		Fixed	const	_y;	
};