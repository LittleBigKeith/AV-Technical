﻿#include "gtest/gtest.h"
#include "main.h"
#include "testerFunction.cpp"

TEST(MoneyTest, CheckMoneyInWallet) {
	ASSERT_EQ(5000, Main::testerFunction());
}

//To run the gtest:
//	./TesterFunction --gtest_repeat=1000 --gtest_break_on_failure
