#include <iostream>

using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int n) : gasolineGauge(n)
    {
        cout << "Car() : " << gasolineGauge << endl;
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int m, int n) : Car(m), electricGauge(n)
    {
        cout << "HybridCar() : " << electricGauge << endl;
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int m, int n, int q) : HybridCar(m,n), waterGauge(q)
    {
        cout << "HybridWaterCar() : " << waterGauge << endl;
    }
    void ShowCurrentGauge()
    {
        cout << "ÀÜ¿© °¡¼Ö¸° : " << GetGasGauge() << endl;
        cout << "ÀÜ¿© Àü±â·® : " << GetElecGauge() << endl;
        cout << "ÀÜ¿© ¿öÅÍ·® : " << waterGauge << endl;
    }
};

int main(void)
{
    HybridWaterCar hwc1(10,20,30);
    hwc1.ShowCurrentGauge();
}
