#pragma once
#include "Video.hpp"

class Pelicula:public Video {
    private:

    public:
        Pelicula();
        Pelicula(int, std::string, int, std::string, double);

        int mostrarCalificacion() override;


};