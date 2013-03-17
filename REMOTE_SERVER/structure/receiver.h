#ifndef RECEIVER_H
#define RECEIVER_H

/**
 * @file
 * @author  Taner Güngör <taner.gungor@std.izmirekonomi.edu.tr>
 * @author  Efe Sezer <efe.sezer@std.izmirekonomi.edu.tr>
 * @author  Ulaş Göde <ulas.gode@std.izmirekonomi.edu.tr>
 * @author  Uğur Eryüzlü <ugur.eryuzlu@std.izmirekonomi.edu.tr>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Receiver class is an abstract receiver class.
 */
class Receiver
{
public:
    /*!
    * Action method is a pure virtual function that has to be implemented in the subclasses.
    */
    virtual void Action() = 0;

protected:
    /*!
    * Constructor that can be redefined in the subclasses.
    */
    Receiver() {}
};

/**
 * @file
 * @author  Taner Güngör <taner.gungor@std.izmirekonomi.edu.tr>
 * @author  Efe Sezer <efe.sezer@std.izmirekonomi.edu.tr>
 * @author  Ulaş Göde <ulas.gode@std.izmirekonomi.edu.tr>
 * @author  Uğur Eryüzlü <ugur.eryuzlu@std.izmirekonomi.edu.tr>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * GetEdgeCommandReceiver class adds the all edge objects from database into the collection
 * given as a parameter.
 */
class GetEdgeCommandReceiver : public Receiver
{
private:
    QVector<Node * > * _nodeList; /*!< The list of the all nodes on the graph */
    QVector<Edge * > * _edgeList; /*!< The list of the all edges on the graph */
    QSqlDatabase _database; /*!< Database object that makes the connection between application and database */

public:
    /*!
    * Constructor that initializes its attributes according to given parameters.
    *
    * @param database Database object that makes the connection between application and database
    * @param edgeList The list of the all edges on the graph
    */
    GetEdgeCommandReceiver(QSqlDatabase database, QVector<Node * > * nodeList, QVector<Edge * > * edgeList) :
        _nodeList(nodeList),
        _edgeList(edgeList),
        _database(database) {}

    ~GetEdgeCommandReceiver()
    {
        delete _nodeList;
        delete _edgeList;
    }

    /*!
    * Add the all edge objects from database into the collection
    * given as a parameter to the constructor.
    */
    void Action()
    {
        if (_database.open()) {
            QSqlQuery _sqlQuery;
            _sqlQuery.exec("SELECT * FROM `izmir_graph_edges`;");
            _edgeList->clear();
            while (_sqlQuery.next()) {
                float Sweights[5], Dweights[5];
                int nodes[2];
                nodes[0] = _sqlQuery.value(0).toInt();
                nodes[1] = _sqlQuery.value(1).toInt();

                Sweights[0] = _sqlQuery.value(2).toDouble();
                Sweights[1] = _sqlQuery.value(3).toDouble();
                Sweights[2] = _sqlQuery.value(4).toDouble();
                Sweights[3] = _sqlQuery.value(5).toDouble();
                Sweights[4] = _sqlQuery.value(6).toDouble();

                Dweights[0] = _sqlQuery.value(7).toDouble();
                Dweights[1] = _sqlQuery.value(8).toDouble();
                Dweights[2] = _sqlQuery.value(9).toDouble();
                Dweights[3] = _sqlQuery.value(10).toDouble();
                Dweights[4] = _sqlQuery.value(11).toDouble();

                Edge * e = new Edge();
                e->SetNode(nodes[0]);
                e->SetNeighbour(nodes[1]);
                e->GetSensorCollection()->SetStaticSensorCollection(Sweights);
                e->GetSensorCollection()->SetDynamicSensorCollection(Dweights);
                _edgeList->push_back(e);

                // ADJACENCY LIST'E ELEMAN EKLENIR
                _nodeList->at(nodes[0])->_adjacency.push_front(nodes[1]);
                _nodeList->at(nodes[1])->_adjacency.push_front(nodes[0]);
            }
        }
    }
};

/**
 * @file
 * @author  Taner Güngör <taner.gungor@std.izmirekonomi.edu.tr>
 * @author  Efe Sezer <efe.sezer@std.izmirekonomi.edu.tr>
 * @author  Ulaş Göde <ulas.gode@std.izmirekonomi.edu.tr>
 * @author  Uğur Eryüzlü <ugur.eryuzlu@std.izmirekonomi.edu.tr>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * GetNodeCommandReceiver class adds the all node objects from database into the collection
 * given as a parameter.
 */
class GetNodeCommandReceiver : public Receiver
{
private:
    QVector<Node * > * _nodeList; /*!< The list of the all nodes on the graph */
    QSqlDatabase _database; /*!< Database object that makes the connection between application and database */

public:
    /*!
    * Constructor that initializes its attributes according to given parameters.
    *
    * @param database Database object that makes the connection between application and database
    * @param nodeList The list of the all nodes on the graph
    */
    GetNodeCommandReceiver(QSqlDatabase database, QVector<Node * > * nodeList) :
        _nodeList(nodeList),
        _database(database) {}

    ~GetNodeCommandReceiver()
    {
        delete _nodeList;
    }

    /*!
    * Add the all node objects from database into the collection
    * given as a parameter to the constructor.
    */
    void Action()
    {
        if (_database.open()) {
            QSqlQuery _sqlQuery;
            _sqlQuery.exec("SELECT * FROM `izmir_graph_nodes`;");
            _nodeList->clear();
            float position[2];
            while (_sqlQuery.next()) {
                position[0] = _sqlQuery.value(2).toDouble();
                position[1] = _sqlQuery.value(3).toDouble();
                _nodeList->push_back(new Node(new QString(_sqlQuery.value(1).toString()), new Position(position[0], position[1])));
            }
        }
    }
};

/**
 * @file
 * @author  Taner Güngör <taner.gungor@std.izmirekonomi.edu.tr>
 * @author  Efe Sezer <efe.sezer@std.izmirekonomi.edu.tr>
 * @author  Ulaş Göde <ulas.gode@std.izmirekonomi.edu.tr>
 * @author  Uğur Eryüzlü <ugur.eryuzlu@std.izmirekonomi.edu.tr>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * SetEdgeCommandReceiver class updates the all sensor objects that are between two nodes and
 * exists on the database.
 */
class SetEdgeCommandReceiver : public Receiver
{
private:
    QVector<Edge * > * _edgeList; /*!< The list of the all edges on the graph */
    QSqlDatabase _database; /*!< Database object that makes the connection between application and database */

public:
    /*!
    * Constructor that initializes its attributes according to given parameters.
    *
    * @param database Database object that makes the connection between application and database
    * @param edgeList The list of the all edges on the graph
    */
    SetEdgeCommandReceiver(QSqlDatabase database, QVector<Edge * > * edgeList) :
        _edgeList(edgeList),
        _database(database) {}

    ~SetEdgeCommandReceiver()
    {
        delete _edgeList;
    }

    /*!
    * Update the all sensor objects that are on the database according
    * to the collection given as a parameter to the constructor.
    */
    void Action()
    {
        if (_database.open()) {
            QSqlQuery _sqlQuery;
            int index = 0;
            QString query("UPDATE `izmir_graph_edges` SET `edges_static_throughput` = :static_throughput, `edges_static_instantaneous_flow` = :static_instantaneous_flow, `edges_static_slipperiness` = :static_slipperiness, `edges_static_weather_condition` = :static_weather_condition, `edges_static_illumination` = :static_illumination, `edges_dynamic_throughput` = :dynamic_throughput, `edges_dynamic_instantaneous_flow` = :dynamic_instantaneous_flow, `edges_dynamic_slipperiness` = :dynamic_slipperiness, `edges_dynamic_weather_condition` = :dynamic_weather_condition, `edges_dynamic_illumination` = :dynamic_illumination WHERE `edges_start_node_id` = :start_node AND `edges_finish_node_id` = :finish_node;");

            while(index < _edgeList->size()) {
                _sqlQuery.prepare(query);
                _sqlQuery.bindValue(":start_node"                   , _edgeList->at(index)->GetNode());
                _sqlQuery.bindValue(":finish_node"                  , _edgeList->at(index)->GetNeighbour());

                _sqlQuery.bindValue(":static_throughput"            , _edgeList->at(index)->GetSensorCollection()->GetStaticSensorCollection()->at(0)->GetValue());
                _sqlQuery.bindValue(":static_instantaneous_flow"    , _edgeList->at(index)->GetSensorCollection()->GetStaticSensorCollection()->at(1)->GetValue());
                _sqlQuery.bindValue(":static_slipperiness"          , _edgeList->at(index)->GetSensorCollection()->GetStaticSensorCollection()->at(2)->GetValue());
                _sqlQuery.bindValue(":static_weather_condition"     , _edgeList->at(index)->GetSensorCollection()->GetStaticSensorCollection()->at(3)->GetValue());
                _sqlQuery.bindValue(":static_illumination"          , _edgeList->at(index)->GetSensorCollection()->GetStaticSensorCollection()->at(4)->GetValue());

                _sqlQuery.bindValue(":dynamic_throughput"           , _edgeList->at(index)->GetSensorCollection()->GetDynamicSensorCollection()->at(0)->GetValue());
                _sqlQuery.bindValue(":dynamic_instantaneous_flow"   , _edgeList->at(index)->GetSensorCollection()->GetDynamicSensorCollection()->at(1)->GetValue());
                _sqlQuery.bindValue(":dynamic_slipperiness"         , _edgeList->at(index)->GetSensorCollection()->GetDynamicSensorCollection()->at(2)->GetValue());
                _sqlQuery.bindValue(":dynamic_weather_condition"    , _edgeList->at(index)->GetSensorCollection()->GetDynamicSensorCollection()->at(3)->GetValue());
                _sqlQuery.bindValue(":dynamic_illumination"         , _edgeList->at(index)->GetSensorCollection()->GetDynamicSensorCollection()->at(4)->GetValue());

                _sqlQuery.exec();
                ++index;
            }
        }
    }
};

#endif // RECEIVER_H
