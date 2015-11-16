#ifndef FVALUES_H
#define FVALUES_H

#include <QWidget>
#include "fbaseform.h"
#include <QTimer>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QVector>

namespace Ui {
    class fVAlues;
}

class fVAlues : public fBaseForm {
    Q_OBJECT
public:
    fVAlues(QWidget *parent = 0);
    ~fVAlues();
    void showWND();
    void hideWND();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::fVAlues *ui;
    QTimer m_timer;
     double temp,humi;
     QwtPlotCurve *ctemp ;
     QwtPlotCurve *chumid;
     QVector<QPointF> * valoriT;
     QVector<QPointF> * valoriH;
     double xx;

private slots:
    void on_pushButton_clicked();
    void timer_tick();

};

#endif // FVALUES_H
