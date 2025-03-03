#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
    private:
        std::string Name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;
        int MaxHP;

    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
};

#endif

/*

攻撃と回復には1EPがかかる。
HPかEPがないとなにもできない。

他のくらっぴとらっぷと
他のくらっぷとらっぷの値を参照しなくていい
    ->？つまり相手のHPとか考慮しなくていいってこと？
    ->まあ今回はダメージ0だからいいのか。


*/