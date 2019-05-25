#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include "Locks/atomic_ops.h"
using namespace std;
class Registros
{
public:
    char App[50];
    char Category[19];
    float Rating;
    int Review;
    char Size[18];
    char Installs[12];
    char Type[4];
    char Price[7];
    char Content_Rating[10];
    char Genres[40];
    char Last_Updates[18];
    char Current_Ver[20];
    char Android_Ver[20];
};
class RandomIndex
{
public:
    map<string, int> indice;
};

class RandomFile
{
private:
    string filename;
    char indexname[50];

public:
    RandomIndex index;
    RandomFile(string filename)
    {
        this->filename = filename;
        leerIndice();
    }
    int busqueda(char indexname[50])
    {
        Registros *temp = new Registros;
        //this->indexname = indexname;
        ifstream file;
        file.open(filename, ios::in | ios::binary);
        char indice;
        int direccion = 0;
        if (file.is_open())
        {
            file.seekg(index.indice[indexname], ios::beg);
            /*int tam = 0;
            file.read((char *)&tam, sizeof(int));
            file.read((char *)temp, tam);*/
            file.read((char *)&indice, 50);
            file.read((char *)&direccion, sizeof(int));
        }
        /*cout << temp->id << " ";
        cout << temp->App << " ";
        cout << temp->Category << " ";
        cout << temp->Rating << " ";
        cout << temp->Review << " ";
        cout << temp->Size << " ";
        cout << temp->Installs << " ";
        cout << temp->Type << " ";
        cout << temp->Price << " ";
        cout << temp->Content_Rating << " ";
        cout << temp->Genres << " ";
        cout << temp->Last_Updates << " ";
        cout << temp->Current_Ver << " ";
        cout << temp->Android_Ver << endl;*/
        delete temp;
        return direccion;
    };
    void leerIndice()
    {
        ifstream file;
        file.open(filename, ios::in | ios::binary);
        file.seekg(0, ios::end);
        int tamanio_fichero = file.tellg();
        file.seekg(0, ios::beg);
        int tamanio_actual = 0;
        cout << tamanio_fichero << endl;
        if (file.is_open())
        {
            while (tamanio_actual != tamanio_fichero)
            {
                char indice[50];
                int direccion;
                file.read((char *)&indice, 50);
                //strcpy(indice, &temp_indice[0]);
                //string temp_indice(indice);
                string temp_indice = indice;
                cout << temp_indice << endl;
                file.read((char *)&direccion, sizeof(int));
                index.indice[indice] = direccion;
                tamanio_actual += 54;
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
            for (std::map<string, int>::iterator it = index.indice.begin(); it != index.indice.end(); ++it)
            {
                file.write((char *)&(it->first), 50);
                file.write((char *)&(it->second), sizeof(int));
            }
            file.close();
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
    char filename[100];
    vector<Registros *> registros;

public:
    void load(RandomFile &randomfile)
    {
        registros.clear();
        ifstream file;
        file.open("Database/BD2.dat", ios::in | ios::binary);
        file.seekg(0, ios::end);
        int tamanio_fichero = file.tellg();
        file.seekg(0, ios::beg);
        int tamanio_actual = 0;
        if (file.is_open())
        {
            while (tamanio_actual != tamanio_fichero)
            {
                Registros *registro = new Registros;
                int tam = 226;
                //file.read((char *)&tam, sizeof(int));
                file.read((char *)registro, tam);
                registros.push_back(registro);
                randomfile.index.indice[registro->App] = tamanio_actual;
                tamanio_actual += 226;
            }
            file.close();
        }
        imprimir_alumnos();
    };
    void add(RandomFile &randomfile)
    {
        Registros *registro = new Registros;
        cout << "Ingrese el App[50], Category[19], Rating,(float) Review(int), Size[18], Installs[12], Type[4], Price[7], Content_Rating[10], Genres[40], Last_Update[18], Current_Ver[20], Android_Ver[20]" << endl;
        cin >> registro->App >> registro->Category >> registro->Rating >> registro->Review >> registro->Size >> registro->Installs >> registro->Type >> registro->Price >> registro->Content_Rating >> registro->Genres >> registro->Last_Updates >> registro->Current_Ver >> registro->Android_Ver;
        registros.push_back(registro);
        fstream file;
        file.open("Database/BD2.dat", ios::out | ios::app | ios::binary);
        if (file.is_open())
        {
            int tam = 226;
            //file.write((char *)&tam, sizeof(int));
            file.write((char *)registro, tam);
            file.close();
            randomfile.index.indice[registro->App] = (registros.size() - 1) * tam;
        }
    }
    void imprimir_alumnos()
    {
        for (int x = 0; x < registros.size(); x++)
        {
            cout << registros[x]->App << " ";
            cout << registros[x]->Category << " ";
            cout << registros[x]->Rating << " ";
            cout << registros[x]->Review << " ";
            cout << registros[x]->Size << " ";
            cout << registros[x]->Installs << " ";
            cout << registros[x]->Type << " ";
            cout << registros[x]->Price << " ";
            cout << registros[x]->Content_Rating << " ";
            cout << registros[x]->Genres << " ";
            cout << registros[x]->Last_Updates << " ";
            cout << registros[x]->Current_Ver << " ";
            cout << registros[x]->Android_Ver << endl;
        }
    };
};
int main()
{
    Database db;
    RandomFile randomfile("Indice/index.dat");
    //db.load(randomfile);
    //db.imprimir_alumnos();
    //randomfile.imprimirIndices();
    //randomfile.guardarIndice();
    //db.add(randomfile);
    //randomfile.guardarIndice();
    /*int add_alumnos;
    cin >> add_alumnos;
    for (int i = 0; i < add_alumnos; i++)
    {
        aula.add(randomfile);
    }*/
    return 0;
}
