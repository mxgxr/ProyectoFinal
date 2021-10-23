#include "usuarios.h"

Usuarios::Usuarios()
{
    users.clear();
    ifstream fin;
    string linea;

    try {
        fin.open("../usuarios.txt");
        if(!fin.is_open()){throw '1';}
        while(!fin.eof()){
            getline(fin,linea);
            Leer(linea);
        }
        fin.close();
    }  catch (char a) {
        if(a==1){} //---------> mirar el tema de los errores en qt
    }

}

bool Usuarios::Registrar(string nombre, string contrasena)
{
    if(nombre!="" and contrasena!=""){
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
    else{
        return false;
    }
}

bool Usuarios::Validar(string nombre)
{
    vector<vector<string>>::iterator iter;
    vector<string>::iterator vecIt;

    if(!users.empty()){
        for(iter=users.begin(); iter!=users.end(); iter++){
            vecIt=iter->begin();
            if(*(vecIt)==nombre){
                return true;
            }
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
    vector<string>uploadUsers;
    string texto="";
    for(unsigned i=0; i<linea.size(); i++){
        if(linea[i]!=';' and linea[i]!='\n'){
            texto+=linea[i];
        }
        else{
            uploadUsers.push_back(texto);
            texto="";
        }
    }

    users.push_back(uploadUsers);
    uploadUsers.clear();
}

void Usuarios::Guardar()
{
    ofstream fout;
    string linea="";
    vector<vector<string>>::iterator iter;
    vector<string>::iterator vecIt;

    try {
        fout.open("../ProyectoFinal/usuarios.txt");
        if(!fout.is_open()){throw '1';}
        for(iter=users.begin(); iter!=users.end(); iter++){
            for(vecIt=iter->begin(); vecIt!=iter->end(); vecIt++){
                linea+=(*vecIt);
            }
            fout << linea;
            linea="";
        }

        fout.close();

    }  catch (char a) {
        if(a==1){} //---------> mirar el tema de los errores en qt
    }


}
