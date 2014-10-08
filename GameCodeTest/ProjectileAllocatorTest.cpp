//
//  ProjectileAllocatorTest.cpp
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/7/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#include "ProjectileAllocator.h"
#include "GameCodeException.h"
#include "gtest/gtest.h"


//Normal case.
TEST( ProjectileAllocator, NormalOperation){
    ProjectileAllocator allocator(3);
    Projectile* projectile = allocator.Alloc();
    EXPECT_NE(projectile, (Projectile*)NULL);
}

//If user calls Alloc() even maxProjectiles=0, Alloc() should return null.
TEST( ProjectileAllocator, TryToAllocNoMaxProjectile){
    ProjectileAllocator allocator(0);
    Projectile* projectile = allocator.Alloc();
    EXPECT_EQ(projectile, (Projectile*)NULL);
}


//If user calls Alloc() more than maxProjectiles times, Alloc() should make
//exception to detect critical error. It means no more memory slot.
TEST( ProjectileAllocator, TryToAllocBiggerThanMaxProjectile){
    
    const int numProjectile = 50;
    ProjectileAllocator allocator(numProjectile);
    Projectile* pProjectile = NULL;
    Projectile* pProjectile2 = NULL;
    
    for (int i=0; i<numProjectile; ++i) {
        pProjectile = allocator.Alloc();
        EXPECT_NE(pProjectile, (Projectile*)NULL);
        EXPECT_NE(pProjectile, pProjectile2);
        EXPECT_EQ(i+1, allocator.GetNumberOfProjectile() );
        
        pProjectile2 = pProjectile;
    }
    
    ASSERT_ANY_THROW( pProjectile = allocator.Alloc() );
}


//If user calls Relase() more then maxProjectiles,
//Allocator should happen exception to detect critical error.
TEST( ProjectileAllocator, TryToReleaseMorethanMaxProjectiles){
    
    const int numProjectile = 50;
    ProjectileAllocator allocator(numProjectile);
    Projectile* pProjectile = NULL;
    
    for (int i=0; i<numProjectile; ++i) {
        pProjectile = allocator.Alloc();
        allocator.Release( pProjectile );
    }
    
    EXPECT_NE(pProjectile, (Projectile*)NULL);
    ASSERT_ANY_THROW( allocator.Release(NULL) );
 
    
}

