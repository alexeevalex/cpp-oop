#pragma once

#include "Video.hpp"
#include "Episodio.hpp"
#include <iostream>
#include <vector>

class Database {
    private:
        std::vector<Video *> vids;
        std::vector<Episodio *> eps;
    public:
        Database();
        ~Database();

        void crearDesdeArchivo();
        
        // VIDEOS
        void incluirVideo(Video&);
        Database operator+(Video&);
        std::string mostrarVideos();
        void printVideos();
        std::string mostrarVideosPorCalificacion(int calif);
        std::string mostrarVideosPorGenero(std::string genr);
        std::string nombreVideoPorID(int idS);
        void setCalificacionPorID(int idV);

        std::string mostrarSeriePorCalificacion(int calif);
        std::string mostrarPeliculaPorCalificacion(int calif);


        // EPISODIOS
        void incluirEpisodio(Episodio&);
        std::string mostrarEpisodios();
        void printEpisodios();
        std::string mostrarEpisodiosPorNombre(std::string nombreSerie);
};