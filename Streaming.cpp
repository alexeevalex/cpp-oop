#include "Streaming.hpp"


// Constructor
Streaming::Streaming()
{}

// Arranca el servicio
void Streaming::start()
{
    int tecla;
    std::string generoSeleccionado;

    //Creación de los Objetos Manualmente
    // Pelicula peli1(001, "La Paola-Pelicula", 120, "Drama", 4.5);
    // Pelicula peli2(002, "Semana 5, Un Horror", 420, "Acción", 2.0);
    // Pelicula peli3(003, "Caminito, de la Escuela", 190, "Misterio", 5.0);

    // Serie seri1(004, "La Alex-Serie", 460, "Drama", 5.0);
    // Serie seri2(005, "Tronco Común: El Relleno", 520, "Acción", 2.0);
    // Serie seri3(006, "El Bote de Mariotte", 460, "Misterio", 3.0);

    // Episodio epi1("Hola Amiguitos", 1, 5.0, "La Alex-Serie");
    // Episodio epi2("El Episodio Padre", 1, 5.0, "La Alex-Serie");
    // Episodio epi3("Llegando Temprano al Tec", 1, 5.0, "La Alex-Serie");

    // Base de Datos
    Database base;
    // base.incluirVideo(peli1);
    // base.incluirVideo(peli2);
    // base.incluirVideo(peli3);

    // base.incluirVideo(seri1);
    // base.incluirVideo(seri2);
    // base.incluirVideo(seri3);

    // base.incluirEpisodio(epi1);
    // base.incluirEpisodio(epi2);
    // base.incluirEpisodio(epi3);

    // std::cout << base.mostrarVideos();
    // std::cout << base.mostrarEpisodios();

    while (tecla != 0) {
        std::cout << "================= MENÚ =================" << "\n";
        std::cout << "1. Cargar archivo de datos" << "\n";
        std::cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << "\n";
        std::cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << "\n";
        std::cout << "4. Mostrar las películas con cierta calificacion" << "\n";
        std::cout << "5. Calificar un video" << "\n";
        std::cout << "0. Salir" << "\n";
        std::cout << "========================================" << "\n";
        
        std::cin >> tecla;
    

        if (tecla == 1) {
            // Cargar el archivo de datos de los videos
            base.crearDesdeArchivo();


        } else if (tecla == 2) {
            // Elegir si con calificación o género
            std::cout << "1. Mostrar con una cierta calificación" << "\n";
            std::cout << "2. Mostrar con un cierto género" << "\n";
            std::cout << "========================================" << "\n";
            std::cin >> tecla;

            // Calificación
            if (tecla == 1) {
                std::cout << "Especifique la calificación (Num del 1 al 5)" << "\n";

                // MOSTRAR TODOS LOS ||VIDEOS|| CON ESA CALIFICACIÓN
                try {
                    std::cin >> tecla;
                    // std::cout << base.mostrarVideosPorCalificacion(tecla);

                    if (tecla != 1 || tecla != 2 || tecla != 3 || tecla != 4 || tecla != 5) {
                        throw std::invalid_argument("Opción Inválida");
                    }
                    break;
                }
                catch (std::invalid_argument &e) {
                    std::cerr << "Ocurrio una excepcion: " << e.what() << "\n";
                }
                
                std::cout << base.mostrarVideosPorCalificacion(tecla);
            } 
            // Género
            else if (tecla == 2) {
                std::cout << "Seleccione el género" << "\n";
                std::cout << "1. Drama" << "\n";
                std::cout << "2. Acción" << "\n";
                std::cout << "3. Misterio" << "\n";
                std::cin >> tecla;

                if (tecla == 1) {
                    generoSeleccionado = "Drama";
                } else if (tecla == 2) {
                    generoSeleccionado = "Acción";
                } else if (tecla == 3) {
                    generoSeleccionado = "Misterio";
                } else {
                    std::cout << "Opción Inválida" << "\n";
                    break;
                }
                
                std::cout << base.mostrarVideosPorGenero(generoSeleccionado);
            }



        } else if (tecla == 3) {
            // Elegir la calificación
            std::cout << "Especifique la calificación (Num del 1 al 5) de la serie" << "\n";
            std::cin >> tecla;

            // MOSTRAR TODAS LAS ||SERIES|| CON ESA CALIFICACIÓN
            std::cout << base.mostrarSeriePorCalificacion(tecla);

            // MOSTRAR LOS ||EPISODIOS|| DE ESA SERIE
            std::cout << "Especifique la Serie a seleccionar ingresando el ID:" << "\n";
            std::cin >> tecla;

            std::cout << base.mostrarEpisodiosPorNombre(base.nombreVideoPorID(tecla));


        } else if (tecla == 4) {
            // Elegir la calificación
            std::cout << "Especifique la calificación (Num del 1 al 5) de la película" << "\n";
            std::cin >> tecla;

            // MOSTRAR TODAS LAS ||PELÍCULAS|| CON ESA CALIFICACIÓN
            std::cout << base.mostrarPeliculaPorCalificacion(tecla);


        } else if (tecla == 5) {
            // Desplegar todos los videos.
            std::cout << base.mostrarVideos() << "\n";
            std::cout << "Seleccione el video ingresando el ID:" << "\n";

            // Elegir un video y cambiar la calificación por ID
            std::cin >> tecla;
            base.setCalificacionPorID(tecla);
        }
    }

    
}