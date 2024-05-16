// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
 protected:
    Automata d;
};

TEST(AutomataTest, TEST1) {
    Automata d;
    d.off();
    EXPECT_EQ(d.getstate(), states::OFF);
}

TEST(AutomataTest, TEST2) {
    Automata d;
    d.on();
    d.off();
    EXPECT_EQ(d.getstate(), states::OFF);
}

TEST(AutomataTest, TEST3) {
    Automata d;
    d.on();
    d.etmenu();
    EXPECT_EQ(d.getstate(), states::WAIT);
}

TEST(AutomataTest, TEST4) {
    Automata d;
    d.on();
    d.coin(600);
    EXPECT_EQ(d.getstate(), states::ACCEPT);
}

TEST(AutomataTest, TEST5) {
    Automata d;
    d.on();
    d.coin(10);
    d.cancel();
    EXPECT_EQ(d.getstate(), states::WAIT);
}

TEST(AutomataTest, TEST6) {
    Automata d;
    d.on();
    d.coin(3040);
    d.choice("Raf");
    EXPECT_EQ(d.getstate(), states::COOK);
}

TEST(AutomataTest, TEST7) {
    Automata d;
    d.on();
    d.coin(3);
    d.choice("Raf");
    EXPECT_EQ(d.getstate(), states::CHECK);
}


TEST(AutomataTest, TEST8) {
    Automata d;
    d.on();
    d.coin(33);
    d.choice("Latte");
    EXPECT_EQ(d.getstate(), states::CHECK);
}


TEST(AutomataTest, TEST9) {
    Automata d;
    d.on();
    d.coin(300);
    d.choice("Latte");
    EXPECT_EQ(d.getstate(), states::ACCEPT);
}


TEST(AutomataTest, TEST10) {
    Automata d;
    d.on();
    d.finish();
    EXPECT_EQ(d.getstate(), states::WAIT);
}
