#include "fserra.h"
#include "ui_fserra.h"

fSerra::fSerra(QWidget *parent) :
    fBaseForm(parent),
    ui(new Ui::fSerra)
{
    ui->setupUi(this);
}

fSerra::~fSerra()
{
    delete ui;
}

void fSerra::showWND()
{
    ui->horizontalSlider->setValue(this->mySerra->portata_aria_estrattore);
    temp10 = (int)(this->mySerra->temperatura /10);
    temp1= (int)(this->mySerra->temperatura % 10);
    umi10= (int)(this->mySerra->umidita /10);
    umi1= (int)(this->mySerra->umidita % 10);

    risem10=(int)(this->mySerra->ill_start.minute() /10);
    risem1 =(int)(this->mySerra->ill_start.minute() %10);

    riseh10=(int)(this->mySerra->ill_start.hour() /10);
    riseh1 =(int)(this->mySerra->ill_start.hour() %10);

    setm10=(int)(this->mySerra->ill_stop.minute() /10);
    setm1 =(int)(this->mySerra->ill_stop.minute() %10);

    seth10=(int)(this->mySerra->ill_stop.hour() /10);
    seth1 =(int)(this->mySerra->ill_stop.hour() %10);
    refresh_value();

    SHOW;
}

void fSerra::hideWND()
{
    this->mySerra->temperatura= temp10*10 + temp1;
    this->mySerra->umidita= umi10*10 + umi1;

    int rh,rm,sh,sm;

    rh = riseh10 *10 + riseh1;
    rm = risem10 * 10 + risem1;
    sh = seth10 *10 + seth1;
    sm = setm10 * 10 + setm1;

    this->mySerra->ill_start = QTime(rh,rm);
    this->mySerra->ill_stop = QTime(sh,sm);

    this->mySerra->portata_aria_estrattore = this->ui->horizontalSlider->value();

    this->hide();
}

void fSerra::refresh_value()
{
    ui->pbRiseH10->setText(QString::number(riseh10,10));
    ui->pbRiseH1->setText(QString::number(riseh1,10));

    ui->pbRiseM10->setText(QString::number(risem10,10));
    ui->pbRiseM1->setText(QString::number(risem1,10));

    ui->pbSetH10->setText(QString::number(seth10,10));
    ui->pbSetH1->setText(QString::number(seth1,10));

    ui->pbSetM10->setText(QString::number(setm10,10));
    ui->pbSetM1->setText(QString::number(setm1,10));

    ui->pbTemp10->setText(QString::number(temp10,10));
    ui->pbTemp1->setText(QString::number(temp1,10));

    ui->bpHU10->setText(QString::number(umi10,10));
    ui->bpHU1->setText(QString::number(umi1,10));
}

void fSerra::on_pbRiseH10P_clicked()
{
    this->riseh10++;
    if(riseh10 > 2) riseh10 =0;
    if(riseh10 < 0) riseh10 =2;
    refresh_value();
}


void fSerra::on_pbRiseH1P_clicked()
{
    this->riseh1++;
    if(riseh1 > 5) riseh1 =0;
    if(riseh1 < 0) riseh1 =5;
    refresh_value();
}


void fSerra::on_pbRiseH10M_clicked()
{
    this->riseh10--;
    if(riseh10 > 2) riseh10 =0;
    if(riseh10 < 0) riseh10 =2;
    refresh_value();
}


void fSerra::on_pbRiseH1M_clicked()
{
    this->riseh1--;
    if(riseh1 > 5) riseh1 =0;
    if(riseh1 < 0) riseh1 =5;
    refresh_value();
}

void fSerra::on_pbRiseM10P_clicked()
{
    this->risem10++;
    if(risem10 > 2) risem10 =0;
    if(risem10 < 0) risem10 =2;
    refresh_value();
}

void fSerra::on_pbRiseM1P_clicked()
{
    this->risem1++;
    if(risem1 > 5) risem1 =0;
    if(risem1 < 0) risem1 =5;
    refresh_value();
}

void fSerra::on_pbRiseM10M_clicked()
{
    this->risem10--;
    if(risem10 > 2) risem10 =0;
    if(risem10 < 0) risem10 =2;
    refresh_value();
}


void fSerra::on_pbRiseM1M_clicked()
{
    this->risem1--;
    if(risem1 > 5) risem1 =0;
    if(risem1 < 0) risem1 =5;
    refresh_value();
}


//***************************************************

void fSerra::on_pbSetH10P_clicked()
{
    this->seth10++;
    if(seth10 > 2) seth10 =0;
    if(seth10 < 0) seth10 =2;
    refresh_value();
}


void fSerra::on_pbSetH1P_clicked()
{
    this->seth1++;
    if(seth1 > 5) seth1 =0;
    if(seth1 < 0) seth1 =5;
    refresh_value();
}


void fSerra::on_pbSetH10M_clicked()
{
    this->seth10--;
    if(seth10 > 2) seth10 =0;
    if(seth10 < 0) seth10 =2;
    refresh_value();
}


void fSerra::on_pbSetH1M_clicked()
{
    this->seth1--;
    if(seth1 > 5) seth1 =0;
    if(seth1 < 0) seth1 =5;
    refresh_value();
}



void fSerra::on_pbSetM10P_clicked()
{
    this->setm10++;
    if(setm10 > 2) setm10 =0;
    if(setm10 < 0) setm10 =2;
    refresh_value();
}


void fSerra::on_pbSetM1P_clicked()
{
    this->setm1++;
    if(setm1 > 5) setm1 =0;
    if(setm1 < 0) setm1 =5;
    refresh_value();
}


void fSerra::on_pbSetM10M_clicked()
{
    this->seth10--;
    if(seth10 > 2) seth10 =0;
    if(seth10 < 0) seth10 =2;
    refresh_value();
}


void fSerra::on_pbSetM1M_clicked()
{
    this->seth1--;
    if(seth1 > 5) seth1 =0;
    if(seth1 < 0) seth1 =5;
    refresh_value();
}
//***************************************************

void fSerra::on_pbTemp10P_clicked()
{
    this->temp10++;
    if(temp10 > 2) temp10 =0;
    if(temp10 < 0) temp10 =2;
    refresh_value();
}


void fSerra::on_pbTemp1P_clicked()
{
    this->temp1++;
    if(temp1 > 9) temp1 =0;
    if(temp1 < 0) temp1 =9;
    refresh_value();
}


void fSerra::on_pbTemp10M_clicked()
{
    this->temp10--;
    if(temp10 > 2) temp10 =0;
    if(temp10 < 0) temp10 =2;
    refresh_value();
}


void fSerra::on_pbTemp1M_clicked()
{
    this->temp1--;
    if(temp1 > 9) temp1 =0;
    if(temp1 < 0) temp1 =9;
    refresh_value();
}

//***************************************************

void fSerra::on_bpHU10P_clicked()
{
    this->umi10++;
    if(umi10 > 9) umi10 =0;
    if(umi10 < 0) umi10 =9;
    refresh_value();
}


void fSerra::on_bpHU1P_clicked()
{
    this->umi1++;
    if(umi1 > 9) umi1 =0;
    if(umi1 < 0) umi1 =9;
    refresh_value();
}


void fSerra::on_bpHU10M_clicked()
{
    this->umi10--;
    if(umi10 > 2) umi10 =0;
    if(umi10 < 0) umi10 =2;
    refresh_value();
}


void fSerra::on_bpHU1M_clicked()
{
    this->umi1--;
    if(umi1 > 5) umi1 =0;
    if(umi1 < 0) umi1 =5;
    refresh_value();
}

void fSerra::on_pbHome_clicked()
{
    emit this->key_pressed(K_HOME,this);
}

void fSerra::on_pbBack_clicked()
{
    emit this->key_pressed(K_BACK,this);
}
