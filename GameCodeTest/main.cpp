//
//  main.cpp
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/7/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#include <iostream>
#include "gtest/gtest.h"


TEST(CASE2, ZERO){
    EXPECT_EQ(0, 0);
    
}

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
