#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        void guardGate();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ScavTrap(const std::string &name);
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
};

#endif


/*

前回の続き。
https://cpp-lang.sevendays-study.com/day6.html
継承の概念はこれがわかりやすい。
なお、CCarおよび、CAmbulanceクラスについている、virtual(バーチャル)修飾子に関しては、必ずつけるようにしてください。
通常、C++言語では、継承を用いる場合、virtualをデストラクタにつけるように推奨されています

https://stackoverflow.com/questions/23647409/error-base-class-constructor-must-explicitly-initialize-parent-class-construct
ScavTrapで呼び出すときに、明示的に親クラスのコンストラクタを作ってあげないと、
rror: constructor for 'ScavTrap' must explicitly initialize the base class 'ClapTrap' which does not have a default constructor
こういうエラーが出る。


*/