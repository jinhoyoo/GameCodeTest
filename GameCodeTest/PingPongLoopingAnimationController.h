//
//  PingPongLoopingAnimationController.h
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/13/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#ifndef __GameCodeTest__PingPongLoopingAnimationController__
#define __GameCodeTest__PingPongLoopingAnimationController__

#include <iostream>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


//Motion data per frame.
class MotionData{
public:
    float dx;
    float dy;
    float dz;
};

//Motion loop animation controller
class PingPongLoopingAnimationController{
    
public:
    PingPongLoopingAnimationController(float totalLengthSecond);
    
    void Update(float timestepSecond);
    
    float GetTime() const;
    
    ~PingPongLoopingAnimationController();
    
    //TO-DO: Load and set animation data.

    
private:
    
    //Configure 30 frame per second.
    const float _framePerSecond = 30.0;
    
    //Motion data.
    MotionData* _motionData;
    
    int _currentFrame;
    int _totalFrame;
    bool _isReversePlay;
    
    
};


#endif /* defined(__GameCodeTest__PingPongLoopingAnimationController__) */
