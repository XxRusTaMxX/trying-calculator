


#ifndef FUNCS
#define FUNCS



#ifndef INPUTS
#define INPUTS
#include <iostream>
#include <cstring>
#include <cmath>
#include "funcs.hpp"
#endif
using namespace std;

int calc_prior(char oper){
    int prior = 0;
    if (oper == '^'){
        prior = 3;
    }
    else if (oper == '*' or oper == '/' or oper == '%'){
        prior = 2;
    }
    else if (oper == '+' or oper == '-'){
        prior = 1;
    }
    else if (oper == '(' or oper == ')'){
        prior = -1;
    }
    else{
        std::cout << "CODE 2 ERROR: check func calc_prior() because of given variable oper can't be a standart operation" << std::endl << "found:   " << oper << endl;
        exit(0);
    }
    return prior;
}



char* copy(char to[], char from[]){
    int len_to = strlen(to);
//     cout << "strlen to " << len_to << endl;
    int len_from = strlen(from);
    if (len_from == 0){
        std::cout << "CODE 2 ERROR: check func copy() because of given massive's from[] lenght is 0" << std::endl;
    }
    // cout << "strlen from " << len_from << endl;
    for (int count = 0; count <= len_from; count++){
        //cout << "from:  " << from[count] << endl;
        //cout << "to:    " << to[len_to + count] << endl;
        //cout << "at:    " << count << endl;
        to[len_to + count] = from[count];
        //cout << "res:   " << to[len_to + count] << endl;
    }
    return to;
}




#endif