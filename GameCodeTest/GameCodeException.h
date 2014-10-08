//
//  GameCodeException.h
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/8/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#ifndef GameCodeTest_GameCodeException_h
#define GameCodeTest_GameCodeException_h

struct GameCodeException : public std::exception
{
    std::string s;
    GameCodeException(std::string ss) : s(ss) {}
    ~GameCodeException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};


#endif
