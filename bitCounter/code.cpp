#include <iostream>

int showBytes(int bits){

    if(bits <= 0 || bits > 31){
        std::cout << "Please enter a valid number\n";
        return 1;
    }

    int n = 1;
    for(int i = 0; i < bits; i++){
        std::cout << n << std::endl;
        n *= 2;
    }
    return 0;
}

int main(){

    int amount;

    std::cout << "(1 - 31) ~$ ";
    std::cin >> amount;

    int res = showBytes(amount);
    if(res==1){
        std::cout << "The program was executed with faults\n";
        return res;
    }

    std::cout << "The program was executed with no errors\n";
    return 0;
}
