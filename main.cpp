#include <iostream>
#include "Fraction.h"

int main(){

    Fraction fract = Fraction(1, 2);
    std::cout << fract;  // Вместо функции принт

    Fraction fract_copy = Fraction(fract);  
    std::cout << fract_copy;

    Fraction result = fract + fract_copy;
    std::cout << result;

    
    //создаем объект нашего класса
    //Fraction fract1; //1 вариант создания

    //fract1.SetNum(1);
    //fract1.SetDenom(1);
    //fract1.PrintDouble();

    
    Fraction* MassivFraction = new Fraction[5];
    delete [] MassivFraction;
    
    Fraction*  pointerFract = new Fraction(); //создание в куче
    delete pointerFract;  //т.к. деструктор не работает

}