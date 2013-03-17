#ifndef NODE_H
#define NODE_H

#include "position.h"

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
 * Node class contains the node position and the node name.
 */
class Node
{
private:
    Position _position; /*!< The node position */
    QString _name; /*!< The node name */

public:

    QVector<int> _adjacency;
    double _distance;
    int _previous;

    /*!
    * Constructor that initializes the name and the position of the node.
    */
    Node(QString * name, Position * position)
    {
        _position = * position;
        _name = * name;


        _distance = 9999;
        _previous = -1;

    }

    /*!
    * Get the node name.
    *
    * @return A node name
    */
    QString GetName()
    {
        return _name;
    }

    /*!
    * Set the node name.
    *
    * @param name The new name of the node
    */
    void SetName(QString * name)
    {
        _name = * name;
    }

    /*!
    * Get the node position.
    *
    * @return A node position
    */
    Position GetPosition()
    {
        return _position;
    }

    /*!
    * Set the node position.
    *
    * @param position The new position of the node
    */
    void SetPosition(Position * position)
    {
        _position = * position;
    }
};

#endif // NODE_H
