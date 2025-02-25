#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
    protected:
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

継承クラスScavTrapでヒットポイントをいじろうとしてもprivateだからかさわれない。そういう仕様か？
それともsetter的なのを用意するのか？
https://rinatz.github.io/cpp-book/ch07-03-inheritance/
いや、protectedにするのか!そうすれば子クラスから親クラス側で設計したメンバ変数にも触れる。

https://cpp-lang.sevendays-study.com/ex-day6.html
virtualじゃないといけない理由
virtualをつけたメソッドは、仮想関数となることから、
親クラスからメンバ関数が呼ばれた場合は、子クラスの処理が実行されます。
実は、これはデストラクタについても同様です。

仮にdeleteが呼ばれた場合、親クラスのデストラクタのみしか呼ばれず、
子クラスのですとらくたは呼ばれない。

このような場合、メモリ解放とかでやばくなる
virtualをつければ、サブクラスのデストラクタが実行されたのちに、親クラスのコンストラクタが実行される。
よって、親クラスのデストラクタにはvirtualをつけよう！

*/