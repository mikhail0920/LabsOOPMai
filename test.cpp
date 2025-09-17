#include "closest_pair.h"
#include "gtest/gtest.h"

TEST(ClosestPairTest, SmallLimit){
    EXPECT_EQ(closest_pair_tonum(1), std::make_pair(-1, -1));
}

TEST(ClosestPairTest, Limit10){
    EXPECT_EQ(closest_pair_tonum(10), std::make_pair(5, 4));
}

TEST(ClosestPairTest, Limit30){
    EXPECT_EQ(closest_pair_tonum(30), std::make_pair(29, 20));
}

TEST(ClosestPairTest, Limit50){
    EXPECT_EQ(closest_pair_tonum(50), std::make_pair(45, 36));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}