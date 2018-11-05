#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include "Trem.h"

using namespace std;

int main(){
    int id;
    while(1){
        cout << "Digite a quatidade de vagoes:" << endl;
        cin >> id;
        Trem trem(id);
    }

}
