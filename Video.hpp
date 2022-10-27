#pragma once
#include "iostream"

class Video {
    protected:
        int id;
        std::string nombre;
        int duracion;
        std::string genero;
        double calificacion;
    
    public:
        Video();
        Video(int, std::string, int, std::string, double);
        
        std::string tipo;

        virtual int mostrarCalificacion() = 0;
        std::string mostrarGenero();
        int mostrarID();
        std::string mostrarNombre();
        std::string mostrar();
        void setCalificacion(int);

};