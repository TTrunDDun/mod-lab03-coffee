// Copyright 2022 UNN-IASR

#include "Automata.h"
#include <iostream>


Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
    std::cout << "The Coffe Machin is working." << std::endl;
}

void Automata::off() {
    state = OFF;
    std::cout << "Automata is turned off." << std::endl;
}

void Automata::coin(int coins) {
    if (state == WAIT || state == ACCEPT) {
        std::cout << "Please,put the money." << std::endl;
        cash += coins;
        state = ACCEPT;
        std::cout << "The balance: " << cash << std::endl;
    }
}
void Automata::etmenu() {
    std::cout << "Choose a coffee"<< std::endl << "Menu:" << std::endl;
    for (size_t i = 0; i < 7; i++) {
        std::cout << "(- " << menu[i];
        std::cout << ": price " << prices[i] << ")" << std::endl;
    }
}

states Automata::getstate() {
    return state;
}

void Automata::choice(std::string drink) {
    std::cout << "Enter your choice: ";
    list.push_front(drink);
    std::cout << drink << std::endl;
}


void Automata::check() {
    int total = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        for (int i = 0; i < 7; i++) {
            if (*it == menu[i]) {
                total += prices[i];
            }
        }
    }
    if (cash >= total) {
        state = COOK;
        std::cout << "Payment accepted. Please waitk." << std::endl;
    } else {
        std::cout << "Please insert more.";
        state = CHECK;
        std::cout << std::endl;
    }
}

void Automata::cancel() {
    if ((state = CHECK) || (state = ACCEPT)) {
        cash = 0;
        list.clear();
        state = WAIT;
        std::cout << "Order canceled. Make a new selection." << std::endl;
    }
}

void Automata::cook() {
    if (state != CHECK) {
        std::cout << "Cooking your coffee..." << std::endl;
        state = WAIT;
    } else {
        state = CHECK;
    }
}

void Automata::finish() {
    cash = 0;
    list.clear();
    state = WAIT;
    std::cout << "Thank you. Have a nice day!" << std::endl;
}
