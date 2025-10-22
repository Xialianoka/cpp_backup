#include <iostream>
using namespace std;

class AbstractCalculator
{
public:
    virtual int getResult(){
        return 0;
    }
    
    int num1;
    int num2;

};

class AddCalculator :public AbstractCalculator
{
    int getResult(){
        return num1 + num2;
    }
};

class SubCalculator :public AbstractCalculator
{
    int getResult(){
        return num1 - num2;
    }
};


class MulCalculator :public AbstractCalculator
{
    int getResult(){
        return num1 * num2;
    }
};

void test01(){

    AbstractCalculator *abc = new AddCalculator;
    abc->num1 = 10;
    abc->num2 = 10;
    cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
    delete abc;

    abc = new SubCalculator;
    abc->num1 = 10;
    abc->num2 = 10;
    cout << abc->num1 << " - " << abc->num2 << " = " << abc->getResult() << endl;
    delete abc;

    abc = new MulCalculator;
    abc->num1 = 10;
    abc->num2 = 10;
    cout << abc->num1 << " * " << abc->num2 << " = " << abc->getResult() << endl;
    delete abc;
}


int main()
{

    test01();
    return 0;

}