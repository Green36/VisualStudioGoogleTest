// IntegrationTest.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "gtest/gtest.h"


class FooTest : public ::testing::Test {
	/*
protected:
	// �S�Ẵe�X�g�J�n�O�ɂP�񂾂����s�����
	static void SetUpTestCase() {
		printf("SetUpTestCase\n");
	}

	// �S�Ẵe�X�g�I����ɂP�񂾂����s�����
	static void TearDownTestCase() {
		printf("TearDownTestCase\n");
	}

	// ��̃e�X�g�P�[�X���s�O�ɂP����s�����
	virtual void SetUp() 
	{ 
		printf("SetUp\n");
	}

	// ��̃e�X�g�P�[�X���s��ɂP����s�����
	virtual void TearDown()
	{
		printf("TearDown\n");
	}
	*/
};

TEST_F(FooTest, Test1) {
//	printf("FooTest, Test1\n");
	EXPECT_EQ(0, 0);
}
TEST_F(FooTest, Test2) {
//	printf("FooTest, Test2\n");
	EXPECT_EQ(0, 0);
}
