#include "Database.hpp"
#include "Episodio.hpp"
#include "Serie.hpp"
#include "Pelicula.hpp"
#include <string>
#include <fstream>
#include <locale>

Database::Database()
{
}

Database::~Database()
{
}

void Database::crearDesdeArchivo()
{
    std::ifstream peliculasFile;
    peliculasFile.open("data_peliculas.txt");
    
    // Variables para el Loop
    std::string line;
    int counter = 1;

    // Variables para creación de objetos
    int idF;
    std::string nombreF;
    int duracionF;
    std::string generoF;
    double califF;

    while(peliculasFile.good()) {
        getline(peliculasFile, line, ',');
        // std::cout << line << "\n";

        if (counter == 1) {
            idF = stoi(line);
            // std::cout << idF << "\n";
            counter++;
        } else if (counter == 2) {
            nombreF = line;
            // std::cout << nombreF << "\n";
            counter++;
        } else if (counter == 3) {
            duracionF = stoi(line);
            // std::cout << duracionF << "\n";
            counter++;
        } else if (counter == 4) {
            generoF = line;
            // std::cout << generoF << "\n";
            counter++;
        } else if (counter == 5) {
            califF = stod(line);
            // std::cout << califF << "\n";
            counter++;

            this->vids.push_back(new Pelicula(idF, nombreF, duracionF, generoF, califF));
            counter = 1;
        }
    }

        std::ifstream seriesFile;
        seriesFile.open("data_series.txt");

    while(seriesFile.good()) {
        getline(seriesFile, line, ',');
        // std::cout << line << "\n";

        if (counter == 1) {
            idF = stoi(line);
            // std::cout << idF << "\n";
            counter++;
        } else if (counter == 2) {
            nombreF = line;
            // std::cout << nombreF << "\n";
            counter++;
        } else if (counter == 3) {
            duracionF = stoi(line);
            // std::cout << duracionF << "\n";
            counter++;
        } else if (counter == 4) {
            generoF = line;
            // std::cout << generoF << "\n";
            counter++;
        } else if (counter == 5) {
            califF = stod(line);
            // std::cout << califF << "\n";
            counter++;

            this->vids.push_back(new Serie(idF, nombreF, duracionF, generoF, califF));
            counter = 1;
        }
    }
        
        std::ifstream episodiosFile;
        episodiosFile.open("data_episodios.txt");

        int temporadaF;
        std::string serieF;

    while(episodiosFile.good()) {
        getline(episodiosFile, line, ',');
        // std::cout << line << "\n";

        if (counter == 1) {
            nombreF = line;
            counter++;
        } else if (counter == 2) {
            temporadaF = stoi(line);
            counter++;
        } else if (counter == 3) {
            califF = stod(line);
            counter++;
        } else if (counter == 4) {
            serieF = line;
            counter++;

            this->eps.push_back(new Episodio(nombreF, temporadaF, califF, serieF));
            counter = 1;
        } 
    }

    std::cout << this->mostrarVideos();
    std::cout << this->mostrarEpisodios();
}


// ---------------- VIDEOS ----------------

// Incluye un Video cualquiera en la Database
void Database::incluirVideo(Video &vnew)
{
    vids.push_back(&vnew);
}

// Incluye un Video cualquiera en la Database con el operador + sobrecargado
Database Database::operator+(Video &vnew) {
    Database b;

    vids.push_back(&vnew);
    b.vids = vids;

    return b;
}

// Muestra todos los videos de la Database (Series, Peliculas)
std::string Database::mostrarVideos()
{
    std::string videos;

    for (auto element : vids) {
        videos += element->mostrar();
    }

    return videos;
}

// Otra forma de mostrar todos los videos de la Database (Imprimirlos)
void Database::printVideos()
{
    for (auto element : vids) {
        std::cout << element->mostrar() << "\n";
    }
}

std::string Database::mostrarVideosPorCalificacion(int calif)
{
    std::string videos;

    for (auto element : vids) {
        if (element->mostrarCalificacion() == calif)
            videos += element->mostrar();
    }

    return videos;
}

std::string Database::mostrarVideosPorGenero(std::string genr)
{
    std::string videos;

    for (auto element : vids) {
        if (element->mostrarGenero() == genr)
            videos += element->mostrar();
    }

    return videos;
}

std::string Database::mostrarSeriePorCalificacion(int calif)
{
    std::string series;

    for (auto element : vids) {
        if (element->mostrarCalificacion() == calif && element->tipo == "Serie")
            series += element->mostrar();
    }

    return series;
}

std::string Database::mostrarPeliculaPorCalificacion(int calif)
{
    std::string peliculas;

    for (auto element : vids) {
        if (element->mostrarCalificacion() == calif && element->tipo == "Pelicula")
            peliculas += element->mostrar();
    }

    return peliculas;
}

std::string Database::nombreVideoPorID(int idS)
{
    std::string nombreSerie;

    for (auto element : vids) {
        if (element->mostrarID() == idS)
            nombreSerie = element->mostrarNombre();
    }

    return nombreSerie;
}

void Database::setCalificacionPorID(int idV)
{
    double califIngresada;

    for (auto element : vids) {
        if (element->mostrarID() == idV){
            std::cout << "Ingrese la Calificación." << "\n";
            std::cin >> califIngresada;
            element->setCalificacion((element->mostrarCalificacion()+califIngresada)/2);
        }
    }
}


// ---------------- EPISODIOS ----------------

// Incluye un Episodio cualquiera en la Database
void Database::incluirEpisodio(Episodio &enew)
{
    eps.push_back(&enew);
}

// Muestra todos los episodios de la Database
std::string Database::mostrarEpisodios()
{
    std::string episodios;

    for (auto element : eps) {
        episodios += element->mostrarEpisodio();
    }

    return episodios;
}

// Otra forma de mostrar todos los episodios de la Database
void Database::printEpisodios()
{
    for (auto element : eps) {
        std::cout << element->mostrarEpisodio() << "\n";
    }
}

std::string Database::mostrarEpisodiosPorNombre(std::string nombreSerie)
{
    std::string episodios;

    for (auto element : eps) {
        if (element->mostrarSerie() == nombreSerie) {
            episodios += element->mostrarEpisodio();
        }
    }

    return episodios;
}

