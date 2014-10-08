//
//  ProjectileAllocator.h
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/7/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#ifndef __GameCodeTest__ProjectileAllocator__
#define __GameCodeTest__ProjectileAllocator__

#include <iostream>
#include "GameCodeException.h"

//Element to create
class Projectile;


//Allocator: Use this one to create Projectile.
class ProjectileAllocator
{
    
public:
    //Allocate the projectile's pool.
    ProjectileAllocator(int maxProjectiles);
    
    //Allocate a projectile.
    Projectile* Alloc();
    
    //Release a projectile. 
    void Release(Projectile* projectile);
    
public:
    ~ProjectileAllocator();
    
public:
    int GetNumberOfProjectile();
    
private:
    Projectile* _projectiles;
    bool      * _tableUsedProjectile;
    int         _numProjectileUsed;
    int         _maxProjectiles;
    
};


#endif /* defined(__GameCodeTest__ProjectileAllocator__) */
