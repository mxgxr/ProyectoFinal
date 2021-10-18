#include "usuarios.h"

Usuarios::Usuarios()
{
    ifstream fin;
    string linea;

    try {
        fin.open("../ProyectoFinal/usuarios.txt");
        if(!fin.is_open()){throw '1';}
        while(!fin.eof()){

        }
        fin.close();
    }  catch (char a) {
        if(a==1){} //---------> mirar el tema de los errores en qt
    }



}

bool Usuarios::Registrar(string nombre, string contrasena)
{
    if(!Validar(nombre)){
        vector<string>newUser;
        newUser.push_back(nombre);
        newUser.push_back(contrasena);
        newUser.push_back("1");
        users.push_back(newUser);
        newUser.clear();
        return true;
    }
    else{
        return false;
    }
}

bool Usuarios::Validar(string nombre)
{
    vector<vector<string>>::iterator iter;
    vector<string>::iterator vecIt;

    for(iter=users.begin(); iter!=users.end(); iter++){
        vecIt=iter->begin();
        if(*(vecIt)==nombre){
            return true;
        }
    }
    return false;
}

bool Usuarios::Validar(string nombre, string contrasena)
{
    vector<vector<string>>::iterator iter;
    vector<string>::iterator vecIt;

    for(iter=users.begin(); iter!=users.end(); iter++){
        vecIt=iter->begin();
        if(*(vecIt)==nombre){
            vecIt++;
            if(*(vecIt)==contrasena){
                return true;
            }
        }
    }
    return false;
}

void Usuarios::Leer(string linea)
{


}

void Usuarios::Guardar()
{

}
