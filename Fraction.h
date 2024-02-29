#include <iostream>
#include <cstdint>  //уточнить разрядность инт

class Fraction{
private:  //модификатор доступа. Запрещает доступ к полям
    int32_t _num;  //32 значит 32-битный
    uint32_t _denom; //поля всегда с _ и с маленкой буквы

public: //Открывает доступ к полям
    Fraction(); //объявление конструктора по умолчанию
    Fraction(int32_t num, uint32_t denom); //конструктор с параментами. переменные без _ и с маленькой буквы

    Fraction(const Fraction& fract){
        //конструктор копирования
        std::cout << "Copy constructor ->" << this << std::endl;  
        _num = fract._num;
        _denom = fract._denom;
    } 

    //чтобы было возможно множественное присваивание а1 = а2 = а3
    Fraction& operator=(const Fraction& fraction){
        _num = fraction._num;
        _denom = fraction._denom;
        return *this;
    }


    Fraction operator/(const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        uint32_t new_denom = fraction._num * _denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator*(const Fraction& fraction) const{
        int32_t new_num = _num * fraction._num;
        uint32_t new_denom = _denom * fraction._denom;
        return Fraction(new_num, new_denom);
    }

    Fraction operator-(const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        uint32_t new_denom = _denom * fraction._denom;
        return Fraction(new_num, new_denom);
    }

    //перегрузка операции сложения
    Fraction operator+(const Fraction& fraction) const {  //конст говорит о том что мы не меняет объект класса => компилятор будет быстрее
        int32_t new_num = _num * fraction._denom + fraction._num * _denom;
        uint32_t new_denum = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denum);
        return res;
    }

    //сеттеры
    void SetNum(int32_t newNum);
    void SetDenom(int32_t newDenom);

    //геттеры
    inline int32_t GetNum(){
        return _num;
    }
    inline uint32_t GetDenom(){
        return _denom;
    }

    //bool IsValid;

    // создаем метод класса, печатающий дробь
    void Print();
    inline void PrintDouble(){     //инлайн пишем тут
        std::cout << static_cast<double>(_num) / _denom << std::endl;
    }

    //перегрузка оператора вывода в консоль
    friend std::ostream& operator<<(std::ostream& os, const Fraction& tmp){   //
        os << tmp._num << "/" << tmp._denom << std::endl;
        return os;
    }

    //деструктор
    ~Fraction(){
        std::cout << "Destructor ->" << this << std::endl;
    }


};