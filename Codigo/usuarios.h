#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <QString>

using namespace std;

class Usuarios
{
private:
    vector<vector<string>>users;

public:
    Usuarios();
    bool Registrar(string nombre, string contrasena);
    bool Validar(string nombre);
    bool Validar(string nombre, string contrasena);
    void Leer(string linea);
    void Guardar();
};

#endif // USUARIOS_H
