#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include "../DB/registros.h"
#define tamanio_registro 239
#define App_name_size 51
using namespace std;
class RandomIndex
{
public:
    map<string, int> indice;
    map<string, int> temp_indice;
};

class RandomFile
{
private:
    string filename;

public:
    RandomIndex index;
    RandomFile(string filename)
    {
        this->filename = filename;
        //leerIndice();
    }
    Registros *busqueda(string buscar)
    {
        Registros *registro = new Registros;
        ifstream file;
        file.open("../DB/BD2.dat", ios::in | ios::binary);
        if (file.is_open())
        {
            if (index.indice.count(buscar) == 0)
            {
                return nullptr;
            }
            file.seekg(index.indice[buscar], ios::beg);
            file.read((char *)registro, tamanio_registro);
        }
        return registro;
    };
    void leerIndice()
    {
        ifstream file;
        file.open(filename, ios::in | ios::binary);
        file.seekg(0, ios::end);
        int tamanio_fichero = file.tellg();
        file.seekg(0, ios::beg);
        int tamanio_actual = 0;
        //cout << tamanio_fichero << endl;
        if (file.is_open())
        {
            while (tamanio_actual != tamanio_fichero)
            {
                char indice[App_name_size];
                int direccion;
                file.read((char *)&indice, App_name_size);
                //strcpy(indice, &temp_indice[0]);
                //string temp_indice(indice);
                //string temp_indice = indice;
                file.read((char *)&direccion, sizeof(int));
                index.indice[indice] = direccion;
                tamanio_actual += App_name_size + 4;
            }
            file.close();
        }
    };
    void guardarIndice()
    {
        fstream file;
        file.open("Indice/index.dat", ios::out | ios::app | ios::binary);
        if (file.is_open())
        {
            for (std::map<string, int>::iterator it = index.temp_indice.begin(); it != index.temp_indice.end(); ++it)
            {
                char App[App_name_size];
                strcpy(App, (it->first.substr(0, App_name_size - 1)).c_str());
                file.write((char *)&(App), App_name_size);
                file.write((char *)&(it->second), sizeof(int));
                index.indice[App] = it->second;
            }
            file.close();
            index.temp_indice.clear();
        }
    };
    void imprimirIndices()
    {
        for (std::map<string, int>::iterator it = index.indice.begin(); it != index.indice.end(); ++it)
        {
            cout << "Indice: " << it->first << "   Direccion: " << it->second << endl;
        }
    };
};
class Database
{
private:
    string filename;
    vector<Registros> registros;

public:
    Database(string filename)
    {
        this->filename = filename;
        //leerIndice();
    }
    void load(RandomFile &randomfile)
    {
        registros.clear();
        ifstream file;
        file.open(filename, ios::in | ios::binary);
        file.seekg(0, ios::end);
        int tamanio_fichero = file.tellg();
        file.seekg(0, ios::beg);
        int tamanio_actual = 0;
        if (file.is_open())
        {
            while (tamanio_actual != tamanio_fichero)
            {
                Registros *registro = new Registros;
                //file.read((char *)&tam, sizeof(int));
                file.read((char *)registro, tamanio_registro);
                registros.push_back(*registro);
                //string gg(registro->App);
                randomfile.index.temp_indice[registro->App] = tamanio_actual;
                tamanio_actual += tamanio_registro;
            }
            file.close();
        }
        //imprimir_alumnos();
    };
    void add(RandomFile &randomfile)
    {
        Registros *registro = new Registros;
        cout << "Ingrese el App[App_name_size], Category[19], Rating,(float) Review(int), Size[18], Installs[12], Type[4], Price[7], Content_Rating[10], Genres[40], Last_Update[18], Current_Ver[20], Android_Ver[20]" << endl;
        cin >> registro->App >> registro->Category >> registro->Rating >> registro->Review >> registro->Size >> registro->Installs >> registro->Type >> registro->Price >> registro->Content_Rating >> registro->Genres >> registro->Last_Updates >> registro->Current_Ver >> registro->Android_Ver;
        registros.push_back(*registro);
        fstream file;
        file.open(filename, ios::out | ios::app | ios::binary);
        if (file.is_open())
        {
            //file.write((char *)&tam, sizeof(int));
            file.write((char *)registro, tamanio_registro);
            file.close();
            randomfile.index.temp_indice[registro->App] = (registros.size() - 1) * tamanio_registro;
        }
    }
    void imprimir_DB()
    {
        for (int x = 0; x < registros.size(); x++)
        {
            cout << registros[x].App << " || ";
            cout << registros[x].Category << " || ";
            cout << registros[x].Review << " || ";
            cout << registros[x].Rating << " || ";
            cout << registros[x].Size << " || ";
            cout << registros[x].Installs << " || ";
            cout << registros[x].Type << " || ";
            cout << registros[x].Price << " || ";
            cout << registros[x].Content_Rating << " || ";
            cout << registros[x].Genres << " || ";
            cout << registros[x].Last_Updates << " || ";
            cout << registros[x].Current_Ver << " || ";
            cout << registros[x].Android_Ver << endl;
        }
    };
};
