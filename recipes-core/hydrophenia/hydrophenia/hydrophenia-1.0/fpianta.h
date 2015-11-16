#ifndef FPIANTA_H
#define FPIANTA_H

#include <QWidget>
#include "fbaseform.h"
#include "cvasca.h"
namespace Ui {
class fPianta;
}

class fPianta : public fBaseForm
{
    Q_OBJECT
    
public:
    explicit fPianta(QWidget *parent = 0);
    ~fPianta();
    void showWND();
    void hideWND();
    void setPianta(int pianta);   
    
private slots:
    void on_pbHome_clicked();

    void on_pbSetting_clicked();

    void on_pbBack_clicked();

    void on_PH10P_clicked();

    void on_PH1P_clicked();

    void on_PH10M_clicked();

    void on_PH1M_clicked();

    void on_H10P_clicked();

    void on_H10M_clicked();

    void on_H10M_2_clicked();

    void on_H1M_clicked();

    void on_M10P_clicked();

    void on_M1P_clicked();

    void on_M10M_clicked();

    void on_M1M_clicked();

    void on_EC10P_clicked();

    void on_EC1P_clicked();

    void on_EC10M_clicked();

    void on_EC1M_clicked();

    void on_A100P_clicked();

    void on_A10P_clicked();

    void on_A1P_clicked();

    void on_B100P_clicked();

    void on_B10P_clicked();

    void on_B1P_clicked();

    void on_C100P_clicked();

    void on_C10P_clicked();

    void on_C1P_clicked();


    void on_A100M_clicked();

    void on_A10M_clicked();

    void on_A1M_clicked();

    void on_B100M_clicked();

    void on_B10M_clicked();

    void on_B1M_clicked();

    void on_C100M_clicked();

    void on_C10M_clicked();

    void on_C1M_clicked();



private:
    Ui::fPianta *ui;
    void refresh_value();
    int ph10,ph1,h10,h1,m10,m1,ec10,ec1,a100,a10,a1,b100,b10,b1,c100,c10,c1;
    cVasca * vasca;
};

#endif // FPIANTA_H
