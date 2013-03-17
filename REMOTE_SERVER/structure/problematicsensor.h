#ifndef PROBLEMATICSENSOR_H
#define PROBLEMATICSENSOR_H

#include "sensor.h"

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
 * ProblematicSensor class contains the node ID, its neighbour's ID and
 * the problematic sensor that is between the node and its neighbour.
 */
class ProblematicSensor
{
private:
    int _node; /*!< The node ID */
    int _neighbour; /*!< The neighbour ID */
    Sensor * _problematicSensor; /*!< The problematic sensor */

public:
    ProblematicSensor(int node, int neighbour, Sensor * problematicSensor)
    {
        _node = node;
        _neighbour = neighbour;
        _problematicSensor = problematicSensor;
    }

    /*!
    * Get the node ID.
    *
    * @return A node ID
    */
    int GetNode()
    {
        return _node;
    }

    /*!
    * Set the node ID.
    *
    * @param node The new ID of the node ID
    */
    void SetNode(int node)
    {
        _node = node;
    }

    /*!
    * Get the neighbour ID.
    *
    * @return A neighbour ID
    */
    int GetNeighbour()
    {
        return _neighbour;
    }

    /*!
    * Set the neighbour ID.
    *
    * @param neighbour The new ID of the neighbour ID
    */
    void SetNeighbour(int neighbour)
    {
        _neighbour = neighbour;
    }

    /*!
    * Get the problematic sensor object.
    *
    * @return A problematic sensor object that are between the node and its neighbour
    */
    Sensor * GetProblematicSensor ()
    {
        return _problematicSensor;
    }

    /*!
    * Set the problematic sensor.
    *
    * @param problematicSensor The new problematic sensor object that are between the node and its neighbour
    */
    void SetProblematicSensor (Sensor * problematicSensor)
    {
        _problematicSensor = problematicSensor;
    }
};

#endif // PROBLEMATICSENSOR_H
