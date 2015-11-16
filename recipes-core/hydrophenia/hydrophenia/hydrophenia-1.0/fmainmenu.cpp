#include "fmainmenu.h"
#include "ui_fmainmenu.h"

fMainMenu::fMainMenu(QWidget *parent) :
    fBaseForm(parent),
    ui(new Ui::fMainMenu)
{
    ui->setupUi(this);
}

fMainMenu::~fMainMenu()
{
    delete ui;
}

void fMainMenu::showWND()
{
    SHOW;
}

void fMainMenu::hideWND()
{
    this->hide();
}

void fMainMenu::on_pbSerra_clicked()
{
    emit this->key_pressed(K_SERRA,this);
}

void fMainMenu::on_pbVasche_clicked()
{
    emit this->key_pressed(K_VASCHE,this);
}

void fMainMenu::on_pbSettings_clicked()
{
    emit this->key_pressed(K_SETTINGS,this);

}

void fMainMenu::on_pbGrafico_clicked()
{
    emit this->key_pressed(K_REALTIME,this);

}
