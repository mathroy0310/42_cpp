/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   bsp.cpp                                           ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/11/05 16:26:25 by maroy                                    */
/*   Updated: 2023/11/05 16:26:26 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"

Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	Fixed dest = ((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2)) / 2);
	if (dest < 0)
		dest = dest * -1;
	return (dest);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{


	Fixed const	triangle = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed const	pa = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed const pb = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	Fixed const pc = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());

	return (triangle  == pa + pb + pc);
}