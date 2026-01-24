// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using std::string;

void carryDigit(string& numToCarryTo, int pointerFrom, int& pointerNum);
void addTwoNumbers(std::string& num1, std::string& num2, 
int& num1Pointer, int& num2Pointer, std::string& result);

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    
    std::string num1 = "123";
    std::string num2 = "123";
    
    int pointerNum1 = num1.size() - 1;
    int pointerNum2 = num2.size() - 1;
    
    std::string result = "";
    
    addTwoNumbers(num1, num2, pointerNum1, pointerNum2, result);
    
    std::cout << result;
    
    return 0;
}

void addTwoNumbers(std::string& num1, std::string& num2, 
int& num1Pointer, int& num2Pointer, std::string& result)
{
    if (num1Pointer < 0)
    {
        return;
    }
    
    if (num2Pointer < 0)
    {
        for (int i = num1Pointer; i >= 0; i--)
        {
            result = num1[i] + result;
        }
        
        return;
    }
    
    int resultNr = (num1[num1Pointer] - '0') + num2[num2Pointer] - '0';
    
    if (resultNr < 10)
    {
        result = (char(resultNr + '0')) + result; 
    }
    else 
    {
        result = char((resultNr - 10) + '0') + result;
        carryDigit(num1, num1Pointer, num1Pointer);
    }
    
    num1Pointer--;
    num2Pointer--;
    
    addTwoNumbers(num1, num2, num1Pointer, num2Pointer, result);
}
void carryDigit(string& numToCarryTo, int pointerFrom, int& pointerNum)
{
    if (pointerFrom < 0)
    {
        numToCarryTo = char(1 + '0') + numToCarryTo;
        
        pointerNum++;
        
        return;
    }

    if (int(numToCarryTo[pointerFrom] - '0') + 1 < 10)
    {
        numToCarryTo[pointerFrom] = char( (int(numToCarryTo[pointerFrom] -'0') + 1) + '0');

        return;
    }

    numToCarryTo[pointerFrom] = '0';
    
    pointerFrom = pointerFrom - 1;

    carryDigit(numToCarryTo, pointerFrom, pointerNum);
}





