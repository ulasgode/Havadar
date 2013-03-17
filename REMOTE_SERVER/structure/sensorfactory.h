#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "structure/sensor.h"
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
 * SensorFactory class creates the sensors and it has also some methods which
 * control and manage them easily.
 */
class SensorFactory
{
private:
    QVector<Sensor *> * _sensorCollection; /*!< The list of the sensors */

public:
    /*!
    * CreateSensorCollection method is a pure virtual function that has to be implemented in the subclasses.
    */
    virtual void CreateSensorCollection() = 0;

    /*!
    * Display the sensor collection
    */
    void DisplaySensorCollection()
    {
        QVector<Sensor *>::iterator sensorIterator = _sensorCollection->begin();
        Sensor * sensor = * sensorIterator;

        while (sensorIterator != _sensorCollection->end()) {
            sensor = * sensorIterator;
            qDebug() << sensor->GetValue();
            ++sensorIterator;
        }
    }

    /*!
    * Get the sensor objects' average weight that is inside of dynamic sensor collection.
    *
    * @return A sensor collecton's average weight
    */
    float CalculateOverallWeight()
    {
        float _overallWeight = 0.0;
        _overallWeight += _sensorCollection->at(0)->GetValue() * 0.15;
        _overallWeight += _sensorCollection->at(1)->GetValue() * 0.15;
        _overallWeight += _sensorCollection->at(2)->GetValue() * 0.15;
        _overallWeight += _sensorCollection->at(3)->GetValue() * 0.40;
        _overallWeight += _sensorCollection->at(4)->GetValue() * 0.15;
        return _overallWeight;
    }

    /*!
    * Get the sensor collection
    *
    * @return A sensor collecton
    */
    QVector<Sensor *> * GetSensorCollection()
    {
        return _sensorCollection;
    }

    /*!
    * Set the sensor objects' weight that is inside of sensor collection
    *
    * @param weights The new weight of the all sensors that are on the sensor collection
    */
    void SetSensorCollection(float weights[5])
    {
        QVector<Sensor *>::iterator sensorIterator = _sensorCollection->begin();
        Sensor * sensor = * sensorIterator;
        int index = 0;

        while (sensorIterator != _sensorCollection->end()) {
            sensor = * sensorIterator;
            sensor->SetValue(weights[index]);
            ++sensorIterator;
            ++index;
        }
    }

    /*!
    * Get the specific sensor object that is inside of sensor collection
    * according to its ID.
    *
    * @param ID The ID of the sensor
    *
    * @return A sensor that has same ID given parameter
    */
    Sensor * GetSensorByID(int ID)
    {
        return _sensorCollection->at(ID);
    }

    /*!
    * Add the problematic sensor object into the collection given as a parameter.
    *
    * @param node The node ID
    * @param neighbour The neighbour ID
    * @param sensorCollection The list of the all problematic sensor objects on the graph
    */
    void AddProblematicSensorToCollection(int node, int neighbour, QVector<ProblematicSensor *> * problematicSensorCollection)
    {
        QVector<Sensor * >::iterator sensorIterator = _sensorCollection->begin();
        Sensor * sensor = * sensorIterator;

        while (sensorIterator != _sensorCollection->end()) {
            sensor = * sensorIterator;

            if(sensor->GetProblem() != 0) {
                problematicSensorCollection->push_back(new ProblematicSensor(node, neighbour, sensor));
            }

            ++sensorIterator;
        }
    }

protected:
    /*!
    * Constructor that allocates space for the sensor collection.
    */
    SensorFactory()
    {
        _sensorCollection = new QVector<Sensor *>();
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
 * StaticSensorFactory class creates the static sensors and put them into the sensor collection.
 */
class StaticSensorFactory : public SensorFactory
{
public:
    /*!
    * Constructor that extends from the base class.
    */
    StaticSensorFactory() : SensorFactory() {}

    /*!
    * Creates the static sensors and put them into the sensor collection.
    */
    void CreateSensorCollection()
    {
        GetSensorCollection()->push_front(new StaticIlluminationSensor());
        GetSensorCollection()->push_front(new StaticWeatherConditionSensor());
        GetSensorCollection()->push_front(new StaticRoadSlipperinessSensor());
        GetSensorCollection()->push_front(new StaticAverageSpeedSensor());
        GetSensorCollection()->push_front(new StaticThroughputSensor());
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
 * DynamicSensorFactory class creates the dynamic sensors and put them into the sensor collection.
 */
class DynamicSensorFactory : public SensorFactory
{
public:
    /*!
    * Constructor that extends from the base class.
    */
    DynamicSensorFactory() : SensorFactory() {}

    /*!
    * Creates the dynamic sensors and put them into the sensor collection.
    */
    void CreateSensorCollection()
    {
        GetSensorCollection()->push_front(new DynamicIlluminationSensor());
        GetSensorCollection()->push_front(new DynamicWeatherConditionSensor());
        GetSensorCollection()->push_front(new DynamicRoadSlipperinessSensor());
        GetSensorCollection()->push_front(new DynamicAverageSpeedSensor());
        GetSensorCollection()->push_front(new DynamicThroughputSensor());
    }
};

#endif // SENSORFACTORY_H
