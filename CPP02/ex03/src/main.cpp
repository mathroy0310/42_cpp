/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:51:15 by maroy                                    */
/*   Updated: 2023/11/05 16:27:19 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "common.hpp"

/*
	To view the triangle, copy the following link and paste it in your browser:

	https://www.desmos.com/geometry/j5d9uewfb6
*/
int	main(void)
{
	Fixed bx(20);
	Fixed by(0);
	Fixed cx(10);
	Fixed cy(30);

	Point const a;         // (0, 0)
	Point const b(bx, by); // (20, 0)
	Point const c(cx, cy); // (10, 30)

	Fixed px(10);
	Fixed py(25);
	Point const point(px, py);
	cout << ANSI_COLOR_CYAN << "Point A: " << ANSI_COLOR_RESET;
	a.printPoint(a);
	cout << ANSI_COLOR_CYAN << "Point B: " << ANSI_COLOR_RESET;
	b.printPoint(b);
	cout << ANSI_COLOR_CYAN << "Point C: " << ANSI_COLOR_RESET;
	c.printPoint(c);
	cout << ANSI_COLOR_CYAN << "Point P: " << ANSI_COLOR_RESET;
	point.printPoint(point);

	string res;
	string color;
	bool is_inside = bsp(a, b, c, point);
	is_inside ? res = "Point is inside the triangle" : res = "Point is outside the triangle";
	is_inside ? color = ANSI_COLOR_GREEN : color = ANSI_COLOR_RED;

	cout << color << res << endl;

	return (0);
}