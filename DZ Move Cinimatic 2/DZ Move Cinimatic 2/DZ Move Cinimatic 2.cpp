#include <iostream>
#include <vector>
#include <cctype>
class big_integer
{
public:
    big_integer()
    {
        //std::cout << "Class has constructed" << std::endl;
    }

    big_integer(std::string Nubmer) : textnumber(Nubmer)
    {
        initialization();
        //std::cout << "Class has constructed" << std::endl;
    }
    
    void printNumber()
    {
        for(int i = 0; i < number.size(); i++)
        {
            std::cout << number[i];
        }
        std::cout << std::endl  << "Size: " << number.size() << std::endl;
    }

    big_integer(const big_integer& other)
        : textnumber(other.textnumber), number(other.number) {
    }



    big_integer(big_integer&& other) noexcept
        : number(std::move(other.number)), textnumber(std::move(other.textnumber)) {
    }  

    big_integer& operator=(const big_integer& other) {
        if (this != &other) {  
            this->textnumber = other.textnumber;  
            this->number = other.number;         
        }
        return *this;
    }

    big_integer& operator=(big_integer&& other) noexcept
    {
        if (this != &other) {
            this->textnumber = std::move(other.textnumber);
            this->number = std::move(other.number);
        }
        return *this;
    }

    


    big_integer operator+ (const big_integer& other)
    {
       bool flagToAdd{false};
       big_integer result{};

       std::vector<int> numF = this->number;
       std::vector<int> numT = other.number;
       
       int maxLen = std::max(numF.size(), numT.size());
       
           
               

       while (numF.size() < maxLen) { numF.insert(numF.begin(), 0); }
       while (numT.size() < maxLen) { numT.insert(numT.begin(), 0); }
      
       int temp{};

       for (int i = maxLen - 1; i >= 0; i--)
       {
          
           temp = numF[i] + numT[i];
           
           if (flagToAdd == true) { temp++; flagToAdd = false; }
           if(temp >= 10)
           {
               flagToAdd = true;
               temp = temp - 10;
           }
           
           result.number.push_back(temp);
          
           temp = 0;

       } 
       if (flagToAdd == true) { temp++; result.number.push_back(temp); }
       std::reverse(result.number.begin(), result.number.end());
       return result;
    }

    big_integer operator* (const int mnoz)
    {
      
        big_integer result;
        for(int i = 0; i < mnoz; i++)
        {
            result = result + *this;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, big_integer j);


    ~big_integer()
    {
        number.clear();
        textnumber.clear();
        //std::cout << "Class has deleted" << std::endl;
    }


private:
    big_integer functionToAidMult(big_integer Number, int countadd)
    {
     if(countadd > 1)
     {
         return functionToAidMult(Number+Number, countadd - 1);
     }
     else
     {
         return Number;
     }
       
    }
    void initialization()
    {

        number.reserve(textnumber.size());
        for (char c : textnumber)
        {
            if (!std::isdigit(c))
                throw std::invalid_argument("Invalid argument. The argument must be a number.");

            number.push_back(c - '0');
        }
    
    }
    std::string textnumber{};
    std::vector<int> number{};
    
};

std::ostream& operator<<(std::ostream& out, big_integer j) {
    std::string temp{};
    for(int i = 0; i<j.number.size(); i++)
    out << j.number[i];
    return out;
}

int main()
{
    auto number1 = big_integer("1922314136412321312343242432223424454136472346832132331284368484874884881332124324874567898765434567898765434567654334567654323456");
    auto number2 = big_integer("7324167286712321321321323456789023448634311869631231254321763756756863565846385678900987654323456789098765434567898765434567898765");
    
 

    auto result = number1 + number2;
    std::cout << result; // 193099
}
