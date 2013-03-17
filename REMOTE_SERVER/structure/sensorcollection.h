#ifndef SENSORCOLLECTION_H
#define SENSORCOLLECTION_H

#include "structure/sensorfactory.h"

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
 * SensorModule class contains the structure of the sensor data
 * and procedures to reach them. There are various type of sensors
 * exists in the system, so this module defines the structure needed
 * to collect the data from them.
 */
class SensorCollection
{
private:
    SensorFactory * _dynamicSensorCollection; /*!< Sensor factory that creates dynamic sensor collection */
    SensorFactory * _staticSensorCollection; /*!< Sensor factory that creates static sensor collection */

public:
    /*!
    * Constructor that allocates space for sensor factories that
    * include dynamic and static sensor objects.
    */
    SensorCollection()
    {
        _dynamicSensorCollection = new DynamicSensorFactory();
        _staticSensorCollection = new StaticSensorFactory();

        _dynamicSensorCollection->CreateSensorCollection();
        _staticSensorCollection->CreateSensorCollection();
    }

    /*!
    * Display the static sensor objects that is inside of static sensor
    * collection that was created by static sensor factory.
    */
    void DisplayDynamicSensorCollection()
    {
        _dynamicSensorCollection->DisplaySensorCollection();
    }

    /*!
    * Display the dynamic sensor objects that is inside of dynamic sensor
    * collection that was created by dynamic sensor factory.
    */
    void DisplayStaticSensorCollection()
    {
        _staticSensorCollection->DisplaySensorCollection();
    }

    /*!
    * Get the dynamic sensor collection that was created by dynamic sensor factory.
    *
    * @return A dynamic sensor collecton
    */
    QVector<Sensor *> * GetDynamicSensorCollection()
    {
        return _dynamicSensorCollection->GetSensorCollection();
    }

    /*!
    * Get the static sensor collection that was created by static sensor factory.
    *
    * @return A static sensor collecton
    */
    QVector<Sensor *> * GetStaticSensorCollection()
    {
        return _staticSensorCollection->GetSensorCollection();
    }

    /*!
    * Get the dynamic sensor objects' average weight that is inside of
    * dynamic sensor collection that was created by dynamic sensor factory.
    *
    * @return A dynamic sensor collecton's overall weight
    */
    float GetDynamicSensorCollectionWeight()
    {
        return _dynamicSensorCollection->CalculateOverallWeight();
    }

    /*!
    * Get the static sensor objects' average weight that is inside of
    * static sensor collection that was created by static sensor factory.
    *
    * @return A static sensor collecton's overall weight
    */
    float GetStaticSensorCollectionWeight()
    {
        return _staticSensorCollection->CalculateOverallWeight();
    }

    /*!
    * Set the static sensor objects' average weight that is inside of
    * static sensor collection that was created by static sensor factory.
    *
    * @param weights The new weight of the all sensors that are on the dynamic sensor collection
    */
    void SetDynamicSensorCollection(float weights[5])
    {
        return _dynamicSensorCollection->SetSensorCollection(weights);
    }

    /*!
    * Set the static sensor objects' average weight that is inside of
    * static sensor collection that was created by static sensor factory.
    *
    * @param weights The new weight of the all sensors that are on the static sensor collection
    */
    void SetStaticSensorCollection(float weights[5])
    {
        return _staticSensorCollection->SetSensorCollection(weights);
    }

    /*!
    * Get the specific dynamic sensor object that is inside of dynamic sensor
    * collection according to its ID.
    *
    * @param ID The ID of the sensor
    *
    * @return A dynamic sensor that has same ID given parameter
    */
    Sensor * GetDynamicSensorByID(int ID)
    {
        return _dynamicSensorCollection->GetSensorByID(ID);
    }

    /*!
    * Get the specific static sensor object that is inside of static sensor
    * collection according to its ID.
    *
    * @param ID The ID of the sensor
    *
    * @return A static sensor that has same ID given parameter
    */
    Sensor * GetStaticSensorByID(int ID)
    {
        return _staticSensorCollection->GetSensorByID(ID);
    }

    /*!
    * Add the problematic static sensor object into the collection
    * given as a parameter.
    *
    * @param node The node ID
    * @param neighbour The neighbour ID
    * @param sensorCollection The list of the all problematic sensor objects on the graph
    */
    void AddStaticProblematicSensorToCollection(int node, int neighbour, QVector<ProblematicSensor *> * sensorCollection)
    {
        _staticSensorCollection->AddProblematicSensorToCollection(node, neighbour, sensorCollection);
    }
};

#endif // SENSORCOLLECTION_H
