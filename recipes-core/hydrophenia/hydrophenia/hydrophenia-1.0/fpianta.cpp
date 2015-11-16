#include "fpianta.h"
#include "ui_fpianta.h"

fPianta::fPianta(QWidget *parent) :
    fBaseForm(parent),
    ui(new Ui::fPianta)
{
    ui->setupUi(this);
}

fPianta::~fPianta()
{
    delete ui;
}

void fPianta::showWND()
{
    ph10 =(int)( vasca->pH / 10);
    ph1 = (int)(vasca->pH % 10);
    ec10 = (int)(vasca->EC / 10);
    ec1 = (int)(vasca->EC % 10);

    a100 =(int)( vasca->grammi[0] /100);
    a10 =(int)( (vasca->grammi[0] %100) / 10);
    a1 = (int)(vasca->grammi[0] % 10);

    b100 = (int)(vasca->grammi[1] /100);
    b10 = (int)((vasca->grammi[1] %100) / 10);
    b1 = (int)(vasca->grammi[1] % 10);

    c100 = (int)(vasca->grammi[2] /100);
    c10 =(int)( (vasca->grammi[2] %100) / 10);
    c1 = (int)(vasca->grammi[2] % 10);

    h10 = (int)(vasca->tempo_ricambio.hour() / 10);
    h1 = (int)(vasca->tempo_ricambio.hour() % 10);

    m10 =(int)( vasca->tempo_ricambio.minute() / 10);
    m1 = (int)(vasca->tempo_ricambio.minute() % 10);
    refresh_value();
    SHOW;
}

void fPianta::hideWND()
{
    this->hide();
}

void fPianta::setPianta(int pianta)
{
    switch(pianta)
    {
        case K_FRAGOLE:
            ui->main_widget->setStyleSheet("image: url(:/img/img/vasca_fragole.png);");
            vasca = &this->mySerra->vasca[0];
        break;

        case K_MIRTILLI:
            ui->main_widget->setStyleSheet("image: url(:/img/img/vasca_mirtilli.png);");
            vasca = &this->mySerra->vasca[1];
        break;

        case K_UVA:
            ui->main_widget->setStyleSheet("image: url(:/img/img/vasca_uva.png);");
            vasca = &this->mySerra->vasca[2];
        break;

        case K_POMODORI:
            ui->main_widget->setStyleSheet("image: url(:/img/img/vasca_pomodori.png);");
            vasca = &this->mySerra->vasca[3];
        break;
    }
}

void fPianta::on_pbHome_clicked()
{
    emit this->key_pressed(K_HOME ,this);
}

void fPianta::on_pbSetting_clicked()
{
    emit this->key_pressed(K_SETTINGS ,this);
}

void fPianta::on_pbBack_clicked()
{
    emit this->key_pressed(K_BACK ,this);
}


void fPianta::refresh_value()
{
    this->ui->PH10->setText(QString::number(this->ph10,10));
    this->ui->PH1->setText(QString::number(this->ph1,10));

    vasca->pH=this->ph10 * 10 +this->ph1;

    this->ui->Ec10->setText(QString::number(this->ec10,10));
    this->ui->EC1->setText(QString::number(this->ec1,10));

    vasca->EC=this->ec10 * 10 +this->ec1;

    this->ui->A100->setText(QString::number(this->a100,10));
    this->ui->A10->setText(QString::number(this->a10,10));
    this->ui->A1->setText(QString::number(this->a1,10));

    vasca->grammi[0]=this->a100 * 100 +  this->a10 * 10 +this->a1;

    this->ui->B100->setText(QString::number(this->b100,10));
    this->ui->B10->setText(QString::number(this->b10,10));
    this->ui->B1->setText(QString::number(this->b1,10));

    vasca->grammi[1]=this->b100 * 100 +  this->b10 * 10 +this->b1;

    this->ui->C100->setText(QString::number(this->c100,10));
    this->ui->C10->setText(QString::number(this->c10,10));
    this->ui->C1->setText(QString::number(this->c1,10));

    vasca->grammi[2]=this->c100 * 100 +  this->c10 * 10 +this->c1;

    this->ui->H10->setText(QString::number(this->h10,10));
    this->ui->H1->setText(QString::number(this->h1,10));

    this->ui->M10->setText(QString::number(this->m10,10));
    this->ui->M1->setText(QString::number(this->m1,10));


    int h_val= this->h10 * 10 + this->h1;
    int m_val= this->m10 * 10 + this->m1;

    if((h_val > 23) || (h_val<0)) h_val =2;
    if((m_val > 59) || (m_val<0)) m_val =30;

    vasca->tempo_ricambio=QTime(h_val,m_val);
}


void fPianta::on_PH10P_clicked()
{
    this->ph10++;
    if(ph10 > 9) ph10 =0;
    if(ph10 < 0) ph10 =9;
    refresh_value();
}

void fPianta::on_PH1P_clicked()
{
    this->ph1++;
    if(ph1 > 9) ph1 =0;
    if(ph1 < 0) ph1 =9;
    refresh_value();
}

void fPianta::on_PH10M_clicked()
{
    this->ph10--;
    if(ph10 > 1) ph10 =0;
    if(ph10 < 0) ph10 =1;
    refresh_value();
}

void fPianta::on_PH1M_clicked()
{
    this->ph1--;
    if(ph1 > 9) ph1 =0;
    if(ph1 < 0) ph1 =9;
    refresh_value();
}

void fPianta::on_H10P_clicked()
{
    this->h10++;
    if(h10 > 9) h10 =0;
    if(h10 < 0) h10 =9;
    refresh_value();
}

void fPianta::on_H10M_clicked()
{
    this->h1++;
    if(h1 > 9) h1 =0;
    if(h1< 0) h1 =9;
    refresh_value();
}

void fPianta::on_H10M_2_clicked()
{
    this->h10--;
    if(h10 > 2) h10 =0;
    if(h10 < 0) h10 =2;
    refresh_value();
}

void fPianta::on_H1M_clicked()
{
    this->h1--;
    if(h1 > 5) h1 =0;
    if(h1 < 0) h1 =5;
    refresh_value();
}

void fPianta::on_M10P_clicked()
{
    this->m10++;
    if(m10 > 5) m10 =0;
    if(m10 < 0) m10 =5;
    refresh_value();
}

void fPianta::on_M1P_clicked()
{
    this->m1++;
    if(m1 > 9) m1 =0;
    if(m1< 0) m1 =9;
    refresh_value();
}

void fPianta::on_M10M_clicked()
{
    this->m10--;
    if(m10 > 5) m10 =0;
    if(m10 < 0) m10 =5;
    refresh_value();
}

void fPianta::on_M1M_clicked()
{
    this->m1--;
    if(m1 > 9) m1 =0;
    if(m1 < 0) m1 =9;
    refresh_value();
}

void fPianta::on_EC10P_clicked()
{
    this->ec10++;
    if(ec10 > 9) ec10 =0;
    if(ec10 < 0) ec10 =9;
    refresh_value();
}

void fPianta::on_EC1P_clicked()
{
    this->ec1++;
    if(ec1 > 9) ec1 =0;
    if(ec1 < 0) ec1 =9;
    refresh_value();
}

void fPianta::on_EC10M_clicked()
{
    this->ec10--;
    if(ec10 > 1) ec10 =0;
    if(ec10 < 0) ec10 =1;
    refresh_value();
}

void fPianta::on_EC1M_clicked()
{
    this->ec1--;
    if(ec1 > 9) ec1 =0;
    if(ec1 < 0) ec1 =9;
    refresh_value();
}

void fPianta::on_A100P_clicked()
{
    this->a100++;
    if(a100 > 1) a100 =0;
    if(a100 < 0) a100 =1;
    refresh_value();
}

void fPianta::on_B100P_clicked()
{
    this->b100++;
    if(b100 > 1) b100 =0;
    if(b100 < 0) b100 =1;
    refresh_value();
}
void fPianta::on_C100P_clicked()
{
    this->c100++;
    if(c100 > 1) c100 =0;
    if(c100 < 0) c100 =1;
    refresh_value();
}

void fPianta::on_A10P_clicked()
{
    this->a10++;
    if(a10 > 9) a10 =0;
    if(a10 < 0) a10 =9;
    refresh_value();
}


void fPianta::on_B10P_clicked()
{
    this->b10++;
    if(b10 > 9) b10 =0;
    if(b10 < 0) b10 =9;
    refresh_value();
}


void fPianta::on_C10P_clicked()
{
    this->c10++;
    if(c10 > 9) c10 =0;
    if(c10 < 0) c10 =9;
    refresh_value();
}

void fPianta::on_A1P_clicked()
{
    this->a1++;
    if(a1 > 9) a1 =0;
    if(a1 < 0) a1 =9;
    refresh_value();
}

void fPianta::on_B1P_clicked()
{
    this->b1++;
    if(b1 > 9) b1 =0;
    if(b1 < 0) b1 =9;
    refresh_value();
}

void fPianta::on_C1P_clicked()
{
    this->c1++;
    if(c1 > 9) c1 =0;
    if(c1 < 0) c1 =9;
    refresh_value();
}



void fPianta::on_A100M_clicked()
{
    this->a100--;
    if(a100 > 1) a100 =0;
    if(a100 < 0) a100 =1;
    refresh_value();
}

void fPianta::on_B100M_clicked()
{
    this->b100--;
    if(b100 > 1) b100 =0;
    if(b100 < 0) b100 =1;
    refresh_value();
}
void fPianta::on_C100M_clicked()
{
    this->c100--;
    if(c100 > 1) c100 =0;
    if(c100 < 0) c100 =1;
    refresh_value();
}

void fPianta::on_A10M_clicked()
{
    this->a10--;
    if(a10 > 9) a10 =0;
    if(a10 < 0) a10 =9;
    refresh_value();
}


void fPianta::on_B10M_clicked()
{
    this->b10--;
    if(b10 > 9) b10 =0;
    if(b10 < 0) b10 =9;
    refresh_value();
}


void fPianta::on_C10M_clicked()
{
    this->c10--;
    if(c10 > 9) c10 =0;
    if(c10 < 0) c10 =9;
    refresh_value();
}

void fPianta::on_A1M_clicked()
{
    this->a1--;
    if(a1 > 9) a1 =0;
    if(a1 < 0) a1 =9;
    refresh_value();
}

void fPianta::on_B1M_clicked()
{
    this->b1--;
    if(b1 > 9) b1 =0;
    if(b1 < 0) b1 =9;
    refresh_value();
}

void fPianta::on_C1M_clicked()
{
    this->c1--;
    if(c1 > 9) c1 =0;
    if(c1 < 0) c1 =9;
    refresh_value();
}


