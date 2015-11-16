#include "fbaseform.h"
#include "ui_fbaseform.h"

fBaseForm::fBaseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fBaseForm)
{
    ui->setupUi(this);
    void timer_tick();
    connect(&this->m_timer,SIGNAL(timeout()),this,SLOT(timer_tick()));
   // m_timer.start(1000);
}

fBaseForm::~fBaseForm()
{
    delete ui;
}

void fBaseForm::received_key_pressed(int keyid, fBaseForm *me)
{

}



void fBaseForm::registerWNH(fBaseForm *father, cSerra *serra)
{
    this->mySerra=serra;
    connect(this,SIGNAL(key_pressed(int,fBaseForm*)),father,SLOT(received_key_pressed(int,fBaseForm*)));
}


void fBaseForm::timer_tick()
{
    ui->lOra->setText(QDateTime::currentDateTime().toString());
}
