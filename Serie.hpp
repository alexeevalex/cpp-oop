#pragma once
#include "Video.hpp"

class Serie:public Video {
    private:

    public:
        Serie();
        Serie(int, std::string, int, std::string, double);

        int mostrarCalificacion() override;
};