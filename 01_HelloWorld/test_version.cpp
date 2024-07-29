#include "lib.h"
#include <gtest/gtest.h>

TEST(VersionCheck, GreaterThanZero){
    auto ver = ver::version();
    EXPECT_NE(ver,0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}