#include <gtest/gtest.h>

extern "C" {
	#include "string/ft_string.h"
}

TEST(string, stringInit)
{
	t_string *string = stringInit();
	ASSERT_TRUE(string != NULL);
	ASSERT_TRUE(stringSize(string) == 0);
	ASSERT_TRUE(stringCapacity(string) == 0);
	ASSERT_TRUE(stringGetStr(string) == NULL);
	stringFree(&string);
	ASSERT_TRUE(string == NULL);
}
TEST(string, stringReserve)
{
	t_string *string = stringInit();
	stringReserve(string, 10);
	ASSERT_TRUE(stringCapacity(string) == 10);
	ASSERT_TRUE(stringSize(string) == 0);
	ASSERT_TRUE(stringGetStr(string) != NULL);
	stringFree(&string);
	ASSERT_TRUE(string == NULL);
}
TEST(string, stringAppendCString)
{
	t_string *string = stringInit();
	stringReserve(string, 5);
	stringAppendCString(string, "advce");
	ASSERT_TRUE(stringCapacity(string) == 10);
	ASSERT_TRUE(stringSize(string) == 5);
	ASSERT_TRUE(stringGetStr(string) != NULL);
	ASSERT_TRUE(strcmp(stringGetStr(string), "advce") == 0);
	stringFree(&string);
	ASSERT_TRUE(string == NULL);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}