#ifndef DIAGNOSEMODULE_H
#define DIAGNOSEMODULE_H

#include "structure/edge.h"

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
 * DiagnoseModule class consists of the system diagnose
 * procedure which is responsible for checking the functionality
 * of the sensors.
 */
class DiagnoseModule
{
private:
    QVector<ProblematicSensor *> * _staticProblematicSensorCollection; /*!< Collection that includes problematic sensors on the graph */

public:
    /*!
    * Constructor that allocates space for a collection that includes
    * problematic sensor objects.
    */
    DiagnoseModule()
    {
        _staticProblematicSensorCollection = new QVector<ProblematicSensor *>();
    }

    ~DiagnoseModule()
    {
        delete _staticProblematicSensorCollection;
    }

    /*!
    * Check the functionality of the sensors on the edges.
    *
    * @param edgeList The list of the all edges on the graph
    */
    void CheckStaticSensorsOnTheEdges(QVector<Edge * > * edgeList)
    {
        QVector<Edge * >::iterator edgeIterator = edgeList->begin();
        Edge * edge = * edgeIterator;

        while (edgeIterator != edgeList->end()) {
            edge = * edgeIterator;
            edge->AddStaticProblematicSensorToCollection(_staticProblematicSensorCollection);
            ++edgeIterator;
        }
    }

    /*!
    * Get the problematic sensors.
    *
    * @return A collection that includes problematic sensor objects
    */
    QVector<ProblematicSensor *> * GetStaticProblematicSensorCollection()
    {
        return _staticProblematicSensorCollection;
    }
};

#endif // DIAGNOSEMODULE_H
