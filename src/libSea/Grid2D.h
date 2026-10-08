#ifndef BLATT6_GRID2D_H
#define BLATT6_GRID2D_H


#include <vector>
#include <functional>

#include "Coordinates.h"


namespace Sea {

    template<class T>
    class Grid2D {

    private:
        std::vector<std::vector<T>> grid;

    public:
        Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement);

        unsigned int sizeX() const;
        unsigned int sizeY() const;
        unsigned int size() const;

        T const & operator[](Coordinates const & coords) const;
        T & operator[](Coordinates const & coords);

        T const & operator()(unsigned int x, unsigned int y) const;
        T & operator()(unsigned int x, unsigned int y);

        void walk(std::function<void(T const &)> operation) const;

        std::vector<T> filter(std::function<bool(T const &)> condition) const;

    };

}


#include "Grid2D.inl"


#endif //BLATT6_GRID2D_H
