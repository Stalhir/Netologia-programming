#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:

	bool operator== (Fraction& other) {
		return numerator_ * other.denominator_ == other.numerator_ * denominator_;
	}

	bool operator!= (Fraction& other) {
		return !(*this == other);
	}

	bool operator< (Fraction& other) {
		return numerator_ * other.denominator_ < other.numerator_ * denominator_;
	}

	bool operator> (Fraction& other) {
		return other < *this;
	}

	bool operator<= (Fraction& other) {
		return !(other < *this);
	}

	bool operator>= (Fraction& other) {
		return !(*this < other);
	}

	Fraction operator+ (Fraction& other) {
		return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
	}

	Fraction operator- (Fraction& other) {
		return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
	}

	Fraction operator* (Fraction& other) {
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
	}

	Fraction operator/ (Fraction& other) {
		return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
	}

	Fraction operator- () {
		return Fraction(-numerator_, denominator_);
	}

	Fraction& operator++() { 
		numerator_ += denominator_;
		return *this;
	}

	Fraction operator++(int) { 
		Fraction temp = *this; 
		++(*this); 
		return temp; 
	}

	Fraction& operator--() { 
		numerator_ -= denominator_;
		return *this;
	}

	Fraction operator--(int) { 
		Fraction temp = *this; 
		--(*this); 
		return temp; 
	}


	Fraction(int numerator, int denominator)
	{
		try {
			if (denominator == 0)
			{
				throw std::invalid_argument("");
			}
			numerator_ = numerator;
			denominator_ = denominator;
		}
		catch (std::invalid_argument)
		{
			numerator_ = 1;
			denominator_ = 1;
			std::cout << "Denominator cannot be zero.";
		}
	}

	friend std::ostream& operator<< (std::ostream& os, const Fraction& f) { 
		os << f.numerator_ << '/' << f.denominator_; 
		return os; 
	}

};

int main()
{
	setlocale(LC_ALL, "rus");

	int num1{}, num2{};

	std::cout << "Введите числитель дроби 1: " << std::endl;
	std::cin >> num1;
	std::cout << "Введите знаменатель дроби 1: " << std::endl; 
	std::cin >> num2; 
	Fraction f1(num1, num2); 

	std::cout << "Введите числитель дроби 2: " << std::endl; 
	std::cin >> num1;
	std::cout << "Введите знаменатель дроби 2: " << std::endl;
	std::cin >> num2;
	Fraction f2(num1, num2);  

	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
	std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl; 
	std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;

	std::cout << "++" << f1 << " * " << f2 << " = " << ((++f1) * f2) << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl; 

	std::cout << f1 << "--" << " * " << f2 << " = " << (f1-- * f2) << std::endl;
	std::cout << "Значение дроби 1 = " << f1 << std::endl;

	return 0;
}