#include "Pelicula.hpp"

Pelicula::Pelicula():Video{} 
{
    this -> tipo = "Pelicula";
}

Pelicula::Pelicula(int id, std::string nombre, int duracion, std::string genero, double calificacion):Video{id, nombre, duracion, genero, calificacion} 
{
    this -> tipo = "Pelicula";
}

int Pelicula::mostrarCalificacion() {
    return calificacion;
}