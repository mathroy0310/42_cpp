
/* ************************************************************************** */
/*                                                                            */
/*                                                     ██   ██ ██████         */
/*   WrongAnimal.hpp                                   ██   ██      ██        */
/*                                                     ███████  █████         */
/*   By: maroy <maroy@student.42.qc>                        ██ ██             */
/*                                                          ██ ███████.qc     */
/*   Created: 2023/10/20 19:25:41 by maroy                                    */
/*   Updated: 2023/10/20 19:32:26 by maroy            >(.)__ <(.)__ =(.)__    */
/*                                                     (___/  (___/  (___/    */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include "common.hpp"

class WrongAnimal
{
  public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal(WrongAnimal const &src);

    WrongAnimal &operator=(WrongAnimal const &src);

    void   makeSound() const;
    string getType() const;

  protected:
    string _type;
};

#endif // WRONGANIMAL_H