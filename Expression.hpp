//
// Created by r_ten on 10.02.2020.
//
#ifndef INPUTS
#define INPUTS
#include <cstring>
#include <iostream>
#include "funcs.hpp"
#endif
#ifndef EXPRESSIONS
#define EXPRESSIONS
using namespace std;
int number_of_number = 0;
class Number{
private:
    int numb;
public:
    Number(){
        numb = 0;
        number_of_number += 1;
    }
    ~Number(){
        cout << "Element of Number class type N" << number_of_number << " with value " << numb << " was destroyed" << endl;
        number_of_number --;
    }
    void set(int numb1){
        numb = numb1;
    }
    int get(){
        return numb;
    }
};


int number_of_float = 0;
class Float{
private:
    double drob;
public:
    Float(){
        drob = 0.0;
        number_of_float += 1;
    }
    ~Float(){
        cout << "Element of Float class type N" << number_of_float << " with value "<< drob << " was destroyed" << endl;
        number_of_float--;
    }
    void set(double drob1){
        drob = drob1;
    }
    double get(){
        return drob;
    }
};

int number_of_operat = 0;
class Operator{
private:
    char oper;
    int prior;
public:
    Operator(){
        oper = 'X';
        prior = 0;
        number_of_operat += 1;
    }
    ~Operator(){
        cout << "Element of Operator class type N" << number_of_operat << " with value of  " << oper << " was destroyed" << endl;
        number_of_operat--;
    }
    void set(char oper1){
        oper = oper1;
        prior = calc_prior(oper);
    }
    char get(){
        return oper;
    }
    int get_prior(){
        return prior;
    }

};

int number_of_expression = 0;
class Expression{
private:
    int isNumber; // 0 - nothing, -1 - operator, 1 - number, 2 - float
    Operator operat;
    Number number;
    Float drobnoe;
public:
    Expression(){
        isNumber = 0;
        number_of_expression += 1;
    }
    ~Expression(){
        cout << "Element of Expression class type N" << number_of_expression << " with value of " << isNumber << " was destroyed" << endl;
        number_of_expression--;
    }
    void set(Operator operat1){
        operat = operat1;
        isNumber = -1;
    }
    void set(Number number1){
        number = number1;
        isNumber = 1;
    }
    void set(Float drobnoe1){
        drobnoe = drobnoe1;
        isNumber = 2;
    }
    void set_in(char operation){
        operat.set(operation);
        isNumber = -1;
    }
    void set_in(int numberior){
        number.set(numberior);
        isNumber = 1;
    }
    void set_in(double drobition){
        drobnoe.set(drobition);
        isNumber = 2;
    }
    int get(){
        if (isNumber == 1){
            return number.get();
        }
    }
    double get_float(){
        if (isNumber == 2){
            return drobnoe.get();
        }
        else {
            cout << "CODE 1 ERROR: check func get_float in class Expression because of isNumber != -2 and used this func" << endl;
            cout << "it's   " << drobnoe.get();
            exit(0);
        }
    }
    char get_operator(){
        if (isNumber == -1){
            return operat.get();
        }
        else{
            cout << "CODE 1 ERROR: check func get_operator() in class Expression because of isNumber != -1 and used this func" << endl;
            exit(0);
        }
    }
    int get_prior(){
        if (isNumber == -1){
            return operat.get_prior();
        }
        else{
            cout << "CODE 1 ERROR: check func get_prior() in class Expression because of isNumber != -1 and used this func" << endl;
            exit(0);
        }
    }
    int get_check(){
        return isNumber;
    }
};


class Stack{
private:
    int count_of_stack;
    char *stacks;
public:
    Stack(int hm=500){
        stacks = new char[hm];
        count_of_stack = 0;
    }
    void set(char smthng){
        stacks[count_of_stack] = smthng;
        count_of_stack += 1;
    }
    int get_length(){
        return count_of_stack;
    }
    char get_last(){
        return stacks[count_of_stack - 1];
    }
    void del_last(){
        count_of_stack -= 1;
        stacks[count_of_stack] = '\0';
    }
    char pop(){
        char cop = get_last();
        del_last();
        return cop;
    }
};


#endif
