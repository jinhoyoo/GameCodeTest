//
//  PingPongLoopingAnimationController.cpp
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/13/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#include <math.h>
#include "PingPongLoopingAnimationController.h"


PingPongLoopingAnimationController::PingPongLoopingAnimationController( float totalLengthSecond ){
    
    _currentFrame = 0;
    _totalFrame = totalLengthSecond * _framePerSecond ;
    _isReversePlay = false;
    
    //TO-DO: Allocate buffer for animation.
    
}


PingPongLoopingAnimationController::~PingPongLoopingAnimationController(){
    
}

//TO-DO: Load and set animation data.


void PingPongLoopingAnimationController::Update( float timestepSecond ){

    int currentFrame = ceil(timestepSecond*_framePerSecond);
    
    if (currentFrame > _totalFrame )
        _isReversePlay = true;
    else if( currentFrame <= 0.0)
        _isReversePlay = false;
        
    
    if (_isReversePlay){
        int reverseFrame = currentFrame % _totalFrame;
        
        if( reverseFrame == 0.0 )
            _currentFrame = 0.0;
        else
            _currentFrame = _totalFrame - reverseFrame;
    }else
        _currentFrame = MAX(currentFrame, 0.0);

    //TO-DO: Get animation motion data .

    
    //TO-DO: Update transform component of object to animate.
    
}



float PingPongLoopingAnimationController::GetTime() const{
    
    float currentTime = ( (float)_currentFrame / _framePerSecond );
    return currentTime;
}

