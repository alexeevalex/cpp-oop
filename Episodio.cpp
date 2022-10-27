#include "Episodio.hpp"
#include "Serie.hpp"

Episodio::Episodio()
{
    this->nombre="Mpty";
    this->temporada=1;
    this->calificacion=4.5;
    this->serie="No Serie";
}

Episodio::Episodio(std::string nombreE, int temporadaE, double calificacionE, std::string serieE) 
{
    this->nombre=nombreE;
    this->temporada=temporadaE;
    this->calificacion=calificacionE;
    this->serie=serieE;

}

std::string Episodio::mostrarEpisodio() 
{
    std::string msg;

    msg = "Título: " + nombre + ", Temporada: " + std::to_string(temporada) + ", Calificacion: " + std::to_string(calificacion) + ", Serie: " + serie + "\n";

    return msg;
}

std::string Episodio::mostrarSerie()
{
    return serie;
}