//
//  FindNext.cpp
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/8/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"

std::string FindNext(std::vector<std::string> items, std::string current)
{
    bool returnNext = false;
    
    for (auto item : items){
        
        if (returnNext)
            return item;
        else if (item == current)
            returnNext = true;
    }
    return "";
}

std::string OptimizedFindNext(std::vector<std::string> &items, std::string current)
{
    bool returnNext = false;
    
    for (auto const &item : items){
        
        if (returnNext)
            return item;
        else if (item == current)
            returnNext = true;
    }
    return "";

}

//Test fixture
class FindNextTest : public testing::Test {
protected:
    virtual void SetUp() {
        _stringArray.reserve(15);
        _stringArray.push_back("Pages");
        _stringArray.push_back("you");
        _stringArray.push_back("view");
        _stringArray.push_back("in");
        _stringArray.push_back("incognito");
        _stringArray.push_back("tabs");
        _stringArray.push_back("will not");
        _stringArray.push_back("stick");
        _stringArray.push_back("around");
        _stringArray.push_back("in");
        
    }
    
    // virtual void TearDown() {}
    std::vector<std::string> _stringArray;
};


TEST_F(FindNextTest, NormalVersion){
    
    for ( int i=0; i<999999; ++i) {
        std::string nextWord
            = FindNext( _stringArray, "in");
        
        EXPECT_EQ(nextWord, "incognito");
    }
}



TEST_F(FindNextTest, OptimizedVersion){
    
    for ( int i=0; i<999999; ++i) {
        std::string nextWord
        = OptimizedFindNext( _stringArray, "in");
        
        EXPECT_EQ(nextWord, "incognito");
    }

    
    
}



