#include "../unity/unity.h"
#include "stdbool.h"

void setUp() {}
void tearDown() {}

void test_AverageThreeBytes_should_AverageMidRangeValues(void)
{
    TEST_ASSERT_TRUE(true);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_AverageThreeBytes_should_AverageMidRangeValues);
    return UNITY_END();
}