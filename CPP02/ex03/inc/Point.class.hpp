/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   Point.class.hpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/16 15:41:28 by maroy                                    */
/*   Updated: 2023/11/05 16:26:02 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H
# define POINT_H

# include "common.hpp"

class Point
{
  public:
	Point();
	Point(Fixed const x, Fixed const y);

	~Point();

	Fixed getX(void) const;
	Fixed getY(void) const;

	void printPoint(Point const &point) const;

  private:
	Fixed const _x;
	Fixed const _y;
};

#endif