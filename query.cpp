#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "RandomFile.h"
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
    bool ejecutar_consulta_recibida(vector<string> query)
    {
        if (!verificar_consulta_recibida(query))
        {
            cout << "Error en la consulta, consulta erronea" << endl;
            return false;
        }
        RandomFile randomfile("Indice/index.dat");
        randomfile.leerIndice();
        //randomfile.imprimirIndices();
        if (query.size() == 4)
        {
            randomfile.busqueda("0", query[1]);
        }
        else if (query.size() == 8)
        {
            char App[50];
            strcpy(App, (query[7].substr(0, 49)).c_str());
            randomfile.busqueda(App, query[1]);
        }
        return true;
    }
};
int main()
{
    /*query obj;
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
    query.clear();*/
    Database db;
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
    return 0;
}