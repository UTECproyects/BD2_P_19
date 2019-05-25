#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
        columnas.push_back("*");
        columnas.push_back("varian_apesta");
        consultas_aceptadas.push_back("from");
        consultas_aceptadas.push_back("DB");
        consultas_aceptadas.push_back("where");
        columnas.push_back("a");
        columnas.push_back("b");
    }
    ~query() {}
    bool verificar_consulta_recibida(vector<string> query)
    {
        int contador_de_validacion = 0;

        for (size_t i = 0; i < query.size(); i++)
        {
            if (i == 1)
            {
                if (find(columnas.begin(), columnas.end(), query[i]) != columnas.end())
                {
                    contador_de_validacion++;
                }
            }
            else if (i == 5)
            {
                if (analizar_sexto_parametro(query[i]))
                {
                    contador_de_validacion++;
                }
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
    string analizar_operador_logico(string param)
    {
        for (size_t i = 0; i < param.size(); i++)
        {
            if (param[i] == '=')
            {
                return "=";
            }
            else if (param[i] == '<')
            {
                return "<";
            }
            else if (param[i] == '>')
            {
                return ">";
            }
            else if (param[i] == '<' && param[i + 1] == '=')
            {
                return "<=";
            }
            else if (param[i] == '>' && param[i + 1] == '=')
            {
                return ">=";
            }
            else if (param[i] == '!' && param[i + 1] == '=')
            {
                return "!=";
            }
        }
    }
    bool analizar_sexto_parametro(string param)
    {
        string operador_logico = analizar_operador_logico(param);
        string a = param.substr(0, param.find(operador_logico));
        string b = param.substr(param.find(operador_logico) + operador_logico.size());
        if (revisar_si_columna_existe_en_BD(a) && revisar_si_columna_existe_en_BD(b))
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
        if (query.size() == 4)
        {
            cout << "Mostrar " + query[1] + " de la base de datos " + query[3] << endl;
        }
        else if (query.size() == 6)
        {
            cout << "Mostrar " + query[1] + " de la base de datos, donde " + query[5] << endl;
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

        query.push_back(word);
    }
    obj.ejecutar_consulta_recibida(query);
    query.clear();
}