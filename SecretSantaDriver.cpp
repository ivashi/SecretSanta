//
//  Simple Secret Santa Program
//  project4
//
//  Created by Ishan Vashishta on 12/2/16.
//  Copyright © 2016 Ishan Vashishta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

struct SecretSanta{
    std::string name;
    bool isGiving;
    bool isReceiving;
    std::string givingTo;
};


int main(int argc, const char * argv[]) {
    
    //num ppl
    int numPpl;
    std::cout << "enter how many ppl: ";
    std::cin >> numPpl;
    std::vector<SecretSanta> Directory;
    
    //enter in all the data
    for(int i = 0; i < numPpl; i++){
        SecretSanta person;
        std::string nam;
        std::cout << "name: ";
        std::cin >> nam;
        person.name = nam;
        person.isGiving = false;
        person.isReceiving = false;
        Directory.push_back(person);
    }
    
    //match eveyone
    for(int i = 0; i < numPpl; i++){
        bool matched = false;
        Directory[i].isGiving = true;
        while(!matched){
            int match = rand() % numPpl;
            if(!Directory[match].isReceiving & (match != i)){
                Directory[i].givingTo = Directory[match].name;
                Directory[match].isReceiving = true;
                matched = true;
            }
        }
    }
    for(int i  = 0; i < numPpl; i++){
        
        
        std::cout << Directory[i].name << " has " <<
                    Directory[i].givingTo << "\n";
        
    }
    
  
    //PRINT THE OUTPUT
    for(int i = 0; i < numPpl; i++){
        std::cout << "call over *"  << Directory[i].name << "* type anything and "<<
                     " hit enter when you are here\n";
        std::string junk;
        std::cin >> junk;
        std::cout << Directory[i].name << " you are gifting " << Directory[i].givingTo;
        std::cout << "\ntype anything when you have written this down\n";
        std::cin >> junk;
        for(int j = 0; j < 100; j++){
            std::cout << "\n";
        }
    }

    std::cout << "\n HAVE FUN !!!!!!!!!!\n";
    return 0;
}
