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
    std::string menu[7];
    int prices[7];
    states state;
    std::list<std::string> list;
public:
    Automata();
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

#endif  // INCLUDE_AUTOMATA_H_
