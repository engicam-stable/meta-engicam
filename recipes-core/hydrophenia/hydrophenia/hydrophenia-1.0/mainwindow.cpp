#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    fBaseForm(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    this->hide();

    f_mainmenu = new fMainMenu();

    f_mainmenu->showWND();
    f_mainmenu->registerWNH(this,&serra);

    f_piante = new fPiante();
    f_piante->registerWNH(this,&serra);

    f_pianta = new fPianta();
    f_pianta->registerWNH(this,&serra);

    f_serra = new fSerra();
    f_serra->registerWNH(this,&serra);

    f_values = new fVAlues();
    f_values->registerWNH(this,&serra);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showWND()
{
    this->show();
}

void MainWindow::received_key_pressed(int keyid, fBaseForm *me)
{

    if(me==this->f_serra)
    {
        switch(keyid)
        {
            case K_BACK:
            case K_HOME:
                swap_wnd(me,this->f_mainmenu);
            break;
        }
    }

    if(me==this->f_mainmenu)
    {
        switch(keyid)
        {
            case K_HOME:

            break;

            case K_SERRA:                
                 swap_wnd(me,this->f_serra);
            break;

            case K_VASCHE:
                swap_wnd(me,this->f_piante);
            break;

            case K_SETTINGS:
                qDebug() << "vasche pressed";
            break;

            case K_REALTIME:
                swap_wnd(me,this->f_values);
            break;
        }
    }

    if(me==this->f_piante)
    {
        switch(keyid)
        {
            case K_HOME:
                swap_wnd(me,this->f_mainmenu);
            break;

            case K_SETTINGS:
                qDebug() << "vasche pressed";
            break;

            default:
                this->f_pianta->setPianta(keyid);
                swap_wnd(me,this->f_pianta);
            break;
        }
    }



    if(me==this->f_values)
    {

        swap_wnd(me,this->f_mainmenu);
    }

    if(me==this->f_pianta)
    {
        switch(keyid)
        {
            case K_HOME:
                swap_wnd(me,this->f_mainmenu);
            break;

            case K_SETTINGS:
                qDebug() << "vasche pressed";
            break;

            case K_BACK:
                swap_wnd(me,this->f_piante);
            break;
        }
    }
}

void MainWindow::swap_wnd(fBaseForm *oldwnd, fBaseForm *newwnd)
{
    newwnd->showWND();
    QCoreApplication::processEvents();
    oldwnd->hideWND();
}
