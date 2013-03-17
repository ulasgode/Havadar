#ifndef POSITION_H
#define POSITION_H

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
 * Position class contains the latitude and the longitude.
 */
class Position
{
private:
    double _latitude; /*!< The latitude of the position */
    double _longitude; /*!< The longitude of the position */

public:
    /*!
    * Constructor that initializes the latitude and the longitude to the zero.
    */
    Position()
    {
        _latitude = 0;
        _longitude = 0;
    }

    /*!
    * Constructor that initializes the latitude and the longitude to the given parameters.
    *
    * @param latitude The latitude of the position
    * @param longitude The longitude of the position
    */
    Position(double latitude, double longitude)
    {
        _latitude = latitude;
        _longitude = longitude;
    }

    /*!
    * Get the latitude of the position.
    *
    * @return A latitude of the position
    */
    double GetLatitude()
    {
        return _latitude;
    }

    /*!
    * Set the latitude of the position.
    *
    * @param latitude The new latitude of the position
    */
    void SetLatitude(double latitude)
    {
        _latitude = latitude;
    }

    /*!
    * Get the longitude of the position.
    *
    * @return A longitude of the position
    */
    double GetLongitude()
    {
        return _longitude;
    }

    /*!
    * Set the longitude of the position.
    *
    * @param longitude The new longitude of the position
    */
    void SetLongitude(double longitude)
    {
        _longitude = longitude;
    }
};

#endif // POSITION_H
