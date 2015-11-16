#ifndef FMAINMENU_H
#define FMAINMENU_H

#include <QWidget>
#include "fbaseform.h"

namespace Ui {
class fMainMenu;
}

class fMainMenu : public fBaseForm
{
    Q_OBJECT
    
public:
    explicit fMainMenu(QWidget *parent = 0);
    ~fMainMenu();
    void showWND();
    void hideWND();
    
private slots:
    void on_pbGrafico_clicked();
    void on_pbSerra_clicked();

    void on_pbVasche_clicked();

    void on_pbSettings_clicked();

private:
    Ui::fMainMenu *ui;
};

#endif // FMAINMENU_H
