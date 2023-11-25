#ifndef UNIT_DERIVED_FLOWS_H
#define UNIT_DERIVED_FLOWS_H

#include "../../src/flowimpl.h"

/**
 * @brief Exponential flow class derived from flow.
 *
 * Represents a exponential interaction beetween systems, where the value
 * taken from and given to the classes are exponential.
 * Its only purpose is to implement the pure virutal method run(), from flow.
 * 
 */
class ExponentialFlow : public Flowimpl {

    public:

        using Flowimpl::operator=;

        /**
         * @brief ExponentialFlow default constructor.
         *
         * Calls the flow default constructor to instance a derived class object.
         * 
         */
        ExponentialFlow();

        /**
         * @brief ExponentialFlow complete constructor.
         *
         * Calls the flow complete constructor to instance a derived class object.
         * 
         */
        ExponentialFlow(string name, double value, System* origin, System* Destination);

        ExponentialFlow(Flow& flow);


        /**
         * @brief run method override.
         *
         * Takes a set value defined by a simple math equation from the origin System and returns it.
         * 
         * @return returns the value it got from the equation, used to update the Systemimpls values.
         * 
         */
        double run();


};

/**
 * @brief Logistical flow class derived from flow.
 *
 * Represents a logistical interaction beetween systems, flow is sort of inverted,
 * taking the value from the destination System and transfering it to the origin System.
 * Its only purpose is to implement the pure virutal method run(), from flow.
 * 
 */
class LogisticalFlow : public Flowimpl {

    public:

        using Flowimpl::operator=;

        /**
         * @brief LogisticalFlow default constructor.
         *
         * Calls the flow default constructor to instance a derived class object.
         * 
         */
        LogisticalFlow();

        /**
         * @brief LogisticalFlow complete constructor.
         *
         * Calls the flow complete constructor to instance a derived class object.
         * 
         */
        LogisticalFlow(string name, double value, System* origin, System* Destination);

        LogisticalFlow(Flow& flow);


        /**
         * @brief run method override.
         *
         * Takes a set value defined by a more complex math equation from the destination System and returns it.
         * 
         * @return returns the value it got from the equation, used to update the Systemimpls values.
         * 
         */
        double run();


};

/**
 * @brief Complex flow class derived from flow.
 *
 * Despite its name, it represents the simplest interaction beetween systems,
 * subtracting a constant value from the origin System and adding it to the destination one.
 * Its only purpose is to implement the pure virutal method run(), from flow.
 * 
 */
class ComplexFlow : public Flowimpl {

    public:

        using Flowimpl::operator=;

        /**
         * @brief ComplexFlow default constructor.
         *
         * Calls the flow default constructor to instance a derived class object.
         * 
         */
        ComplexFlow();

        /**
         * @brief ComplexFlow default constructor.
         *
         * Calls the flow complete constructor to instance a derived class object.
         * 
         */
        ComplexFlow(string name, double value, System* origin, System* destination);

        ComplexFlow(Flow& flow);

        /**
         * @brief run method override.
         *
         * Takes a set value defined by a simple math equation from the origin System and returns it.
         * Currently the same equation as the exponentialFlow implementation.
         * 
         * @return returns the value it got from the equation, used to update the Systemimpls values.
         * 
         */
        double run();


};

#endif