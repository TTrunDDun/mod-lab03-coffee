// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public testing::Test {
 protected:
    Automata d;
};

TEST(AutomataTest, TEST1) {
    Automata d;
    d.on();
    d.off();
    d.on();
    d.on();
    d.off();
    EXPECT_EQ(OFF, d.getstate());
}

TEST(AutomataTest, TEST2) {
    Automata d;
    d.on();
    d.coin(9);
    d.choice(3);
    EXPECT_EQ(false, d.check(3));
}

TEST(AutomataTest, TEST3) {
    Automata d;
    d.on();
    d.coin(5);
    d.choice(3);
    EXPECT_EQ(false, d.check(3));
}

TEST(AutomataTest, TEST4) {
    Automata d;
    d.on();
    d.coin(600);
    d.choice(4);
    d.cook(4);
    d.finish(4);
    EXPECT_EQ(WAIT, d.getstate());
}

TEST(AutomataTest, TEST5) {
    Automata d;
    d.on();
    d.coin(33);
    d.choice(3);
    EXPECT_EQ(false, d.check(3));
}

TEST(AutomataTest, TEST6) {
    Automata d;
    d.on();
    d.coin(3040);
    d.choice(5);
    d.cook(5);
    d.finish(5);
    EXPECT_EQ(WAIT, d.getstate());
}

TEST(AutomataTest, TEST7) {
    Automata d;
    d.on();
    d.coin(3);
    d.choice(3);
    EXPECT_EQ(false, d.check(3));
}


TEST(AutomataTest, TEST8) {
    Automata d;
    d.on();
    d.coin(33);
    d.choice(6);
    EXPECT_EQ(false, d.check(6));
}


TEST(AutomataTest, TEST9) {
    Automata d;
    d.on();
    d.coin(43);
    d.choice(1);
    EXPECT_EQ(false, d.check(1));
}


TEST(AutomataTest, TEST10) {
    Automata d;
    d.on();
    d.coin(33);
    d.choice(0);
    EXPECT_EQ(false, d.check(0));
}
