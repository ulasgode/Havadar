#ifndef COMMAND_H
#define COMMAND_H

#include "receiver.h"

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
 * Command class is an abstract command class.
 */
class Command
{
public:
    /*!
    * Execute method is a pure virtual function that has to be implemented in the subclasses.
    */
    virtual void Execute() = 0;

protected:
    /*!
    * Constructor that can be redefined in the subclasses.
    */
    Command() {}
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
 * GetEdgeCommand class adds the all edge objects from database into the collection
 * given as a parameter.
 */
class GetEdgeCommand : public Command
{
private:
    Receiver * _getCommandReceiver; /*!< The receiver that gets edges from the database */

public:
    /*!
    * Constructor that allocates space for command's receiver and
    * initializes it given parameters.
    *
    * @param database Database object that makes the connection between application and database
    * @param edgeList The list of the all edges on the graph
    */
    GetEdgeCommand(QSqlDatabase database, QVector<Node * > * nodeList, QVector<Edge * > * edgeList)
    {
        _getCommandReceiver = new GetEdgeCommandReceiver(database, nodeList, edgeList);
    }

    /*!
    * Execute the command's receiver.
    */
    void Execute() {
        _getCommandReceiver->Action();
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
 * GetNodeCommand class adds the all node objects from database into the collection
 * given as a parameter.
 */
class GetNodeCommand : public Command
{
private:
    Receiver * _getCommandReceiver; /*!< The receiver that gets nodes from the database */

public:
    /*!
    * Constructor that allocates space for command's receiver and
    * initializes it given parameters.
    *
    * @param database Database object that makes the connection between application and database
    * @param nodeList The list of the all nodes on the graph
    */
    GetNodeCommand(QSqlDatabase database, QVector<Node * > * nodeList)
    {
        _getCommandReceiver = new GetNodeCommandReceiver(database, nodeList);
    }

    /*!
    * Execute the command's receiver.
    */
    void Execute()
    {
        _getCommandReceiver->Action();
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
 * SetEdgeCommand class updates the all sensor objects that are between two nodes and
 * exists on the database.
 */
class SetEdgeCommand : public Command
{
private:
    Receiver * _setCommandReceiver; /*!< The receiver that sets edges that are on the database */

public:
    /*!
    * Constructor that allocates space for command's receiver and
    * initializes it given parameters.
    *
    * @param database Database object that makes the connection between application and database
    * @param edgeList The list of the all edges on the graph
    */
    SetEdgeCommand(QSqlDatabase database, QVector<Edge * > *edgeList)
    {
        _setCommandReceiver = new SetEdgeCommandReceiver(database, edgeList);
    }

    /*!
    * Execute the command's receiver.
    */
    void Execute() {
        _setCommandReceiver->Action();
    }
};

#endif // COMMAND_H
