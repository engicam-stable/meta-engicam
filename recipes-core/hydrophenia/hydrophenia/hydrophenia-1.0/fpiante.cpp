#include "fpiante.h"
#include "ui_fpiante.h"

fPiante::fPiante(QWidget *parent) :
    fBaseForm(parent),
    ui(new Ui::fPiante)
{
    ui->setupUi(this);
}

fPiante::~fPiante()
{
    delete ui;
}

void fPiante::showWND()
{
    SHOW;
}

void fPiante::hideWND()
{
    this->hide();
}

void fPiante::on_pbFragole_clicked()
{
    emit this->key_pressed(K_FRAGOLE,this);
}

void fPiante::on_pbMirtilli_clicked()
{
    emit this->key_pressed(K_MIRTILLI,this);
}

void fPiante::on_pbUva_clicked()
{
    emit this->key_pressed(K_UVA,this);
}

void fPiante::on_pbPomodori_clicked()
{
    emit this->key_pressed(K_POMODORI,this);
}

void fPiante::on_pbSetup_clicked()
{
    emit this->key_pressed(K_SETTINGS,this);
}

void fPiante::on_pbHome_clicked()
{
    emit this->key_pressed(K_HOME,this);
}
