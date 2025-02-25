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

    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        ClapTrap(const std::string &name);
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