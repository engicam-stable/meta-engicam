#include "cserra.h"

cSerra::cSerra(QObject *parent) :
    QObject(parent)
{
    ill_start=QTime(18,20);
    ill_stop=QTime(5,20);
    portata_aria_estrattore=0;
    temperatura=25;
    umidita=70;
}
