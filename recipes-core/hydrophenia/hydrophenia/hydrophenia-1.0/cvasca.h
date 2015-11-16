#ifndef CVASCA_H
#define CVASCA_H
#include <QTime>

class cVasca
{
public:
    cVasca();

    int pH;
    int EC;
    int grammi[3];
    QTime tempo_ricambio;
};

#endif // CVASCA_H
