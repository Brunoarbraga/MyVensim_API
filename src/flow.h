#ifndef FLOW_H
#define FLOW_H

#include "system.h"

/**
 * @brief Represents the Flow.
 *
 * This class represents the real life interactions beetween systems, that possibly 
 * alter their values and represent a phenomena. Its the event that occurs
 * throught time and influences the behaviour of the systems. For instance,
 * population growth of a given nation system.
 * 
 */
class Flow {

    public:

        /**
         * @brief Flow virtual destructor.
         *
         * Destructs the flow, freeing its memory allocation.
         * 
         */
        virtual ~Flow(){};

        /**
         * @brief Flow's run method.
         *
         * This method is pure virtual, which means it can only be implemented by Flow's subclasses.
         * Is used to set the flow value, using the origin or destination System, depending on the type of flow.
         * This value is gonna be used later to update systems values. 
         * 
         */
        virtual double run() = 0;

        /**
         * @brief Setter function for the flow origin.
         * 
         * Sets the origin pointer of the flow and returns success or failure.
         * Essential for correctly representing the real world interactions.
         *
         * @param system system pointer to be set as origin.
         * 
         * @return returns boolean true if successful, false otherwise.
         * Extremely imporant keeping track of the success because the entire
         * simulation depends on it.
         *
         */
        virtual bool setOrigin(System* system) = 0;

        /**
         * @brief Setter function for the flow destination.
         * 
         * Sets the destination pointer of the flow and returns success or failure.
         * Essential for correctly representing the real world interactions.
         *
         * @param system system pointer to be set as destination.
         * 
         * @return returns boolean true if successful, false otherwise.
         * Extremely imporant keeping track of the success because the entire
         * simulation depends on it.
         *
         */
        virtual bool setDestination(System* system) = 0;

        /**
         * @brief Getter function for the flow origin.
         * 
         * Gets the system pointed as origin by the flow and returns it.
         *
         * @return The current origin pointer.
         * Can be used to update the systems values, since the value is "trasnfered" from
         * one System to another.
         * For instance, if a population migrates from a place, they need to have migrated to another place,
         * its possible to get where they migrated from with this method.
         *
         */
        virtual System* getOrigin() const = 0;

        /**
         * @brief Getter function for the flow destination.
         * 
         * Gets the system pointed as Destination by the flow and returns it.
         *
         * @return The current destination pointer.
         * Can be used to update the systems values, since the value is "trasnfered" from
         * one System to another.
         * For instance, if a population migrates from a place, they need to have migrated to another place,
         * its possible to get to where they migrated with this method.
         *
         */
        virtual System* getDestination() const = 0;

        /**
         * @brief Setter function for the name.
         * 
         * Sets the name of the Flow and returns success or failure.
         * Important if the name is not already defined in the constructor call.
         *
         * @param name string name to be set to the class atribute.
         * 
         * @return returns boolean true if successful, false otherwise.
         *
         */
        virtual bool setName(string name) = 0;

        /**
         * @brief Setter function for the value.
         * 
         * Sets the value of the flow and returns success or failure.
         * Can be used to update the Flow's value when the simulation is ran.
         *
         * @param value double value to be set to the class atribute
         * 
         * @return returns boolean true if successful, false otherwise.
         *
         */
        virtual bool setValue(double value) = 0;

        /**
         * @brief Getter function for the name.
         * 
         * Gets the current name of the Flow and returns it to the user.
         *
         * @return The current string name.
         *
         */
        virtual string getName() const = 0;

        /**
         * @brief Getter function for the value.
         * 
         * Gets the current value of the flow and returns it to the user.
         *
         * @return The current double value.
         * Can be used to update the system value.
         * For instance, if we need to subtract the population of a city due to migration,
         * we need to know how many people left first. That can be done calling this method.
         *
         */
        virtual double getValue() const = 0;

        /**
         * @brief Flow's atribution operator overload.
         *
         * Atributes one Flow to another, that is, copies all of its informations (name, value, origin and destination)
         * and atributes them to the left-side Flow atributes.
         * 
         * @param other Flow to be atributed to the left-side of the operator Flow 
         * 
         * @return returns a Flow memory adress
         * 
         */
        virtual Flow& operator=(const Flow& other) = 0;

        /**
         * @brief Overload of equality operator for Flow.
         *
         * Checks if two Flows are equal, considering all their atributes.
         * 
         * @param other Flow to be compared to the left-side of the operator Flow.
         * 
         * @return returns a boolean true if the Flows are equal, false otherwise.
         * 
         */
        virtual bool operator==(const Flow& other) const = 0;

        
};


#endif