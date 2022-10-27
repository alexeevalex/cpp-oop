#include "Video.hpp"
#include <string>


Video::Video()
{
    this -> id = 0;
    this -> nombre = "Vacío";
    this -> duracion = 0;
    this -> genero = "Drama";
    this -> calificacion = 5.0;
    this -> tipo = "Video";
}

Video::Video(int idV, std::string nombreV, int duracionV, std::string generoV, double califV) 
{
    this -> id = idV;
    this -> nombre = nombreV;
    this -> duracion = duracionV;
    this -> genero = generoV;
    this -> calificacion = califV;
    this -> tipo = "Video";
}


int Video::mostrarCalificacion() {
    return calificacion;
}

std::string Video::mostrarGenero() {
    return genero;
}

int Video::mostrarID() {
    return id;
}

std::string Video::mostrarNombre() {
    return nombre;
}

std::string Video::mostrar(){
    std::string msg;

    msg = "ID: " + std::to_string(id) + ", Título: " + nombre + ", Duración: " + std::to_string(duracion) + ", Género: " + genero + ", Calificacion: " + std::to_string(calificacion) +  "\n";

    return msg;
}

void Video::setCalificacion(int calif) {
    this -> calificacion = calif;
}