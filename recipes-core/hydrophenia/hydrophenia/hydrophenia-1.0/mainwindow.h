#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fbaseform.h"
#include "fmainmenu.h"
#include "cserra.h"
#include "fpiante.h"
#include "fpianta.h"
#include "fserra.h"
#include "fvalues.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public fBaseForm
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showWND();
    void hideWND(){ };

public slots:
    void received_key_pressed(int keyid,fBaseForm * me);


private:
    Ui::MainWindow *ui;
    fMainMenu * f_mainmenu;
    fPiante * f_piante;
    fPianta * f_pianta;
    fSerra * f_serra;
    fVAlues * f_values;
    cSerra serra;
    void swap_wnd (fBaseForm * oldwnd , fBaseForm * newwnd);
};

#endif // MAINWINDOW_H
