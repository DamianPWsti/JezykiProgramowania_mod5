#include <iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

int konwert(string text)
{
    int value =0;  
    for(int c = 0; c < text.length() ; c++)
        if(text.at(text.length() - (c+1))== '1')
            value += pow(2, c) * 1;
    return value;
}


string konwertInt(int number)
{
    char value[16] = {'0', '0', '0' ,'0' ,'0','0', '0', '0' ,'0' ,'0','0', '0', '0' ,'0' ,'0','0'};
    int c=15; 
    int indeks = 0; 
    while(c>=0)
    {
        if((number - pow(2 , c))>=0)
        {
            number -= pow(2, c);
            value[15-c] = '1';
        }
        c--;
    }
    return string(value);
}

int main()
{
    cout << "WSTI" << " --GRUPA-- " << 2 << "DZI " << "Damian" << " " << "Potoczny" << endl;
    cout << "Modul 4 "<< " Pliki" << "Zadanie 1"<< endl;

    //liczby.txt
    //odpowiedzi_sendor.txt

    string linia;
    int countLength9 =0;
    int count2=0;
    string max; 
    vector<string> binary;
    vector<int> decimal;
    int suma=0;
    ifstream odczyt("liczby.txt");
    if(!odczyt)
    {
        cout << "Pliku nie można otworzyć";
        getchar();
        return 1;
    }

    while(!odczyt.eof())
    {
        if(odczyt >> linia)
        {
            // cout << linia << endl;
            if(linia.length() == 9)
            {
                countLength9++;
                suma += konwert(linia);
            }
            if(linia.at(linia.length()-1) == '0')
                count2++;
            if(max.length()< linia.length())
                max = linia;
            else
                if(max.length() == linia.length())
                    if(max.compare(linia)<0)
                        max = linia;

        }
    };
    odczyt.close();
    // cout << "length: " << linia.length() << endl;
    cout << "Liczb 9 cyfrowych: " << countLength9 << endl;
    cout << "Liczb parzystych: " << count2 << endl;
    cout << "Najwieksza Liczba: " << max << " " << konwert(max) << endl;
    cout << "Suma 9 cyfrowych: " << suma <<  " " << konwertInt(suma) << endl;


    ofstream zapis("odpowiedzi_Potoczny.txt");
    zapis << "WSTI" << " --GRUPA-- " << 2 << "DZI " << "Damian" << " " << "Potoczny" << endl;
    zapis << "Modul 4 "<< "Operacje na plikach " << "Zadanie 1"<< endl;
    zapis << "Języki programowania" << endl;

    zapis << "1. Liczb parzystych: " << count2 << endl;
    zapis << "2. Najwieksza Liczba: BIN:" << max << " DEC:" << konwert(max) << endl;
    zapis << "3. Liczb 9 cyfrowych: " << countLength9 << endl;
    zapis << "\tSuma 9 cyfrowych: " << suma <<  " " << konwertInt(suma) << endl;
    zapis.close();
    system("pause");
    return 0;
}