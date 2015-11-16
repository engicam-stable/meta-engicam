#ifndef FPIANTE_H
#define FPIANTE_H

#include <QWidget>
#include "fbaseform.h"
namespace Ui {
class fPiante;
}

class fPiante : public fBaseForm
{
    Q_OBJECT
    
public:
    explicit fPiante(QWidget *parent = 0);
    ~fPiante();
    void showWND();
    void hideWND();
    
private slots:
    void on_pbFragole_clicked();

    void on_pbMirtilli_clicked();

    void on_pbUva_clicked();

    void on_pbPomodori_clicked();

    void on_pbSetup_clicked();

    void on_pbHome_clicked();

private:
    Ui::fPiante *ui;
};

#endif // FPIANTE_H
