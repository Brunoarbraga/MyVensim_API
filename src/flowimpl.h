#ifndef FLOWIMPL_H
#define FLOWIMPL_H


#include "flow.h"
#include "handleBodySemDebug.h"

/**
 * @brief Represents the Flowimpl.
 *
 * This class represents the real life interactions beetween systems, that possibly 
 * alter their values and represent a phenomena. Its the event that occurs
 * throught time and influences the behaviour of the systems. For instance,
 * population growth of a given nation system.
 * 
 */
class Flowimpl : public Body {

    protected:

        /**
         * @brief The Flowimpl's name.
         *
         * This represents the Flowimpl's name, is set to "" by default, and can be
         * changed at any given time by the user. Makes the identification of interactions
         * more intuitive, since they can be recognized on sight if given a good name,
         * e.g. exponential.
         * 
         */
        string name;

        /**
         * @brief The Flowimpl's value.
         *
         * This atribute represents the Flowimpl/interaction "transfer" value, the amount that will
         * be changed on the System's value when the simulation is ran. 
         * Is set to 0.0 by default, but can be changed at any given time.
         * 
         */
        double value;

        /**
         * @brief The Flowimpl's origin.
         *
         * This atribute represents where the flow comes from, that is, what system uses it as
         * an interaction. The start of the interaction. Linked to the flow via pointer.
         * Its possible for the flow to have no origin. In that case the pointer is null. 
         * 
         */
        System* origin;

        /**
         * @brief The Flowimpl's destination.
         *
         * This atribute represents where the flow "ends", what system uses it as
         * a "receiver". The end of the interaction. Linked to the flow via pointer.
         * Its possible for the flow to have no destination. In that case the pointer is null. 
         * 
         */
        System* destination;

    public:

        /**
         * @brief Flowimpl default constructor.
         *
         * Instances a Flowimpl object with an empty string "" name, a double 0.0 value,
         * and no origin nor destination (null pointers).
         * 
         */
        Flowimpl();

        /**
         * @brief Copy constructor for Flowimpl.
         *
         * Makes a deep copy of a given Flowimpl to the method calling Flowimpl.
         * Copies the name, value, and sets the origin and destination to be the same System
         * of the parameter.
         * 
         * @param flow Flowimpl to be copied.
         * 
         */
        Flowimpl(Flow &flow);

        /**
         * @brief Complete Flowimpl constructor.
         *
         * Intances a Flowimpl with all the atributes passed as parameters.
         * All the atributes that the class Flowimpl has are going to be "filled".
         * 
         * @param name string name to be atributed to the Flowimpl being instanced.
         * 
         * @param value double value to be atributed to the Flowimpl being instanced.
         * 
         * @param origin Pointer to the System acting as the origin of the interaction.
         * 
         * @param destination Pointer to the System acting as the destination of the interaction.
         *  
         */
        Flowimpl(string name, double value, System* origin, System* destination);

        /**
         * @brief Flowimpl virtual destructor.
         *
         * Destructs the flow, freeing its memory allocation.
         * 
         */
        virtual ~Flowimpl();

        /**
         * @brief Flowimpl's run method.
         *
         * This method is pure virtual, which means it can only be implemented by Flowimpl's subclasses.
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
        bool setOrigin(System* system);

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
        bool setDestination(System* system);

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
        System* getOrigin() const;

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
        System* getDestination() const;

        /**
         * @brief Setter function for the name.
         * 
         * Sets the name of the Flowimpl and returns success or failure.
         * Important if the name is not already defined in the constructor call.
         *
         * @param name string name to be set to the class atribute.
         * 
         * @return returns boolean true if successful, false otherwise.
         *
         */
        bool setName(string name);

        /**
         * @brief Setter function for the value.
         * 
         * Sets the value of the flow and returns success or failure.
         * Can be used to update the Flowimpl's value when the simulation is ran.
         *
         * @param value double value to be set to the class atribute
         * 
         * @return returns boolean true if successful, false otherwise.
         *
         */
        bool setValue(double value);

        /**
         * @brief Getter function for the name.
         * 
         * Gets the current name of the Flowimpl and returns it to the user.
         *
         * @return The current string name.
         *
         */
        string getName() const;

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
        double getValue() const;

        /**
         * @brief Overload of equality operator for Flowimpl.
         *
         * Checks if two Flowimpls are equal, considering all their atributes.
         * 
         * @param other Flowimpl to be compared to the left-side of the operator Flowimpl.
         * 
         * @return returns a boolean true if the Flowimpls are equal, false otherwise.
         * 
         */
        bool operator==(const Flow& other) const;

        
};

template <typename T>
class FlowHandle : public Flow , public Handle<T>{
    public:

        virtual ~FlowHandle(){}

        FlowHandle(){
            Handle<T>::pImpl_->setName("");
            Handle<T>::pImpl_->setValue(0.0);
            Handle<T>::pImpl_->setOrigin(nullptr);
            Handle<T>::pImpl_->setDestination(nullptr);

        }
        FlowHandle(string name, double value, System* origin, System* destination){
            Handle<T>::pImpl_->setName(name);
            Handle<T>::pImpl_->setValue(value);
            Handle<T>::pImpl_->setOrigin(origin);
            Handle<T>::pImpl_->setDestination(destination);
        }
        FlowHandle(Flow& flow){
            Handle<T>::pImpl_->setName(flow.getName());
            Handle<T>::pImpl_->setValue(flow.getValue());
            Handle<T>::pImpl_->setOrigin(flow.getOrigin());
            Handle<T>::pImpl_->setDestination(flow.getDestination());
        }
        

        double run(){
            return Handle<T>::pImpl_->run();
        }


        bool setOrigin(System* origin){
            return Handle<T>::pImpl_->setOrigin(origin);
        }
        bool setDestination(System* destination){
            return Handle<T>::pImpl_->setDestination(destination);
        }
        bool setName(string name){
            return Handle<T>::pImpl_->setName(name);
        }
        bool setValue(double value){
            return Handle<T>::pImpl_->setValue(value);
        }


        System* getOrigin() const{
            return Handle<T>::pImpl_->getOrigin();
        }
        System* getDestination() const{
            return Handle<T>::pImpl_->getDestination();
        }
        string getName() const{
            return Handle<T>::pImpl_->getName();
        }
        double getValue() const{
            return Handle<T>::pImpl_->getValue();
        }

        Flow& operator=(const Flow& other){
            return Handle<T>::pImpl->operator=(other);
        }

        bool operator==(const Flow& other) const{
            return Handle<T>::pImpl_->operator==(other);
        }

};


#endif

