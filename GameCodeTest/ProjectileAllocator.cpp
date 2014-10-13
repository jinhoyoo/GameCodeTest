//
//  ProjectileAllocator.cpp
//  GameCodeTest
//
//  Created by Jinho Yoo on 10/7/14.
//  Copyright (c) 2014 Jinho Yoo. All rights reserved.
//

#include "ProjectileAllocator.h"

class Projectile{
        
};

ProjectileAllocator::ProjectileAllocator(int maxProjectiles){
    
    _projectiles = new Projectile[maxProjectiles];
    _tableUsedProjectile = new bool[maxProjectiles];
    
    for (int i=0; i<maxProjectiles; ++i)
        _tableUsedProjectile[i]=false;
    
    _numProjectileUsed = 0;
    _maxProjectiles = maxProjectiles;    
}

Projectile* ProjectileAllocator::Alloc(){
    
    if ( 0 == _maxProjectiles)
        return NULL;
    
    if (_numProjectileUsed < _maxProjectiles){
        
        _tableUsedProjectile[_numProjectileUsed] = true;
        Projectile* pt = &_projectiles[_numProjectileUsed];
        ++_numProjectileUsed;
        return pt;
    }else
        throw GameCodeException("No more projectile!");
}


int ProjectileAllocator::GetNumberOfProjectile() const{
    return _numProjectileUsed;
}

void ProjectileAllocator::Release(Projectile* projectile){

    if ( NULL == projectile)
        throw GameCodeException("The projectile argument is not from this allocator!!");

    
    for (int i=0; i< _maxProjectiles; ++i) {
        
        if( _tableUsedProjectile[i] &&
           ( projectile == &_projectiles[i] ) ){
            _tableUsedProjectile[i] = false;
            --_numProjectileUsed;
            return;
        }
    }
    throw GameCodeException("The projectile argument is not from this allocator!!");
}

ProjectileAllocator::~ProjectileAllocator(){
    
    delete [] _projectiles;
    delete [] _tableUsedProjectile;
}


