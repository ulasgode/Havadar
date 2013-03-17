#ifndef CONTROLMODULE_H
#define CONTROLMODULE_H

#include <QWebFrame>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QStandardItemModel>

#include "databasemodule.h"
#include "diagnosemodule.h"
#include "communicationmodule.h"
#include "ui_controlmodule.h"
#include "structure/observer.h"

namespace Ui
{
    class ControlModule;
}

class ControlModule : public QMainWindow
{
    Q_OBJECT

private:
    // Interface attribute
    Ui::ControlModule * ui;

    // Module attributes
    DatabaseModule * _databaseModule;
    DiagnoseModule * _diagnoseModule;
    CommunicationModule * _communicationModule;

    // Model View attributes
    QStandardItemModel * _overallModelView;
    QStandardItemModel * _diagnoseModelView;

    // Timer attribute
    QTimer * _updateSensors;

    // Structure attributes
    QVector<Observer * > * _observerList;
    QVector<Edge * > * _edgeList;
    QVector<Node * > * _nodeList;

    // Observer attributes
    Observer * _overallView;
    Observer * _diagnoseView;

    // Other attributes
    int _selectedItem;

    void Attach(Observer * observer)
    {
        _observerList->push_back(observer);
    }

    void Detach(Observer * observer)
    {
        _observerList->remove(_observerList->indexOf(observer));
    }

    void Notify()
    {
        QVector<Observer *>::iterator observerIterator = _observerList->begin();
        Observer * observer = * observerIterator;

        while (observerIterator != _observerList->end()) {
            observer = * observerIterator;
            observer->Update();
            ++observerIterator;
        }

        delete observer;
    }

public:
    explicit ControlModule(QWidget *parent = 0) : QMainWindow(parent), ui(new Ui::ControlModule)
    {
        ui->setupUi(this);

        _observerList = new QVector<Observer *>();
        _edgeList = new QVector<Edge *>();
        _nodeList = new QVector<Node *>();

        _databaseModule = new DatabaseModule();
        _databaseModule->GetNodes(_nodeList);
        _databaseModule->GetEdges(_nodeList, _edgeList);

        _diagnoseModule = new DiagnoseModule();
        _communicationModule = new CommunicationModule(this);

        _overallView = new ObserverOverallView(_edgeList, _nodeList, ui->overallTableView, _overallModelView);
        _diagnoseView = new ObserverDiagnoseView(_diagnoseModule, _edgeList, _nodeList, ui->diagnoseTableView, _diagnoseModelView);

        Attach(_overallView);
        Attach(_diagnoseView);

        /* SILINECEK */
        _edgeList->at(5)->GetSensorCollection()->GetStaticSensorCollection()->at(3)->SetProblem(1);
        _edgeList->at(5)->GetSensorCollection()->GetStaticSensorCollection()->at(3)->SetValue(-5);

        _edgeList->at(18)->GetSensorCollection()->GetStaticSensorCollection()->at(2)->SetProblem(1);
        _edgeList->at(18)->GetSensorCollection()->GetStaticSensorCollection()->at(2)->SetValue(-5);

        _edgeList->at(32)->GetSensorCollection()->GetStaticSensorCollection()->at(4)->SetProblem(1);
        _edgeList->at(32)->GetSensorCollection()->GetStaticSensorCollection()->at(4)->SetValue(-5);
        /* SILINECEK */

        Notify();

        _updateSensors = new QTimer(this);
        _updateSensors->start(15000);

        connect(_updateSensors, SIGNAL(timeout()), this, SLOT(updateSensors()));
    }

    ~ControlModule()
    {
        delete ui;
    }

public slots:

    void updateSensors()
    {
        QVector<Edge * >::iterator iterator = _edgeList->begin();
        Edge * e1 = * iterator;

        while (iterator != _edgeList->end()) {
            e1 = * iterator;

            QVector<Sensor *>::iterator sensorIterator = e1->GetSensorCollection()->GetStaticSensorCollection()->begin();
            Sensor * sensor = * sensorIterator;

            while (sensorIterator != e1->GetSensorCollection()->GetStaticSensorCollection()->end()) {
                sensor = * sensorIterator;
                sensor->SetValue(qrand() % ((95 + 1) - 5) + 5);
                ++sensorIterator;
            }

            ++iterator;
        }

        if(_communicationModule->GetPackageList()->count() > 0) {

            QVector<QString>::Iterator packageIterator = _communicationModule->GetPackageList()->begin();
            QString message = * packageIterator;

            while(packageIterator != _communicationModule->GetPackageList()->end()) {

                message = * packageIterator;
                //qDebug() << "UPDATE EDILEN PAKET: " << message;

                QList<QString> list = message.split(QRegExp("#"));
                QList<QString>::Iterator iterator = list.begin();
                QString parseString = * iterator;

                QList<QString> list0 = parseString.split(QRegExp(","));
                // qDebug() << list0 << endl;

                // FIND EDGE DIYE BI FONKSIYON EKLENEBILIR....
                QVector<Edge *>::iterator iteratorED = _edgeList->begin();
                Edge * ec = * iteratorED;

                while (iteratorED != _edgeList->end()) {
                    ec = * iteratorED;
                    if(ec->GetNode() == list0.at(0).toInt() && ec->GetNeighbour() == list0.at(1).toInt()) {
                        break;
                    }
                    ++iteratorED;
                }

                ++iterator;

                while(iterator != list.end()) {
                    parseString = * iterator;
                    list0 = parseString.split(QRegExp(","));

                    Sensor * s1;
                    s1 = ec->GetSensorCollection()->GetDynamicSensorByID(list0.at(0).toInt());
                    s1->SetValue(list0.at(1).toDouble());

                    //qDebug() << list0 << endl;
                    ++iterator;
                }

                packageIterator++;

                delete ec;

           }

           _communicationModule->GetPackageList()->clear();

        }

        qDebug() << "-----------------update edildi-----------------";

        _databaseModule->SetEdges(_edgeList);
        Notify();

        //delete e1;
    }
};

#endif // CONTROLMODULE_H
