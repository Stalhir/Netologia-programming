#include <iostream>
#include <numeric>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    void reduction() {
        int gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;

        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        numerator_ = numerator;
        denominator_ = denominator;
        reduction();
    }

    bool operator== (const Fraction& other) const {
        return numerator_ * other.denominator_ == other.numerator_ * denominator_;
    }

    bool operator!= (const Fraction& other) const {
        return !(*this == other);
    }

    bool operator< (const Fraction& other) const {
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    bool operator> (const Fraction& other) const {
        return other < *this;
    }

    bool operator<= (const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>= (const Fraction& other) const {
        return !(*this < other);
    }

    Fraction operator+ (const Fraction& other) const {
        int common_denominator = std::lcm(denominator_, other.denominator_);
        int new_numerator = numerator_ * (common_denominator / denominator_) +
            other.numerator_ * (common_denominator / other.denominator_);
        return Fraction(new_numerator, common_denominator);
    }

    Fraction operator- (const Fraction& other) const {
        int common_denominator = std::lcm(denominator_, other.denominator_);
        int new_numerator = numerator_ * (common_denominator / denominator_) -
            other.numerator_ * (common_denominator / other.denominator_);
        return Fraction(new_numerator, common_denominator);
    }

    Fraction operator* (const Fraction& other) const {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/ (const Fraction& other) const {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction operator- () const {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++() {
        numerator_ += denominator_;
        reduction();
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() {
        numerator_ -= denominator_;
        reduction();
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
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
	
	
    try
    {
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
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
	return 0;
}