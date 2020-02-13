#ifndef INPUTS
#define INPUTS
#include <iostream>
#include <cstring>
#include <cmath>
#include "funcs.hpp"
#include "Expression.hpp"
using namespace std;
#endif


int main(int argscount, char** arguments) {
    int length_of_all_arguments = 0;
    for (int count = 1; count < argscount; count++){
        length_of_all_arguments += strlen(arguments[count]);
    }
    cout << "len:   " << length_of_all_arguments << endl;
    char *all_args = new char[length_of_all_arguments];
    memset(all_args, 0, sizeof(all_args)/sizeof(all_args[0]));
    for (int count = 1; count < argscount; count++){
//        cout << arguments[count] << endl;
        copy(all_args, arguments[count]);
//        cout << "args:  "<< all_args << endl;
    }
    cout << all_args << endl;

    Expression *FirstExpression = new Expression[length_of_all_arguments];
    int FirstExpressionCount = 0;

    char *number = new char[length_of_all_arguments];
    memset(number, 0, sizeof(number)/sizeof(number[0]));
    int numbercount = 0;

    char *floating = new char[length_of_all_arguments];
    memset(floating, 0, sizeof(floating)/ sizeof(floating[0]));
    int floating_count = 0;
    int last_oper = 0;
    int next_closed = 0;
    for (int i = 0; i < length_of_all_arguments; i++){
        if (all_args[i] == '('){
            FirstExpression[FirstExpressionCount].set_in(all_args[i]);
            FirstExpressionCount += 1;
        }
        else if (all_args[i] == ')' and all_args[i + 1] != '\0') {
            if (isdigit(all_args[i + 1])) {
                FirstExpression[FirstExpressionCount].set_in(all_args[i]);
                FirstExpressionCount += 1;
            }
            else{
                next_closed = 1;
                int copy_i = i - 1;
                int found_dot = 0; // 0 - not found, 1 - found
                int is_null = 0; // 0 - not null, 1 - null
                while (1){
                    cout << "IT'S " << all_args[copy_i] << " at " << copy_i << endl;
                    if (all_args[copy_i] == '.'){
                        found_dot = 1;
                    }
                    if (copy_i == 0){
                        is_null = 1;
                        break;
                    }
                    if (!isdigit(all_args[copy_i]) and all_args[copy_i] != '.' and all_args[copy_i] != '(' and all_args[copy_i] != ')'){
                        is_null = 0;
                        break;
                    }
                    copy_i--;
                }
                cout << "is_null:   " << is_null << endl << "found_dot:     " << found_dot << endl;
                if (found_dot == 1){
                    for (int j = copy_i; j <= i; j++){
                        cout << floating << " at " << j << endl << "in " << all_args[j] << endl;
                        if (isdigit(all_args[j]) or all_args[j] == '.') {
                            floating[floating_count] = all_args[j];
                            floating_count += 1;
                        }
                    }
                    FirstExpression[FirstExpressionCount].set_in(atof(floating));
                    cout << "Writed float:      "<< FirstExpression[FirstExpressionCount].get_float() << endl;
                    FirstExpressionCount += 1;
                    memset(floating, 0, sizeof(floating)/sizeof(floating[0]));
                    floating_count = 0;
                }
                else if (found_dot == 0){
                    for (int j = copy_i; j <= i; j++){
                        cout << number << endl;
                        if (isdigit(all_args[j])) {
                            number[numbercount] = all_args[j];
                            numbercount += 1;
                        }
                    }
                    FirstExpression[FirstExpressionCount].set_in(atoi(number));
                    cout << "Writed int:        " << FirstExpression[FirstExpressionCount].get() << endl;
                    FirstExpressionCount += 1;
                    memset(number, 0, sizeof(number)/sizeof(number[0]));
                    numbercount = 0;
                }
                FirstExpression[FirstExpressionCount].set_in(all_args[i]);
                FirstExpressionCount += 1;
                FirstExpression[FirstExpressionCount].set_in(all_args[i+1]);
                FirstExpressionCount += 1;
            }
        }
        else if (!isdigit(all_args[i]) and all_args[i] != '.'){
            cout << "Now " << all_args[i] << " at point " << i << endl;
            if (next_closed == 1){
                next_closed = 0;
                continue;
            }
            last_oper = i;
            int copy_i = i - 1;
            int found_dot = 0; // 0 - not found, 1 - found
            int is_null = 0; // 0 - not null, 1 - null
            while (1){
                cout << "IT'S " << all_args[copy_i] << " at " << copy_i << endl;
                if (all_args[copy_i] == '.'){
                    found_dot = 1;
                }
                if (copy_i == 0){
                    is_null = 1;
                    break;
                }
                if (!isdigit(all_args[copy_i]) and all_args[copy_i] != '.' and all_args[copy_i] != '(' and all_args[copy_i] != ')'){
                    is_null = 0;
                    break;
                }
                copy_i--;
            }
            cout << "is_null:   " << is_null << endl << "found_dot:     " << found_dot << endl;
            if (found_dot == 1){
                for (int j = copy_i; j <= i; j++){
                    cout << floating << " at " << j << endl << "in " << all_args[j] << endl;
                    if (isdigit(all_args[j]) or all_args[j] == '.') {
                        floating[floating_count] = all_args[j];
                        floating_count += 1;
                    }
                }
                FirstExpression[FirstExpressionCount].set_in(atof(floating));
                cout << "Writed float:      "<< FirstExpression[FirstExpressionCount].get_float() << endl;
                FirstExpressionCount += 1;
                memset(floating, 0, sizeof(floating)/sizeof(floating[0]));
                floating_count = 0;
            }
            else if (found_dot == 0){
                for (int j = copy_i; j <= i; j++){
                    cout << number << endl;
                    if (isdigit(all_args[j])) {
                        number[numbercount] = all_args[j];
                        numbercount += 1;
                    }
                }
                FirstExpression[FirstExpressionCount].set_in(atoi(number));
                cout << "Writed int:        " << FirstExpression[FirstExpressionCount].get() << endl;
                FirstExpressionCount += 1;
                memset(number, 0, sizeof(number)/sizeof(number[0]));
                numbercount = 0;

            }
            FirstExpression[FirstExpressionCount].set_in(all_args[i]);
            cout << "Writed char:       " << FirstExpression[FirstExpressionCount].get_operator() << endl;
            FirstExpressionCount += 1;


        }
    }
    if (all_args[length_of_all_arguments - 1] != ')') {
        int copy_i = length_of_all_arguments - 1;
        int found_dot = 0; // 0 - not found, 1 - found
        while (1) {
            cout << copy_i << " is " << all_args[copy_i] << endl;
            if (all_args[copy_i] == '.') {
                found_dot = 1;
            }
            if (!isdigit(all_args[copy_i]) and all_args[copy_i] != '.' and all_args[copy_i] != ')' and
                all_args[copy_i] != '(') {
                break;
            }
            copy_i--;
        }
        if (found_dot == 1) {
            for (int j = last_oper; j < length_of_all_arguments; j++) {
                cout << floating << " at " << j << endl << "in " << all_args[j] << endl;
                if (isdigit(all_args[j]) or all_args[j] == '.') {
                    floating[floating_count] = all_args[j];
                    floating_count += 1;
                }
            }
            FirstExpression[FirstExpressionCount].set_in(atof(floating));
            cout << "Writed float:      " << FirstExpression[FirstExpressionCount].get_float() << endl;
            FirstExpressionCount += 1;
        } else {
            for (int j = copy_i; j < length_of_all_arguments; j++) {
                cout << number << endl;
                if (isdigit(all_args[j])) {
                    number[numbercount] = all_args[j];
                    numbercount += 1;
                }
            }
            FirstExpression[FirstExpressionCount].set_in(atoi(number));
            cout << "Writed int:        " << FirstExpression[FirstExpressionCount].get() << endl;
            FirstExpressionCount += 1;
        }
    }
    cout << endl;
    for (int i = 0; i <= FirstExpressionCount; i++){
        if (FirstExpression[i].get_check() == -1){
            cout << FirstExpression[i].get_operator() << " , ";
        }
        else if (FirstExpression[i].get_check() == 1){
            cout << FirstExpression[i].get() << " , ";
         }
        else if (FirstExpression[i].get_check() == 2){
            cout  << FirstExpression[i].get_float() << " , ";
        }
    }
    cout << endl;
























    delete[](FirstExpression);
    delete[](number);
    delete[](floating);
    delete[](all_args);
    return 0;
}