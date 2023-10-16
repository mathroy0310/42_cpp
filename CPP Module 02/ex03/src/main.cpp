/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   main.cpp                                          ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/14 20:51:15 by maroy                                    */
/*   Updated: 2023/10/16 17:16:01 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#include "../inc/common.hpp"

int main( void ) {

	Fixed bx(20);
	Fixed by(1);
	Fixed cx(10);
	Fixed cy(30);
	
	Point const a(by, by); // (1, 1)
	Point const b(bx, by); // (20, 1)
	Point const c(cx, cy); // (10, 30)

	Fixed px(60);
	Fixed py(50);
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
	bool isInside = bsp(a, b, c, point);
	isInside ? res = "Point is inside the triangle" : res = "Point is outside the triangle";
	cout << res << endl;

	return 0;
}