//
//  AnimationPlaybackTest.cpp
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/13/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#include <math.h>
#include "PingPongLoopingAnimationController.h"
#include "GameCodeException.h"
#include "gtest/gtest.h"

const float fDiff = 0.1;


TEST(PingPongLoopingAnimationController, normal){
    
    //Set animation with 100.0sec.
    const float maxFrame = 100.0;
    const float deltaTimePerSec = 1.0;
    PingPongLoopingAnimationController controller(maxFrame);
    
    EXPECT_FLOAT_EQ(controller.GetTime(), 0.0);
    
    //Forward playing of animation.
    for ( float frameSecond = deltaTimePerSec; frameSecond<= maxFrame ;
         frameSecond +=deltaTimePerSec ) {
        controller.Update(frameSecond);
        EXPECT_NE(controller.GetTime(), 0.0);
        EXPECT_FLOAT_EQ(controller.GetTime(), frameSecond);
    }
    
    //Play more time: It should play animation reversly.
    for ( float frameSecond = maxFrame+deltaTimePerSec; frameSecond<= 2*maxFrame ;
         frameSecond +=deltaTimePerSec ) {
        controller.Update(frameSecond);
        if ( controller.GetTime() != 0.0 )
            EXPECT_FLOAT_EQ(controller.GetTime(), maxFrame - (frameSecond - maxFrame) );
    }
    
}

TEST(PingPongLoopingAnimationController, preciseDeltaFrameTime){
    
    //Set animation with 300.0sec. => 100 Frame.
    const float maxFrameSec = 300.0;
    const float deltaTimePerSec = 0.0333; // 30 Frame per second.
    PingPongLoopingAnimationController controller(maxFrameSec);
    
    EXPECT_FLOAT_EQ(controller.GetTime(), 0.0);
    
    //Forward playing of animation.
    for ( float frameSecond = deltaTimePerSec; frameSecond<= maxFrameSec ;
         frameSecond +=deltaTimePerSec ) {
        controller.Update(frameSecond);
        float diff = fabs(controller.GetTime() - frameSecond);
        EXPECT_LE(diff, fDiff);
    }
    
    //Play more time: It should play animation reversly.
    for ( float frameSecond = maxFrameSec+deltaTimePerSec; frameSecond<= 2*maxFrameSec ;
         frameSecond +=deltaTimePerSec ) {
        controller.Update(frameSecond);
        if ( controller.GetTime() != 0.0 ){
            float diff = fabs(controller.GetTime() -
                              ( maxFrameSec - (frameSecond - maxFrameSec)) );
            EXPECT_LE(diff, fDiff);
        }
    }
    
}
