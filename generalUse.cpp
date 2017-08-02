//
//  generalUse.cpp
//  googlement
//
//  Created by Colleen Minor on 8/1/17.
//  Copyright © 2017 Colleen Minor. All rights reserved.
//

#include "generalUse.hpp"

std::string vectorToString(std::vector<int> v){
    std::string out_string = "";
    for(int i = 0; i < v.size(); i++){
        out_string += std::to_string(v[i]);
    }
    return out_string;
}



std::vector<int> intToVector(int num){
    int i;
    int numDigits = getNumDigitsInInt(num);
    std::vector<int> digitsVec;
    for (i = numDigits; i >= 1; i--) {
        digitsVec.push_back(num % 10);
        num /= 10;
    }
    std::reverse(digitsVec.begin(), digitsVec.end());
    return digitsVec;
}



int getNumDigitsInInt(int n){
    unsigned int number_of_digits = 0;
    
    do {
        ++number_of_digits;
        n /= 10;
    } while (n);
    
    return number_of_digits;
}



std::vector< std::vector<int> > getVectorOfPerms(std::vector<int> v){
    std::vector< std::vector<int> > outVector;
    for(int i=1;i<=v.size();++i)
        do{
            outVector.push_back(v);
        }    while(std::next_permutation(v.begin(),v.end()));
    outVector = getUniqueVectors(outVector);
    return outVector;
}



std::vector< std::vector<int> > getUniqueVectors(std::vector< std::vector<int> > inVec){
    sort( inVec.begin(), inVec.end() );
    inVec.erase( unique( inVec.begin(), inVec.end() ), inVec.end() );
    return inVec;
}



int vectorToInt(std::vector<int> v){
    int result = 0;
    for (auto d : v)
    {
        result = result * 10 + d;
    }
    return result;
}



std::vector<int> addLeadingZeroes(std::vector<int> numberAsVector, std::string numString){
    int leadingZeroes = numString.length() - numberAsVector.size();
    std::reverse(numberAsVector.begin(), numberAsVector.end());
    for(int i = 0; i < leadingZeroes; i++){
        numberAsVector.push_back(0);
    }
    std::reverse(numberAsVector.begin(), numberAsVector.end());
    return numberAsVector;
}
