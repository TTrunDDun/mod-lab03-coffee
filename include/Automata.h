// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include <list>

enum states { OFF, wait, accept, check, cook };

class automata {
private:
    int cash;
    std::string menu[7] = { "Capuchino", "Raf", "Americano", "Latte", "Flat White", "Espresso", "Dopio" };
    int prices[7] = { 120, 150, 80, 140, 150, 50, 100};
    states state;
    std::list<std::string> list;
public:
    automata();
    void on();
    void off();
    void coin(int coins);
    void etmenu();
    void getstate();
    void choice();
    void check();
    void cancel();
    void cook();
    void finish();
};
