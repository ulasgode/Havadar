#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
public:
    virtual ~Observer() {}
    virtual void Update() = 0;
    virtual void SetColor(QStandardItemModel * model, int x, int y, float value)
    {
        if(y >= 2) {

            QModelIndex position(model->index(x, y));
            model->setData(position, value, Qt::EditRole);

            if(value >= 0 && value < 25) {
                model->setData(position, Qt::cyan   , Qt::BackgroundRole);
            } else if(value >= 25 && value < 50) {
                model->setData(position, Qt::green  , Qt::BackgroundRole);
            } else if(value >= 50 && value < 75) {
                model->setData(position, Qt::yellow , Qt::BackgroundRole);
            } else if(value >= 75 && value <= 100) {
                model->setData(position, Qt::red    , Qt::BackgroundRole);
            } else {
                // YAZIYI GÖSTERME!!!
                model->setData(position, Qt::black  , Qt::BackgroundRole);
            }
        }
    }
};

class ObserverOverallView : public Observer
{
public:
    ObserverOverallView(QVector<Edge * > * edgeList, QVector<Node * > * nodeList, QTableView * tableView, QStandardItemModel * modelView)
        : _edgeList(edgeList), _nodeList(nodeList), _tableView(tableView), _modelView(modelView) {

        _modelView = new QStandardItemModel(_tableView);
            _modelView->setHorizontalHeaderItem(0, new QStandardItem(QString("Node A")));
            _modelView->setHorizontalHeaderItem(1, new QStandardItem(QString("Node B")));

            _modelView->setHorizontalHeaderItem(2, new QStandardItem(QString("Types")));
            _modelView->setHorizontalHeaderItem(3, new QStandardItem(QString("Throughput")));
            _modelView->setHorizontalHeaderItem(4, new QStandardItem(QString("Average Sp.")));
            _modelView->setHorizontalHeaderItem(5, new QStandardItem(QString("Slipperiness")));
            _modelView->setHorizontalHeaderItem(6, new QStandardItem(QString("Weather C.")));
            _modelView->setHorizontalHeaderItem(7, new QStandardItem(QString("Illumination")));
            _modelView->setHorizontalHeaderItem(8, new QStandardItem(QString("OVERALL")));

            _modelView->setHorizontalHeaderItem(9, new QStandardItem(QString("Types")));
            _modelView->setHorizontalHeaderItem(10, new QStandardItem(QString("Throughput")));
            _modelView->setHorizontalHeaderItem(11, new QStandardItem(QString("Average Sp.")));
            _modelView->setHorizontalHeaderItem(12, new QStandardItem(QString("Slipperiness")));
            _modelView->setHorizontalHeaderItem(13, new QStandardItem(QString("Weather C.")));
            _modelView->setHorizontalHeaderItem(14, new QStandardItem(QString("Illumination")));
            _modelView->setHorizontalHeaderItem(15, new QStandardItem(QString("OVERALL")));
        _tableView->setModel(_modelView);
    }

    void Update()
    {
            QVector<Edge * >::iterator iterator = _edgeList->begin();
            Edge * e1 = * iterator;
            int x = 0;

            while (iterator != _edgeList->end()) {
                e1 = * iterator;

                _modelView->setItem(x, 0, new QStandardItem(QString("%1").arg(_nodeList->at(e1->GetNode())->GetName())));
                _modelView->setItem(x, 1, new QStandardItem(QString("%1").arg(_nodeList->at(e1->GetNeighbour())->GetName())));

                _modelView->setItem(x, 2, new QStandardItem("STATIC SENSORS"));
                // FOR STATICS
                    SetColor(_modelView, x, 3, e1->GetSensorCollection()->GetStaticSensorCollection()->at(0)->GetValue());
                    SetColor(_modelView, x, 4, e1->GetSensorCollection()->GetStaticSensorCollection()->at(1)->GetValue());
                    SetColor(_modelView, x, 5, e1->GetSensorCollection()->GetStaticSensorCollection()->at(2)->GetValue());
                    SetColor(_modelView, x, 6, e1->GetSensorCollection()->GetStaticSensorCollection()->at(3)->GetValue());
                    SetColor(_modelView, x, 7, e1->GetSensorCollection()->GetStaticSensorCollection()->at(4)->GetValue());
                    SetColor(_modelView, x, 8, e1->GetSensorCollection()->GetStaticSensorCollectionWeight());
                //++x;

                _modelView->setItem(x, 9, new QStandardItem("DYNAMIC SENSORS"));
                // FOR DYNAMICS
                    SetColor(_modelView, x, 10, e1->GetSensorCollection()->GetDynamicSensorCollection()->at(0)->GetValue());
                    SetColor(_modelView, x, 11, e1->GetSensorCollection()->GetDynamicSensorCollection()->at(1)->GetValue());
                    SetColor(_modelView, x, 12, e1->GetSensorCollection()->GetDynamicSensorCollection()->at(2)->GetValue());
                    SetColor(_modelView, x, 13, e1->GetSensorCollection()->GetDynamicSensorCollection()->at(3)->GetValue());
                    SetColor(_modelView, x, 14, e1->GetSensorCollection()->GetDynamicSensorCollection()->at(4)->GetValue());
                    SetColor(_modelView, x, 15, e1->GetSensorCollection()->GetDynamicSensorCollectionWeight());
                ++x;

                //qDebug() << e1->GetStaticSensorCollection()->at(0)->GetValue() << " --------------- " << e1->GetDynamicSensorCollection()->at(0)->GetValue();

                ++iterator;
            }
    }

private:
    QVector<Edge * > * _edgeList;
    QVector<Node * > * _nodeList;
    QTableView * _tableView;
    QStandardItemModel * _modelView;
};






class ObserverDiagnoseView : public Observer
{
public:
    ObserverDiagnoseView(DiagnoseModule * diagnoseModule, QVector<Edge * > * edgeList, QVector<Node * > * nodeList, QTableView * tableView, QStandardItemModel * modelView)
        : _diagnoseModule(diagnoseModule), _edgeList(edgeList), _nodeList(nodeList), _tableView(tableView), _modelView(modelView) {

        _modelView = new QStandardItemModel(_tableView);
            _modelView->setHorizontalHeaderItem(0, new QStandardItem(QString("Node A")));
            _modelView->setHorizontalHeaderItem(1, new QStandardItem(QString("Node B")));
            _modelView->setHorizontalHeaderItem(2, new QStandardItem(QString("Name")));
            _modelView->setHorizontalHeaderItem(3, new QStandardItem(QString("value")));
            _modelView->setHorizontalHeaderItem(4, new QStandardItem(QString("problem")));
        _tableView->setModel(_modelView);
    }

    void Update()
    {
        _diagnoseModule->CheckStaticSensorsOnTheEdges(_edgeList);

        QVector<ProblematicSensor *>::iterator iterator = _diagnoseModule->GetStaticProblematicSensorCollection()->begin();
        ProblematicSensor * ps = * iterator;
        int y = 0;

        while (iterator != _diagnoseModule->GetStaticProblematicSensorCollection()->end()) {
            ps = * iterator;
            _modelView->setItem(y, 0, new QStandardItem(QString("%1").arg(_nodeList->at(ps->GetNode())->GetName())));
            _modelView->setItem(y, 1, new QStandardItem(QString("%1").arg(_nodeList->at(ps->GetNeighbour())->GetName())));
            _modelView->setItem(y, 2, new QStandardItem(QString("%1").arg(ps->GetProblematicSensor()->GetID())));
            SetColor(_modelView, y, 3, ps->GetProblematicSensor()->GetValue());
            SetColor(_modelView, y, 4, ps->GetProblematicSensor()->GetProblem());

            ++iterator;
            ++y;
        }

        _diagnoseModule->GetStaticProblematicSensorCollection()->clear();
    }

private:
    DiagnoseModule * _diagnoseModule;
    QVector<Edge * > * _edgeList;
    QVector<Node * > * _nodeList;
    QTableView * _tableView;
    QStandardItemModel * _modelView;
};

#endif // OBSERVER_H
