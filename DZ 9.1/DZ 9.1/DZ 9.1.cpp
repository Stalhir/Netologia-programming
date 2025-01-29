#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:

	bool operator== (Fraction& other)  {
		return numerator_ * other.denominator_ == other.numerator_ * denominator_;
	}
	
	bool operator!= (Fraction& other) {
		return !(*this == other);
	}

	bool operator< ( Fraction& other)  {
		return numerator_ * other.denominator_ < other.numerator_ * denominator_;
	}

	bool operator> ( Fraction& other)  {
		return other < *this; 
	}

	bool operator<= ( Fraction& other)  {
		return !(other < *this); 
	}

	bool operator>= ( Fraction& other)  {
		return !(*this < other); 
	}

	Fraction(int numerator, int denominator)
	{
		try{ 
		if (denominator == 0) 
		{
			throw std::invalid_argument("");
		}
		numerator_ = numerator;
		denominator_ = denominator;
		}
		catch(std::invalid_argument)
		{
			numerator_ = 0; 
			denominator_ = 0; 
			std::cout << "Denominator cannot be zero."; 
		}
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);
	
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
	
}