#include "Serie.hpp"

Serie::Serie():Video{} 
{
    this -> tipo = "Serie";
}

Serie::Serie(int id, std::string nombre, int duracion, std::string genero, double calificacion):Video{id, nombre, duracion, genero, calificacion} 
{
    this -> tipo = "Serie";
}

int Serie::mostrarCalificacion() {
    return calificacion;
}