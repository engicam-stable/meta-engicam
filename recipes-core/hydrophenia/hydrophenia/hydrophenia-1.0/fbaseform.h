#ifndef FBASEFORM_H
#define FBASEFORM_H

#include <QWidget>
#include <cserra.h>
#include <QDateTime>
#include <QTimer>
#include "keycode.h"
namespace Ui {
class fBaseForm;
}

class fBaseForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit fBaseForm(QWidget *parent = 0);
    virtual void showWND()=0;
    virtual void hideWND()=0;
    void registerWNH(fBaseForm * father,cSerra * serra);
    ~fBaseForm();

    cSerra * mySerra;


public slots:
     void received_key_pressed(int keyid,fBaseForm * me);
     void timer_tick();

    signals:
        void key_pressed(int keyid,fBaseForm * me);

private:
    Ui::fBaseForm *ui;
    QTimer m_timer;
};

#endif // FBASEFORM_H
