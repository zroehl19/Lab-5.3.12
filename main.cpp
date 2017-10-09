/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zroehl
 *
 * Created on October 5, 2017, 1:53 PM
 */

#include <iostream>

using namespace std;

double num;

class FarmAnimal{
public:
    FarmAnimal(double water_consumption);
    double getWaterConsumption();
    
private:
    double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption)
{
    this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption()
{
    return water_consumption;
}

class ConsumptionAccumulator
{
public:
    ConsumptionAccumulator();
    double getTotalConsumption();
    void addConsumption(FarmAnimal animal);
private:
    double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() : total_consumption(0)
{
    
}

double ConsumptionAccumulator::getTotalConsumption()
{
    return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
    total_consumption += animal.getWaterConsumption();
}

void Cow()
{
    num = (num/100)*8.6;
}

void Horse()
{
    num = (num/100)*6.8;
}

void Sheep()
{
    num = (num/10)*1.1;
}

int main()
{
    ConsumptionAccumulator accumulator;
    string input;
   
    do{
       getline(cin, input);
       
       if(1== sscanf(input.c_str(),"cow %lf",&num))
       {
           Cow();
           accumulator.addConsumption(num);
       }
       else if(1== sscanf(input.c_str(),"horse %lf",&num))
       {
           Horse();
           accumulator.addConsumption(num);
       }
       else if(1== sscanf(input.c_str(),"sheep %lf",&num))
       {
           Sheep();
           accumulator.addConsumption(num);
       }
    }
    while(input != "");
    
    cout << accumulator.getTotalConsumption();
}

