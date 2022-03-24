#include "main.h"
#include <vector>
#include <thread>

//source included in Test.cpp for Google Test

int Main::testerFunction()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for (int i = 0; i < threads.size(); i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}

std::mutex myMutex;

int Wallet::getMoney()
{
    return mMoney;
}

void Wallet::addMoney(int money)
{
    std::lock_guard<std::mutex> guard(myMutex);
    for (int i = 0; i < money; ++i)
    {
        mMoney++;
    }
}
