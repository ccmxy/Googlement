//
//  Googlement.cpp
//  googlement
//
//  Created by Colleen Minor on 8/2/17.
//  Copyright © 2017 Colleen Minor. All rights reserved.
//

#include "Googlement.hpp"
#include "generalUse.hpp"
#include <stdio.h>

static int derivCount;

Googlement::Googlement(){
    derivCount = 1;
}

Googlement::Googlement(std::string numString){
    
    int_vec numberAsVector = intToVector(atoi(numString.c_str()));
    
    if (numberAsVector[0] == 1){
        if (numberAsVector.size() == 1) {
            return;
        }
        std::reverse(numberAsVector.begin(), numberAsVector.end());
    }
    
    if (vectorToInt(numberAsVector) == 0){
        return;
    }
    
    numberAsVector = addLeadingZeroes(numberAsVector, numString);
    int_vec firstDecayedNum = Googlement::getFirstDecayedNum(atoi(numString.c_str()), numberAsVector);
    
    if(firstDecayedNum[0] != -1){
        
        decayedNums = getUniqueVectors(getVectorOfPerms(firstDecayedNum));
        
        for (double_int_vec::const_iterator i = decayedNums.begin(); i != decayedNums.end(); ++i){
            derivCount++;    //Increment derivs
        }
        //        this->printDecays();
        setDecays();
    }
}

Googlement::~Googlement(){
    numberAsVector.clear();
    decayedNums.clear();
}


int Googlement::getDerivCount(){
    if(!derivCount){
        derivCount = 0;
    }
    return derivCount;
}

void Googlement::printDecays(){
    int_vec numVector;
    for (double_int_vec::const_iterator i = decayedNums.begin(); i != decayedNums.end(); ++i){
        std::cout << '\n' << derivCount << " ";
        numVector = *i;
        for (int_vec::const_iterator i = numVector.begin(); i != numVector.end(); ++i){
            std::cout << *i << ' ';
        }
    }
}

void Googlement::setDecays(){
    int_vec permutationVector;
    for (double_int_vec::const_iterator i = decayedNums.begin(); i != decayedNums.end(); ++i){
        permutationVector = *i;
        if (permutationVector != numberAsVector){
            Googlement node = Googlement(vectorToString(permutationVector));
        }
    }
}

int_vec Googlement::getFirstDecayedNum(int num, int_vec v){
    int_vec newVec;
    int numCount;
    for(int_vec::size_type i = 0; i != v.size(); i++) { //is this right
        numCount = v[i];
        for(int j=0; j<numCount; j++){
            newVec.push_back(i+1);
        }
    }
    
    while(newVec.size() < v.size()){
        newVec.push_back(0);
    }
    
    if(newVec.size() == v.size() ){
        return newVec;
    }
    else{
        int_vec failVector = {-1};
        return failVector;
    }
}
