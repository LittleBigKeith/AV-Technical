#pragma once

#ifndef NMP_MAIN_H
#define NMP_MAIN_H

#include <mutex>

class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0) {}
    int getMoney();
    void addMoney(int money);
};

class Main {
public:
	static int testerFunction();
};
#endif

