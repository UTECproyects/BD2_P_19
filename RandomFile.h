#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include "Locks/atomic_ops.h"
#define tamanio_registro 237
#define App_name_size 51
using namespace std;
class Registros
{
public:
    char App[51];
    char Category[20];
    float Rating;
    int Review;
    char Size[19];
    char Installs[13];
    char Type[5];
    char Price[8];
    char Content_Rating[11];
    char Genres[41];
    char Last_Updates[19];
    char Current_Ver[21];
    char Android_Ver[21];
};
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
    void busqueda(char buscar[App_name_size], string columna)
    {
        Registros *temp = new Registros;
        //this->indexname = indexname;
        ifstream file;
        file.open("Database/BD2.dat", ios::in | ios::binary);
        //char indice;
        //int direccion = 0;
        if (buscar == "0")
        {
            for (std::map<string, int>::iterator it = index.indice.begin(); it != index.indice.end(); ++it)
            {
                if (file.is_open())
                {
                    file.seekg(it->second, ios::beg);
                    file.read((char *)temp, tamanio_registro);
                    if (columna == "*")
                    {
                        //cout << "Indice: " << it->first << "   Direccion: " << it->second << endl;
                        cout << temp->App << " || ";
                        cout << temp->Category << " || ";
                        cout << temp->Rating << " || ";
                        cout << temp->Review << " || ";
                        cout << temp->Size << " || ";
                        cout << temp->Installs << " || ";
                        cout << temp->Type << " || ";
                        cout << temp->Price << " || ";
                        cout << temp->Content_Rating << " || ";
                        cout << temp->Genres << " || ";
                        cout << temp->Last_Updates << " || ";
                        cout << temp->Current_Ver << " || ";
                        cout << temp->Android_Ver << endl;
                    }
                    else if (columna == "App")
                    {
                        cout << temp->App << endl;
                    }
                    else if (columna == "Category")
                    {
                        cout << temp->Category << endl;
                    }
                    else if (columna == "Rating")
                    {
                        cout << temp->Rating << endl;
                    }
                    else if (columna == "Review")
                    {
                        cout << temp->Review << endl;
                    }
                    else if (columna == "Size")
                    {
                        cout << temp->Size << endl;
                    }
                    else if (columna == "Installs")
                    {
                        cout << temp->Installs << endl;
                    }
                    else if (columna == "Type")
                    {
                        cout << temp->Type << endl;
                    }
                    else if (columna == "Price")
                    {
                        cout << temp->Price << endl;
                    }
                    else if (columna == "Content_Rating")
                    {
                        cout << temp->Content_Rating << endl;
                    }
                    else if (columna == "Genres")
                    {
                        cout << temp->Genres << endl;
                    }
                    else if (columna == "Last_Updates")
                    {
                        cout << temp->Last_Updates << endl;
                    }
                    else if (columna == "Current_Ver")
                    {
                        cout << temp->Current_Ver << endl;
                    }
                    else if (columna == "Android_Ver")
                    {
                        cout << temp->Android_Ver << endl;
                    }
                }
            }
            delete temp;
            return;
        }
        if (file.is_open())
        {
            file.seekg(index.indice[buscar], ios::beg);
            //cout << index.indice[buscar] << endl;
            /*int tam = 0;
            file.read((char *)&tam, sizeof(int));
            file.read((char *)temp, tam);*/
            //file.read((char *)&indice, App_name_size);
            file.read((char *)temp, tamanio_registro);
        }
        if (columna == "*")
        {
            cout << temp->App << " || ";
            cout << temp->Category << " || ";
            cout << temp->Rating << " || ";
            cout << temp->Review << " || ";
            cout << temp->Size << " || ";
            cout << temp->Installs << " || ";
            cout << temp->Type << " || ";
            cout << temp->Price << " || ";
            cout << temp->Content_Rating << " || ";
            cout << temp->Genres << " || ";
            cout << temp->Last_Updates << " || ";
            cout << temp->Current_Ver << " || ";
            cout << temp->Android_Ver << endl;
        }
        if (columna == "App")
        {
            cout << temp->App << endl;
        }
        else if (columna == "Category")
        {
            cout << temp->Category << endl;
        }
        else if (columna == "Rating")
        {
            cout << temp->Rating << endl;
        }
        else if (columna == "Review")
        {
            cout << temp->Review << endl;
        }
        else if (columna == "Size")
        {
            cout << temp->Size << endl;
        }
        else if (columna == "Installs")
        {
            cout << temp->Installs << endl;
        }
        else if (columna == "Type")
        {
            cout << temp->Type << endl;
        }
        else if (columna == "Price")
        {
            cout << temp->Price << endl;
        }
        else if (columna == "Content_Rating")
        {
            cout << temp->Content_Rating << endl;
        }
        else if (columna == "Genres")
        {
            cout << temp->Genres << endl;
        }
        else if (columna == "Last_Updates")
        {
            cout << temp->Last_Updates << endl;
        }
        else if (columna == "Current_Ver")
        {
            cout << temp->Current_Ver << endl;
        }
        else if (columna == "Android_Ver")
        {
            cout << temp->Android_Ver << endl;
        }

        delete temp;
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
            for (std::map<string, int>::iterator it = index.temp_indice.begin(); it != index.temp_indice.end(); ++it)
            {
                char App[App_name_size];
                strcpy(App, (it->first.substr(0, 49)).c_str());
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
    char filename[100];
    vector<Registros> registros;

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
        file.open("Database/BD2.dat", ios::out | ios::app | ios::binary);
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
