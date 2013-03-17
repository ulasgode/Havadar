#ifndef EDGE_H
#define EDGE_H

#include "structure/sensorcollection.h"
#include "structure/problematicsensor.h"

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
 * Edge class contains the node ID, its neighbour's ID and the sensor module
 * that seperate from static and dynamic sensors. Static sensors are on
 * the road. On the other hand, dynamic sensors are on the vehicles.
 * And that module keeps information about these sensors.
 */
class Edge
{
private:
    int _node; /*!< The node ID */
    int _neighbour; /*!< The neighbour ID */
    SensorCollection * _sensorCollection; /*!< The sensor module that keeps dynamic and static sensor collections inside */

public:
    /*!
    * Constructor that allocates space for sensor module that
    * include dynamic and static sensor collections.
    */
    Edge()
    {
        _sensorCollection = new SensorCollection();
    }

    ~Edge()
    {
        delete _sensorCollection;
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
    * Get the sensor module.
    *
    * @return A sensor module of the node
    */
    SensorCollection * GetSensorCollection()
    {
        return _sensorCollection;
    }

    /*!
    * Set the sensor module.
    *
    * @param sensorModule The new sensor module of the edge
    */
    void SetSensorCollection(SensorCollection * sensorCollection)
    {
        _sensorCollection = sensorCollection;
    }

    /*!
    * First search the static problematic sensor that is inside of the sensor module on the edge,
    * Then add the problematic static sensor object into the collection given as a parameter.
    *
    * @param StaticProblematicSensorCollection The list of the all static problematic sensor objects on the graph
    */
    void AddStaticProblematicSensorToCollection(QVector<ProblematicSensor *> * StaticProblematicSensorCollection)
    {
        _sensorCollection->AddStaticProblematicSensorToCollection(_node, _neighbour, StaticProblematicSensorCollection);
    }
};

#endif // EDGE_H
