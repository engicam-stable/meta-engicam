#ifndef FSERRA_H
#define FSERRA_H

#include <QWidget>
#include "fbaseform.h"
namespace Ui {
class fSerra;
}

class fSerra : public fBaseForm
{
    Q_OBJECT
    
public:
    explicit fSerra(QWidget *parent = 0);
    ~fSerra();
    void showWND();
    void hideWND();

    
private slots:
    void  on_pbRiseH10P_clicked() ;
    void  on_pbRiseH1P_clicked() ;
    void  on_pbRiseH10M_clicked() ;
    void  on_pbRiseH1M_clicked() ;
    void  on_pbRiseM10P_clicked() ;
    void  on_pbRiseM1P_clicked() ;

    void  on_pbRiseM10M_clicked() ;
    void  on_pbRiseM1M_clicked() ;
    void  on_pbSetH10P_clicked() ;
    void  on_pbSetH1P_clicked() ;
    void  on_pbSetH10M_clicked() ;
    void  on_pbSetH1M_clicked() ;

    void  on_pbSetM10P_clicked() ;

    void  on_pbSetM1P_clicked() ;
    void  on_pbSetM10M_clicked() ;

    void  on_pbSetM1M_clicked() ;
    void  on_pbTemp10P_clicked() ;


    void  on_pbTemp1P_clicked() ;

    void  on_pbTemp10M_clicked() ;

    void  on_pbTemp1M_clicked() ;
    void  on_bpHU10P_clicked() ;


    void  on_bpHU1P_clicked() ;


    void  on_bpHU10M_clicked() ;


    void  on_bpHU1M_clicked();

    void on_pbHome_clicked();

    void on_pbBack_clicked();

private:
    Ui::fSerra *ui;
    int temp10,temp1,umi10,umi1,riseh10,riseh1,risem10,risem1,seth10,seth1,setm10,setm1;
    void refresh_value();
};

#endif // FSERRA_H
