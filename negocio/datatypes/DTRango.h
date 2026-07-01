#ifndef DTRANGO_H
#define DTRANGO_H

class DTRango {
private:
    float minimo;
    float maximo;
public:
    DTRango(float min, float max) {
        this->minimo = min;
        this->maximo = max;
    }

    float getMinimo() { return this->minimo; }
    float getMaximo() { return this->maximo; }
};

#endif