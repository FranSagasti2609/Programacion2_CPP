#include <iostream>
#include <vector>

int main(){

    std::vector <int> nums = {10,20,30,40,50,60,70};

    for(int i=0; i < nums.size(); i++){
        std::cout << "Indice " << i << " es " << nums.at(i) << std::endl;
    }
    std::cout << nums.size() <<std::endl;
    
    //std::cout << "Indice 0 " << nums.begin() <<std::endl;
    std::cout << "Indice 7 " << nums.back() <<std::endl;
        return 0;
    
}