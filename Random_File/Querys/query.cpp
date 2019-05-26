#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../Random_File/RandomFile.h"
using namespace std;
class query
{
private:
    vector<string> consultas_aceptadas;
    vector<string> columnas;
    //vector<string> consultas_recibidas;

public:
    query()
    {
        consultas_aceptadas.push_back("select");
        consultas_aceptadas.push_back("from");
        consultas_aceptadas.push_back("DB");
        consultas_aceptadas.push_back("where");
        columnas.push_back("*");
        columnas.push_back("App");
        columnas.push_back("Category");
        columnas.push_back("Rating");
        columnas.push_back("Review");
        columnas.push_back("Size");
        columnas.push_back("Installs");
        columnas.push_back("Type");
        columnas.push_back("Price");
        columnas.push_back("Content_Rating");
        columnas.push_back("Genres");
        columnas.push_back("Last_Updates");
        columnas.push_back("Current_Ver");
        columnas.push_back("Android_Ver");
    }
    ~query() {}
    bool verificar_consulta_recibida(vector<string> query)
    {
        int contador_de_validacion = 0;

        for (size_t i = 0; i < query.size(); i++)
        {
            if (i == 1 || i == 5)
            {
                if (find(columnas.begin(), columnas.end(), query[i]) != columnas.end())
                {
                    contador_de_validacion++;
                }
            }
            else if (i == 6)
            {
                if (analizar_operador_logico(query[i]))
                {
                    contador_de_validacion++;
                }
            }
            else if (i == 7)
            {
                contador_de_validacion++;
            }
            else if (find(consultas_aceptadas.begin(), consultas_aceptadas.end(), query[i]) != consultas_aceptadas.end())
            {
                contador_de_validacion++;
            }
        }
        if (contador_de_validacion == query.size())
        {
            return true;
        }
        return false;
    }
    bool revisar_si_columna_existe_en_BD(string columna)
    {
        bool revisar_columna = find(columnas.begin(), columnas.end(), columna) != columnas.end();
        if (revisar_columna)
        {
            return true;
        }
        return false;
    }
    bool analizar_operador_logico(string param)
    {
        for (size_t i = 0; i < param.size(); i++)
        {
            if (param[i] == '=')
            {
                return true;
            }
            else if (param[i] == '<')
            {
                return true;
            }
            else if (param[i] == '>')
            {
                return true;
            }
            else if (param[i] == '<' && param[i + 1] == '=')
            {
                return true;
            }
            else if (param[i] == '>' && param[i + 1] == '=')
            {
                return true;
            }
            else if (param[i] == '!' && param[i + 1] == '=')
            {
                return true;
            }
        }
    }
    bool analizar_sexto_parametro(string param)
    {
        bool operador_logico = analizar_operador_logico(param);
        string a = param.substr(0, param.find(operador_logico));
        //string b = param.substr(param.find(operador_logico) + operador_logico.size());
        if (revisar_si_columna_existe_en_BD(a))
        {
            return true;
        }
        return false;
    }
    void Imprimir_registros(vector<Registros *> registros_recibidos, string columna)
    {
        for (int i = 0; i < registros_recibidos.size(); i++)
        {
            if (registros_recibidos[i] == nullptr)
            {
                return;
            }
            if (columna == "*")
            {
                //cout << "Indice: " << it->first << "   Direccion: " << it->second << endl;
                cout << registros_recibidos[i]->App << " || ";
                cout << registros_recibidos[i]->Category << " || ";
                cout << registros_recibidos[i]->Rating << " || ";
                cout << registros_recibidos[i]->Review << " || ";
                cout << registros_recibidos[i]->Size << " || ";
                cout << registros_recibidos[i]->Installs << " || ";
                cout << registros_recibidos[i]->Type << " || ";
                cout << registros_recibidos[i]->Price << " || ";
                cout << registros_recibidos[i]->Content_Rating << " || ";
                cout << registros_recibidos[i]->Genres << " || ";
                cout << registros_recibidos[i]->Last_Updates << " || ";
                cout << registros_recibidos[i]->Current_Ver << " || ";
                cout << registros_recibidos[i]->Android_Ver << endl;
            }
            else if (columna == "App")
            {
                cout << registros_recibidos[i]->App << endl;
            }
            else if (columna == "Category")
            {
                cout << registros_recibidos[i]->Category << endl;
            }
            else if (columna == "Rating")
            {
                cout << registros_recibidos[i]->Rating << endl;
            }
            else if (columna == "Review")
            {
                cout << registros_recibidos[i]->Review << endl;
            }
            else if (columna == "Size")
            {
                cout << registros_recibidos[i]->Size << endl;
            }
            else if (columna == "Installs")
            {
                cout << registros_recibidos[i]->Installs << endl;
            }
            else if (columna == "Type")
            {
                cout << registros_recibidos[i]->Type << endl;
            }
            else if (columna == "Price")
            {
                cout << registros_recibidos[i]->Price << endl;
            }
            else if (columna == "Content_Rating")
            {
                cout << registros_recibidos[i]->Content_Rating << endl;
            }
            else if (columna == "Genres")
            {
                cout << registros_recibidos[i]->Genres << endl;
            }
            else if (columna == "Last_Updates")
            {
                cout << registros_recibidos[i]->Last_Updates << endl;
            }
            else if (columna == "Current_Ver")
            {
                cout << registros_recibidos[i]->Current_Ver << endl;
            }
            else if (columna == "Android_Ver")
            {
                cout << registros_recibidos[i]->Android_Ver << endl;
            }
            delete registros_recibidos[i];
        }
    }
    bool ejecutar_consulta_recibida(vector<string> query)
    {
        if (!verificar_consulta_recibida(query))
        {
            cout << "Error en la consulta, consulta erronea" << endl;
            return false;
        }
        RandomFile randomfile("../Random_File/Indice/index.dat");
        randomfile.leerIndice();
        //randomfile.imprimirIndices();
        vector<Registros *> registros_recibidos;
        char App[App_name_size];
        if (query.size() == 4)
        {
            //randomfile.busqueda("0", query[1]);
            for (std::map<string, int>::iterator it = randomfile.index.indice.begin(); it != randomfile.index.indice.end(); ++it)
            {
                registros_recibidos.push_back(randomfile.busqueda(it->first));
            }
            Imprimir_registros(registros_recibidos, query[1]);
        }
        else if (query.size() == 8)
        {

            strcpy(App, (query[7].substr(0, App_name_size - 1)).c_str());
            //randomfile.busqueda(App, query[1]);
            registros_recibidos.push_back(randomfile.busqueda(App));
            Imprimir_registros(registros_recibidos, query[1]);
        }
        return true;
    }
};
int main()
{
    query obj;
    vector<string> query;
    string word;
    while (true)
    {
        cin >> word;
        if (word == ";")
            break;
        if (word[0] == (char)34)
        {
            bool cadena_analizada = false;
            word = word.substr(1);
            string sub_cadena;
            if (word[word.length() - 1] == (char)34)
            {
                word = word.substr(0, word.length() - 1);
                cadena_analizada = true;
            }
            while (!cadena_analizada)
            {
                cin >> sub_cadena;
                if (sub_cadena[sub_cadena.length() - 1] == (char)34)
                {
                    sub_cadena = sub_cadena.substr(0, sub_cadena.length() - 1);
                    cadena_analizada = true;
                }
                word += " " + sub_cadena;
            }
        }
        //cout << word << endl;
        query.push_back(word);
    }
    obj.ejecutar_consulta_recibida(query);
    query.clear();
    /*
    Database db("Database/BD2.dat");
    RandomFile randomfile("Indice/index.dat");
    db.load(randomfile);
    //randomfile.leerIndice();
    db.imprimir_DB();
    //randomfile.busqueda("Coloring book moana");
    randomfile.guardarIndice();
    //randomfile.imprimirIndices();
    //db.add(randomfile);
    //db.imprimir_alumnos();
    //randomfile.imprimirIndices();
    //randomfile.guardarIndice();
    return 0;*/
}