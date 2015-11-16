#ifndef CSERRA_H
#define CSERRA_H

#include <QObject>
#include <QTime>
#include "cvasca.h"

class cSerra : public QObject
{
    Q_OBJECT
public:
    explicit cSerra(QObject *parent = 0);
    
    QTime ill_start;
    QTime ill_stop;
    int portata_aria_estrattore;
    int temperatura;
    int umidita;

    cVasca vasca[4];


signals:
    
public slots:
    
};

#endif // CSERRA_H
