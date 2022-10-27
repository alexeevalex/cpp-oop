#pragma once
#include "Serie.hpp"

class Episodio: public Serie{
    private:
        std::string nombre;
        std::string serie;
        int temporada;
        double calificacion;

    public:
        Episodio();
        Episodio(std::string nombreE, int temporadaE, double calificacionE, std::string serieE);

        std::string mostrarEpisodio();
        std::string mostrarSerie();
};