#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../RandomFile.h"
#include <sstream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

#ifndef QTapp_h
  #define path ""
#else
    #define path QTapp_h
#endif


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
        consultas_aceptadas.push_back("insert");
        consultas_aceptadas.push_back("into");
        consultas_aceptadas.push_back("values");
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
            //cout << query[i] << endl;
            if (query[0] == "insert" && i == 4)
            {
                contador_de_validacion++;
            }
            if ((i == 1 || i == 5) && query[0] != "insert")
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
            //cout << contador_de_validacion << " " << query.size() << endl;
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
    /*bool analizar_sexto_parametro(string param)
    {
        bool operador_logico = analizar_operador_logico(param);
        string a = param.substr(0, param.find(operador_logico));
        //string b = param.substr(param.find(operador_logico) + operador_logico.size());
        if (revisar_si_columna_existe_en_BD(a))
        {
            return true;
        }
        return false;
    }*/
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
    vector<string> parse_query(string query_string)
    {
        vector<string> query;
        size_t pos = 0;
        string sub_string = "";
        for (size_t i = 0; i < query_string.size(); i++)
        {
            if (query_string[i] == ';')
            {
                break;
            }
            if (query_string[i] == ' ' && query_string[i] != ',')
            {
                query.push_back(sub_string);
                sub_string = "";
            }
            else
            {
                if(query_string[i] == (char)39){
                    i++;
                    while (query_string[i]!=(char)39){
                        sub_string += query_string[i];    
                        i++;
                    }
                    
                }else if (query_string[i] != '(' && query_string[i] != ')')
                {
                    sub_string += query_string[i];
                }
            }
        }
        return query;

        /*
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
        */
    }
    stringstream ss(string s)
    {
        stringstream geek;
        geek << s;
        return geek;
    }
    void Insertar_query(string data)
    {
        Registros *registro = new Registros;
        Databases db(string(path)+"Dependencies/BD2.dat");
        RandomFile randomfile(string(path)+"Random_File/Indice/index.dat");
        randomfile.leerIndice();
        string sub_string = "";
        vector<string> regis;
        for (size_t i = 0; i <= data.size(); i++)
        {
            if (data[i] == ',' || i == data.size())
            {
                regis.push_back(sub_string);
                sub_string = "";
            }
            else
            {
                sub_string += data[i];
            }
        }
        try
        {
            /*char App[51];
            char Category[20];
            float Rating = stof(regis[2]);
            int Review = stoi(regis[3]);
            char Size[19];
            char Installs[15];
            char Type[5];
            char Price[8];
            char Content_Rating[11];
            char Genres[41];
            char Last_Updates[19];
            char Current_Ver[21];
            char Android_Ver[21];*/
            /*strcpy(App, (regis[0].substr(0, 51 - 1)).c_str());
                strcpy(Category, (regis[1].substr(0, 20 - 1)).c_str());
                strcpy(Size, (regis[4].substr(0, 19 - 1)).c_str());
                strcpy(Installs, (regis[5].substr(0, 15 - 1)).c_str());
                strcpy(Type, (regis[6].substr(0, 5 - 1)).c_str());
                strcpy(Price, (regis[7].substr(0, 8 - 1)).c_str());
                strcpy(Content_Rating, (regis[8].substr(0, 11 - 1)).c_str());
                strcpy(Genres, (regis[9].substr(0, 41 - 1)).c_str());
                strcpy(Last_Updates, (regis[10].substr(0, 19 - 1)).c_str());
                strcpy(Current_Ver, (regis[11].substr(0, 21 - 1)).c_str());
                strcpy(Android_Ver, (regis[12].substr(0, 21 - 1)).c_str());*/
            ///////////////////////////////////////////////////////////////
            //geek << regis[0];
            ss(regis[0]) >> registro->App; //geek << regis[1];
            ss(regis[1]) >> registro->Category;
            //geek << regis[2];
            //ss(regis[0]) >> registro->Rating;
            registro->Rating = stof(regis[2]);
            //geek << regis[3];
            //ss(regis[0]) >> registro->Review;
            registro->Review = stoi(regis[3]);
            //geek << regis[4];
            ss(regis[4]) >> registro->Size;
            //geek << regis[5];
            ss(regis[5]) >> registro->Installs;
            //geek << regis[6];
            ss(regis[6]) >> registro->Type;
            //geek << regis[7];
            ss(regis[7]) >> registro->Price;
            //geek << regis[8];
            ss(regis[8]) >> registro->Content_Rating;
            //geek << regis[9];
            ss(regis[9]) >> registro->Genres;
            //geek << regis[10];
            ss(regis[10]) >> registro->Last_Updates;
            //geek << regis[11];
            ss(regis[11]) >> registro->Current_Ver;
            //geek << regis[12];
            ss(regis[12]) >> registro->Android_Ver;
            /*strncpy(registro->App, App, 51);
            strncpy(registro->Category, Category, 20);
            registro->Review = Review;
            registro->Rating = Rating;
            strncpy(registro->Size, Size, 19);
            strncpy(registro->Installs, Installs, 15);
            strncpy(registro->Type, Type, 5);
            strncpy(registro->Price, Price, 8);
            strncpy(registro->Content_Rating, Content_Rating, 11);
            strncpy(registro->Genres, Genres, 41);
            strncpy(registro->Last_Updates, Last_Updates, 19);
            strncpy(registro->Current_Ver, Current_Ver, 21);
            strncpy(registro->Android_Ver, Android_Ver, 21);*/
        }
        catch (...)
        {
            cout << "Error en la inserccion" << endl;
            return;
        }
        db.add(randomfile, registro);
        //db.imprimir_DB();
        //randomfile.imprimirIndices();
        randomfile.guardarIndice();
        //cout << "nice";
    }
    pair<bool,string> get_result(Registros* registros_recibidos,string columna){
        bool punt=1;
        string ress;
        if (registros_recibidos == nullptr)
        {
            pair<bool,string>aa(0,"null");
            return aa;
        }
        if (columna == "*")
        {

        }
        else if (columna == "App")
        {
            punt =0;
            ress=registros_recibidos->App;
        }
        else if (columna == "Category")
        {
            punt =0;
            ress=registros_recibidos->Category;
        }
        else if (columna == "Rating")
        {
            punt =0;
            ress=to_string(registros_recibidos->Rating);
        }
        else if (columna == "Review")
        {
            punt =0;
            ress=to_string(registros_recibidos->Review);
        }
        else if (columna == "Size")
        {
            punt =0;
            ress=registros_recibidos->Size;
        }
        else if (columna == "Installs")
        {
            punt =0;
            ress=registros_recibidos->Installs;
        }
        else if (columna == "Type")
        {
            punt =0;
            ress=registros_recibidos->Type;
        }
        else if (columna == "Price")
        {
            punt =0;
            ress=registros_recibidos->Price;
        }
        else if (columna == "Content_Rating")
        {
            punt =0;
            ress=registros_recibidos->Content_Rating;
        }
        else if (columna == "Genres")
        {
            punt =0;
            ress=registros_recibidos->Genres;
        }
        else if (columna == "Last_Updates")
        {
            punt =0;
            ress=registros_recibidos->Last_Updates;
        }
        else if (columna == "Current_Ver")
        {
            punt =0;
            ress=registros_recibidos->Current_Ver;
        }
        else if (columna == "Android_Ver")
        {
            punt =0;
            ress=registros_recibidos->Android_Ver;
        }    
        return pair <bool,string>(punt,ress);        
        
    }

    pair<Registros*,pair<bool,string>> ejecutar_consulta_recibida(string query_string){
        vector<string> query = parse_query(query_string);
        if (!verificar_consulta_recibida(query))
        {
            cout << "Error en la consulta, consulta erronea" << endl;
            exit(-1);
            ;
        }

        if (query[0] == "insert")
        {
            Insertar_query(query[4]);
        }
        else if (query[0] == "select")
        {
            RandomFile randomfile(string(path)+"Random_File/Indice/index.dat");
            randomfile.leerIndice();
            vector<Registros *> registros_recibidos;
            Registros* dev;
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
                dev=randomfile.busqueda(App);
                registros_recibidos.push_back(dev);                
                //Imprimir_registros(registros_recibidos, query[1]);
                return pair<Registros*,pair<bool,string>>(dev,get_result(dev,query[1]));
            }
        }
        //randomfile.imprimirIndices();
    }
};
/*
int main()
{
    string q = "select * from DB where App = 'Gas Station' ;";
    //string q = "insert into DB values ('test','test','5.5','5',test,test,test,test,test,test,test,test,test) ;";
    query obj;
    obj.ejecutar_consulta_recibida(q);
}
*/