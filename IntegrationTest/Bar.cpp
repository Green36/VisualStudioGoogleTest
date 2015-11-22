// IntegrationTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "gtest/gtest.h"


class BarTest : public ::testing::Test {
protected:
	/*
	// 全てのテスト開始前に１回だけ実行される
	static void SetUpTestCase() {
		printf("SetUpTestCase\n");
	}

	// 全てのテスト終了後に１回だけ実行される
	static void TearDownTestCase() {
		printf("TearDownTestCase\n");
	}

	// 一つのテストケース実行前に１回実行される
	virtual void SetUp()
	{
		printf("SetUp\n");
	}

	// 一つのテストケース実行後に１回実行される
	virtual void TearDown()
	{
		printf("TearDown\n");
	}
	*/
};

TEST_F(BarTest, Test1) {
	EXPECT_EQ(0,0);
}
TEST_F(BarTest, Test2) {
	EXPECT_EQ(0, 0);
}
