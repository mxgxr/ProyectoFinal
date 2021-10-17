#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <fstream>

using namespace std;

class Usuarios
{
private:
    string nomUser, contraUser;
    int level;
public:
    Usuarios(string nombre, string contrasena, int nivel);
    void Registrar();
    bool Validar();
    void Leer();
    void Guardar();
};

#endif // USUARIOS_H
