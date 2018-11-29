#include "Rod.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main() {
   
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    Rod rod(price);
    rod.extBottomUpCut();
    rod.printCut();
    return 0;
}