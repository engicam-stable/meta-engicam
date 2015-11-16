#include "fvalues.h"
#include "ui_fvalues.h"
#include <QTime>
fVAlues::fVAlues(QWidget *parent) :
    fBaseForm(parent),
    ui(new Ui::fVAlues)
{
    ui->setupUi(this);
    connect(&this->m_timer,SIGNAL(timeout()),this,SLOT(timer_tick()));
    temp=20;
    humi=50;
    ui->thHum->setValue(humi);
    ui->thTemp->setValue(temp);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,100);
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,100);

    valoriT = new  QVector<QPointF>(110);
    valoriH = new  QVector<QPointF>(110);

    ctemp = new QwtPlotCurve("Temp");
    chumid= new QwtPlotCurve("Humid");

    ctemp->attach(ui->qwtPlot);
    chumid->attach(ui->qwtPlot);
    ctemp->setPen(QPen(Qt::blue));
    chumid->setPen(QPen(Qt::black));
    xx=0.0;
}

fVAlues::~fVAlues()
{
    delete ui;
}

void fVAlues::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void  fVAlues::showWND()
{
    SHOW;
    this->m_timer.start(1000);
}

void  fVAlues::hideWND()
{
   this->m_timer.stop();
    this->hide();
}

void fVAlues::on_pushButton_clicked()
{
    emit this->key_pressed(K_BACK,this);
}


void fVAlues::timer_tick()
{
    int high=1;
    int low =-1;
    humi +=  qrand()  % ((high + 1) - low) + low; ;
    temp +=  qrand()  % ((high + 1) - low) + low;;

    ui->thHum->setValue(humi);
    ui->thTemp->setValue(temp);

    valoriT->append(QPointF(xx,temp));
    valoriH->append(QPointF(xx,humi));

    xx+=1;
    if(valoriH->count() > 100)
    {
        valoriH->clear();
        valoriT->clear();
        xx=0;
    }

    ctemp->setSamples(*valoriT);
    chumid->setSamples(*valoriH);

    ui->qwtPlot->replot();
}
