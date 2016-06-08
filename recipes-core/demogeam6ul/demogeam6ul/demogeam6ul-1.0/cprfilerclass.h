#ifndef CPRFILERCLASS_H
#define CPRFILERCLASS_H

#include <QThread>
#include <QMutex>

class cPrfilerClass : public QThread
{
    Q_OBJECT
public:
    explicit cPrfilerClass(QObject *parent = 0);
    Q_INVOKABLE QString cpuPercentage();
    void run();
    Q_INVOKABLE QString getMemFree();
    Q_INVOKABLE QString vMEMVAlue();
    Q_INVOKABLE QString getCpuModel() { return _cpuType; }
    Q_INVOKABLE QString getMemTotal() { return _memTotal; }
    Q_INVOKABLE QString getQtVersion() { return qVersion(); }
signals:

private:
    int getVMValue();
    int parseLine(char *line);
    void recoverCpuInfo();
    void recoverMemTotal();
    QString findInfo(const QString &ref, const QString &filename);

public slots:

private:
    double m_percent;
    int m_VM;
    bool running;
    QMutex mMutex;
    QString _cpuType = "unknown";
    QString _memTotal = "unknown";
};

#endif // CPRFILERCLASS_H
