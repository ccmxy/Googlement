//
//  Googlement.hpp
//  googlement
//
//  Created by Colleen Minor on 8/2/17.
//  Copyright © 2017 Colleen Minor. All rights reserved.
//

#ifndef Googlement_hpp
#define Googlement_hpp
#include <vector>
typedef std::vector<int> int_vec;
typedef std::vector< std::vector<int> > double_int_vec;


class Googlement {
    
    private:
        int_vec getFirstDecayedNum(int num, std::vector<int> v);
        int_vec numberAsVector;
        double_int_vec decayedNums;
    
        void setDecays();
        void printDecays();
    
    public:
        Googlement(std::string numString); //Constructor
        Googlement();
        ~Googlement();
        int getDerivCount();
};

#endif /* Googlement_hpp */
