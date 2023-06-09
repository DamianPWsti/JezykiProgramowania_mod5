#include <iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

enum skala
{
    UNDERWEIGHT = 185,
    NORMAL = 249,
    OVERWEIGHT = 299,
    OBESE = 349,
    EXTREMLY_OBESE= 65000
};

struct date
{
    int masa;
    int wzrost;
    float bmi;
    skala nadwaga;
};

string getSkalaString(skala value)
{
    switch(value)
    {
        case UNDERWEIGHT:
        return "Niedowaga";
        case NORMAL:
        return "Normalna";
        case OVERWEIGHT:
        return "nadwaga";
        case OBESE:
        return "Otylość";
        case EXTREMLY_OBESE:
        return "Ekstrmalna otylość";
        default:
        return "poza skala";
    }
}

skala getSkala(float bmi)
{
    if(bmi > ((float)UNDERWEIGHT/10))
        if(bmi > ((float)NORMAL/10))
            if(bmi > ((float)UNDERWEIGHT/10))
                if(bmi> ((float)OBESE/10))
                    return EXTREMLY_OBESE;
                else
                    return OBESE;
            else
                return UNDERWEIGHT;
        else
            return NORMAL;
    else
        return UNDERWEIGHT;
}

vector<date> dataBase;


int main()
{
    cout << "WSTI" << " --GRUPA-- " << 2 << "DZI " << "Damian" << " " << "Potoczny" << endl;
    cout << "Modul 4 "<< " Pliki " << "Zadanie 2"<< endl;

    string linia;
    ifstream odczyt("BMI.txt");
    if(!odczyt)
    {
        cout << "Pliku nie można otworzyć";
        getchar();
        return 1;
    }
    while(!odczyt.eof())
    {
        date value;
        if(odczyt >> value.masa)
        {
            if(odczyt >> value.wzrost)
            {
                value.bmi = (float)value.masa/pow(((float)value.wzrost/100), 2);
                value.nadwaga = getSkala(value.bmi);
                dataBase.emplace_back(value);
            }
        }
        else
            cout << "Nie odczytano";
    }

    ofstream zapis("bmi_Potoczny.html");
    zapis << "<html><body>" << endl;
    zapis << "<table>" << endl;
    zapis << "<tr><td>MASA</td><td>WZROST</td><td>BMI</td><td>SKALA</td></tr>" << endl;


    for(int c=0; c< dataBase.size(); c++)
        zapis << "<tr><td>" << dataBase.at(c).masa <<"</td><td>" << dataBase.at(c).wzrost << "</td><td>" << dataBase.at(c).bmi << "</td><td>" << getSkalaString(dataBase.at(c).nadwaga)  << "</td></tr>" << endl;
    
    zapis << "</table>" << endl;
    zapis << "</body></html>" << endl;
    zapis.close();

    system("pause");
    return 0;
}