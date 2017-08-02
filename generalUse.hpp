//
//  generalUse.hpp
//  googlement
//
//  Created by Colleen Minor on 8/1/17.
//  Copyright © 2017 Colleen Minor. All rights reserved.
//

#ifndef generalUse_hpp
    #define generalUse_hpp
    #include <vector>
    #include <iostream>

    std::vector<int> intToVector(int num);
    int getNumDigitsInInt(int num);
    std::vector< std::vector<int> > getVectorOfPerms(std::vector<int>);
    std::vector< std::vector<int> > getUniqueVectors(std::vector< std::vector<int> > inVec);
    std::string vectorToString(std::vector<int> v);
    int vectorToInt(std::vector<int> v);
    std::vector<int> addLeadingZeroes(std::vector<int> numberAsVector, std::string numString);

#endif /* generalUse_hpp */


