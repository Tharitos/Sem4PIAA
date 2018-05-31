#include <vector>
#include "Bohr.h"
#include "Aho.h"
#include "gtest/gtest.h"

struct AhoTest 
{
	string T;
	vector<string> P;
	vector<Item> res;
};

AhoTest Test1 = { "wasitacaroracatisow",
	{ "ca", "car", "cat", "or" },
	{ { 7, 1 }, { 7, 2 }, { 10, 4 }, { 13, 1 }, { 13, 3 }
	} 
};

AhoTest Test2 = { "abcdcbcddbbbcccbbbcccbb",
	{ "abc", "bcdc", "cccb", "bcdd", "bbbc" },
	{ { 1, 1 }, { 2, 2 }, { 6, 4 }, { 10, 5 }, { 13, 3 }, { 16, 5 }, { 19, 3 }
	}
};

class AHOTest : public ::testing::TestWithParam<AhoTest>
{
public:
	virtual void SetUp() {}
	virtual void TearDown() {}
};

INSTANTIATE_TEST_CASE_P(AHOTestIns, AHOTest,
	::testing::Values(Test1, Test2));

TEST_P(AHOTest, AHTestTrue)
{
	vector<Item> res = doAhoCorasick(GetParam().T, GetParam().P);
	ASSERT_TRUE(compare(GetParam().res, res));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE");
	return 0;
}