
class Grid2DInvalidSizeException : public std::exception {
private:
    const char * what() const noexcept override { return "sizeX and sizeY must both be > 0"; }
};

template<class T>
Sea::Grid2D<T>::Grid2D(unsigned int sizeX, unsigned int sizeY, T const & initElement)
: grid(sizeY, std::vector<T>(sizeX, initElement))
{
    if (sizeX == 0 || sizeY == 0) {
        throw Grid2DInvalidSizeException();
    }
}

template<class T>
unsigned int Sea::Grid2D<T>::sizeX() const
{
    return static_cast<unsigned int>(grid[0].size());
}

template<class T>
unsigned int Sea::Grid2D<T>::sizeY() const
{
    return static_cast<unsigned int>(grid.size());
}

template<class T>
unsigned int Sea::Grid2D<T>::size() const
{
    return sizeX() * sizeY();
}

template<class T>
T const & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coords) const
{
    return grid.at(coords.getY()).at(coords.getX());
}

template<class T>
T & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coords)
{
    return grid.at(coords.getY()).at(coords.getX());
}

template<class T>
T const & Sea::Grid2D<T>::operator()(unsigned int x, unsigned int y) const
{
    return grid.at(y).at(x);
}

template<class T>
T & Sea::Grid2D<T>::operator()(unsigned int x, unsigned int y)
{
    return grid.at(y).at(x);
}

template<class T>
void Sea::Grid2D<T>::walk(std::function<void(T const &)> operation) const
{
    for (unsigned int y = 0; y < sizeY(); ++y) {
        for (unsigned int x = 0; x < sizeX(); ++x) {
            operation((*this)(x, y));
        }
    }
}

template<class T>
std::vector<T> Sea::Grid2D<T>::filter(std::function<bool(T const &)> condition) const
{
    std::vector<T> result;

    for (unsigned int y = 0; y < sizeY(); ++y) {
        for (unsigned int x = 0; x < sizeX(); ++x) {
            T const & element = (*this)(x, y);

            if (condition(element)) {
                result.push_back(element);
            }
        }
    }

    return result;
}
