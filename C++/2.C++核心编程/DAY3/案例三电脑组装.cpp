#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void calculate() = 0;
};
// CPU::~CPU(){
    
// }

class VideoCard
{
public:
    virtual void display() = 0;
};
// VideoCard::~VideoCard(){

// }

class RAM
{
public:
    virtual void memery() = 0;
};
// RAM::~RAM(){

// }

class IntelCPU :public CPU
{
public:
    virtual void calculate(){
        cout << "IntelCPU开始计算" << endl;
    }
};

class IntelVidelCard :public VideoCard
{
public:
    virtual void display(){
        cout << "Intel显卡开始工作" << endl;
    }

};

class IntelRAM :public RAM
{
public:
    virtual void memery(){
        cout << "Intel内存开始读写" << endl;
    }

};

class LenovoCPU :public CPU
{
public:
    virtual void calculate(){
        cout << "LenovoCPU开始计算" << endl;
    }
};

class LenovoVideoCard :public VideoCard
{
public:
    virtual void display(){
        cout << "Lenovo显卡开始工作" << endl;
    }

};

class LenovoRAM :public RAM
{
public:
    virtual void memery(){
        cout << "Lenovo内存开始读写" << endl;
    }

};

class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vd, RAM *ram){
        m_Cpu = cpu;
        m_Vd = vd;
        m_Ram = ram;
    }
    void doWork(){
        m_Cpu->calculate();
        m_Vd->display();
        m_Ram->memery();
    }
    ~Computer()
    {
        if(!m_Cpu)
            delete m_Cpu;
        if(!m_Vd)
            delete m_Vd;
        if(!m_Ram)
            delete m_Ram;
    }

private:
    CPU *m_Cpu;
    VideoCard *m_Vd;
    RAM *m_Ram;
};

void test01()
{
    CPU *intelCPU = new IntelCPU;
    VideoCard *intelViderlCard = new IntelVidelCard;
    RAM *intelRAM = new IntelRAM;

    cout << "第一台计算机开始工作" << endl;
    Computer *computer1 = new Computer(intelCPU, intelViderlCard, intelRAM);
    computer1->doWork();
    delete computer1;

    cout << "_________________" << endl;
    cout << "第二台计算机开始工作" << endl;
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoRAM);
    computer2->doWork();
    delete computer2;

    cout << "_________________" << endl;
    cout << "第三台计算机开始工作" << endl;
    Computer *computer3 = new Computer(new LenovoCPU, new IntelVidelCard, new LenovoRAM);
    computer3->doWork();
    delete computer3;
}



int main()
{

    test01();
    return 0;
}