// Copyright 2022 UNN-IASR

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <string>
#include <list>

enum states { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::string menu[7] = { "Capuchino",
        "Raf",
        "Americano",
        "Latte",
        "Flat White",
        "Espresso",
        "Dopio" };
    int prices[7] = { 120,
        150,
        80,
        140,
        150,
        50,
        100 };
    states state;
    std::list<std::string> list;

 public:
    Automata();
    void on();
    void off();
    void coin(int coins);
    void etmenu();
    states getstate();
    void choice(std:: string drink);
    void check();
    void cancel();
    void cook();
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
