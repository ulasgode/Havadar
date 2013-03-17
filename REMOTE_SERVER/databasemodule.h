#ifndef DATABASEMODULE_H
#define DATABASEMODULE_H

#include <QtSql>

#include "structure/edge.h"
#include "structure/node.h"
#include "structure/command.h"

#define HOSTNAME    "localhost"
#define DATABASE    "izmir_graph"
#define USERNAME    "root"
#define PASSWORD    "qgw_00_dpy"

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
 * DatabaseModule class is responsible for logging or updating the
 * nodes and paths. Any kind of action is logged and kept in the
 * database for future calculation.
 */
class DatabaseModule
{
private:
    QSqlDatabase _database; /*!< Database object that makes the connection between application and database */

public:
    /*!
    * Constructor that allocates space for a QSqlDatabase object that
    * makes the connection between application and database and set
    * connection features.
    */
    DatabaseModule()
    {
        _database = QSqlDatabase::addDatabase("QMYSQL");
        _database.setHostName(HOSTNAME);
        _database.setDatabaseName(DATABASE);
        _database.setUserName(USERNAME);
        _database.setPassword(PASSWORD);
    }

    /*!
    * Add the all edge objects from database into the collection
    * given as a parameter.
    *
    * @param edgeList The list of the all edges on the graph
    */
    void GetEdges(QVector<Node * > * nodeList, QVector<Edge * > * edgeList)
    {
        Command * _getEdgeCommand = new GetEdgeCommand(_database, nodeList, edgeList);
        _getEdgeCommand->Execute();
    }

    /*!
    * Add the all node objects from database into the collection
    * given as a parameter.
    *
    * @param nodeList The list of the all nodes on the graph
    */
    void GetNodes(QVector<Node * > * nodeList)
    {
        Command * _getNodeCommand = new GetNodeCommand(_database, nodeList);
        _getNodeCommand->Execute();
    }

    /*!
    * Update the all sensor objects that are on the database according
    * to the collection given as a parameter.
    *
    * @param edgeList The list of the all edges on the graph
    */
    void SetEdges(QVector<Edge * > * edgeList)
    {
        Command * _setEdgeCommand = new SetEdgeCommand(_database, edgeList);
        _setEdgeCommand->Execute();
    }
};

#endif // DATABASEMODULE_H
