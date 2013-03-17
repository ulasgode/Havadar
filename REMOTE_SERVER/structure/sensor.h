#ifndef SENSOR_H
#define SENSOR_H

#define SENSOR_SUC_0    0
#define SENSOR_ERR_1    1
#define SENSOR_ERR_2    2

#define THROUGHPUT          0
#define AVERAGE_SPEED       1
#define ROAD_SLIPPERINESS   2
#define WEATHER_CONDITION   3
#define ILLUMINATION        4

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
 * Sensor class contains the sensor's problem ID, its value and its ID.
 * Also this is an abstract sensor class.
 */
class Sensor
{
private:
    int _problem; /*!< The problem ID of the sensor */
    float _value; /*!< The value of the sensor */
    int _ID; /*!< The ID of the sensor */

public:
    /*!
    * Get the problem ID of the sensor.
    *
    * @return A problem ID
    */
    int GetProblem()
    {
        return _problem;
    }

    /*!
    * Set the problem ID of the sensor.
    *
    * @param problem The new problem ID of the sensor
    */
    void SetProblem(int problem)
    {
        _problem = problem;
    }

    /*!
    * Get the value of the sensor.
    *
    * @return A value of the sensor
    */
    float GetValue()
    {
        return _value;
    }

    /*!
    * Set the value of the sensor.
    *
    * @param problem The new value of the sensor
    */
    void SetValue(float value)
    {
        _value = value;
    }

    /*!
    * Get the ID of the sensor.
    *
    * @return A ID of the sensor
    */
    int GetID()
    {
        return _ID;
    }

    /*!
    * Set the ID of the sensor.
    *
    * @param ID The new name of the sensor
    */
    void SetID(int ID)
    {
        _ID = ID;
    }

protected:
    /*!
    * Constructor that can be redefined in the subclasses.
    */
    Sensor() {}
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
 * StaticWeatherConditionSensor class contains the average weight that comes from
 * sensors which measure temperature, wind, humidity etc.
 */
class StaticWeatherConditionSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    StaticWeatherConditionSensor()
    {
        SetID(WEATHER_CONDITION);
        SetProblem(SENSOR_SUC_0);
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
 * StaticThroughputSensor class contains the throughput information that comes from
 * sensors which is on the road and measures road density.
 */
class StaticThroughputSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    StaticThroughputSensor()
    {
        SetID(THROUGHPUT);
        SetProblem(SENSOR_SUC_0);
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
 * StaticIlluminationSensor class contains the illumination information that comes from
 * sensors which is on the road and measures illumination.
 */
class StaticIlluminationSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    StaticIlluminationSensor()
    {
        SetID(ILLUMINATION);
        SetProblem(SENSOR_SUC_0);
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
 * StaticAverageSpeedSensor class contains the average speed information that comes from
 * sensors which is on the road and measures speed of vehicles.
 */
class StaticAverageSpeedSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    StaticAverageSpeedSensor()
    {
        SetID(AVERAGE_SPEED);
        SetProblem(SENSOR_SUC_0);
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
 * StaticRoadSlipperinessSensor class contains the slipperiness information that comes from
 * sensors which is on the road and measures slipperiness.
 */
class StaticRoadSlipperinessSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    StaticRoadSlipperinessSensor()
    {
        SetID(ROAD_SLIPPERINESS);
        SetProblem(SENSOR_SUC_0);
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
 * DynamicWeatherConditionSensor class contains the average weight that comes from
 * sensors which measure temperature, wind, humidity etc.
 */
class DynamicWeatherConditionSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    DynamicWeatherConditionSensor()
    {
        SetID(WEATHER_CONDITION);
        SetProblem(SENSOR_SUC_0);
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
 * DynamicThroughputSensor class contains the throughput information that comes from
 * sensors which is on the vehicle and measures road density.
 */
class DynamicThroughputSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    DynamicThroughputSensor()
    {
        SetID(THROUGHPUT);
        SetProblem(SENSOR_SUC_0);
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
 * DynamicIlluminationSensor class contains the illumination information that comes from
 * sensors which is on the vehicle and measures illumination.
 */
class DynamicIlluminationSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    DynamicIlluminationSensor()
    {
        SetID(ILLUMINATION);
        SetProblem(SENSOR_SUC_0);
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
 * DynamicAverageSpeedSensor class contains the average speed information that comes from
 * sensors which is on the vehicle and measures speed of vehicles.
 */
class DynamicAverageSpeedSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    DynamicAverageSpeedSensor()
    {
        SetID(AVERAGE_SPEED);
        SetProblem(SENSOR_SUC_0);
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
 * DynamicRoadSlipperinessSensor class contains the slipperiness information that comes from
 * sensors which is on the vehicle and measures slipperiness.
 */
class DynamicRoadSlipperinessSensor : public Sensor
{
public:
    /*!
    * Constructor that initializes the values and calls the Control() method inside.
    */
    DynamicRoadSlipperinessSensor()
    {
        SetID(ROAD_SLIPPERINESS);
        SetProblem(SENSOR_SUC_0);
    }
};

#endif // SENSOR_H
