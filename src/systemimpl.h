#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H
#include "system.h"
#include "handleBodySemDebug.h"


/**
 * @brief Represents the Systemimpl.
 *
 * This class represents the real life systems and its phenomena, storing its energy (value),
 * that could be altered through the course of time in the simulation. e.g. Respiratory system, cardiovascular system. 
 * 
 * Systemimpls can exist independently from any other structure in the simulation.
 * 
 */
class Systemimpl : public Body {
    protected:
        // Como foi decidido que não há necessidade de sistemas possuitem subsistemas nessa sprint
        // Os atributos abaixo foram removidos
        // Systemimpl* systems;
        // Flow* flows;

        /**
         * @brief The Systemimpl's value.
         *
         * This atribute represents the Systemimpls energy/matter, the value it holds in 
         * the real world. Is set to 0.0 by default, but can be changed at any given time
         * 
         */
        double value;

        /**
         * @brief The Systemimpl's name.
         *
         * This represents the Systemimpl's name, is set to "" by default, and can be
         * changed at any given time by the user. Very imporant for identification,
         * since it usually defines its usage, e.g. "respiratory system"
         * 
         */
        string name;

    public:

        /**
         * @brief Systemimpl default constructor.
         *
         * Instances a Systemimpl object with an empty string "" name atribute and double 0.0 value,
         * if no parameter is passed.
         * 
         */
        Systemimpl();

        /**
         * @brief Copy constructor for Systemimpl.
         *
         * Makes a deep copy of a given Systemimpl to the method calling Systemimpl.
         * Copies the value and the name atribute, via = operator.
         * 
         * @param system Systemimpl to be copied.
         * 
         */
        Systemimpl(System &system);

        /**
         * @brief Systemimpl constructor override with value parameter.
         *
         * Intances a Systemimpl atributing the double parameter given to the Systemimpl value atribute.
         * Since no name is given, sets it as "" by default.
         * 
         * @param value double value to be atributed to the Systemimpl being instanced.
         * 
         */
        Systemimpl(double value);

        /**
         * @brief Systemimpl constructor override with name parameter.
         *
         * Intances a Systemimpl atributing the string parameter given to the Systemimpl name atribute.
         * Since no value is given, sets it as 0.0 by default.
         * 
         * @param name string name to be atributed to the Systemimpl being instanced.
         * 
         */
        Systemimpl(string name);

        /**
         * @brief Complete Systemimpl constructor.
         *
         * Intances a Systemimpl with all the atributes passed as parameters.
         * All the atributes that the class Systemimpl has are going to be "filled".
         * 
         * @param value double value to be atributed to the Systemimpl being instanced.
         * 
         * @param name string name to be atributed to the Systemimpl being instanced.
         *  
         */
        Systemimpl(double value, string name);


        /**
         * @brief Systemimpl virtual destructor.
         *
         * Destructs the system, freeing its memory allocation.
         * 
         */
        virtual ~Systemimpl();

        /**
         * @brief Getter function for the value.
         * 
         * Gets the current value of the system and returns it to the user.
         *
         * @return The current double value.
         * Can be used to evaluate the flow, and to update the system's value
         *
         */
        double getValue() const;

        /**
         * @brief Setter function for the value.
         * 
         * Sets the value of the system and returns success or failure.
         * Can be used to update the Systemimpl's value when the simulation is ran.
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
         * Gets the current name of the system and returns it to the user.
         *
         * @return The current string name, the return value is constant to assure it wont
         * be modified in the process
         *
         */
        const string getName() const;

        /**
         * @brief Setter function for the name.
         * 
         * Sets the name of the system and returns success or failure.
         * Important if the name is not already defined in the constructor call.
         *
         * @param name string name to be set to the class atribute.
         * 
         * @return returns boolean true if successful, false otherwise.
         *
         */
        bool setName(string name);

        /**
         * @brief Systemimpl << operator overload.
         * 
         * Overloads the << cout operator so that the system can be printed on terminal (its name and value).
         * Used only by the printModel() method, since it prints all the systems it contains.
         *
         * @param system system to be printed
         *
         */
        friend ostream& operator<<(ostream& os, const Systemimpl& system);

        /**
         * @brief Systemimpl's atribution operator overload.
         *
         * Atributes one Systemimpl to another, that is, copies all of its informations (name and value)
         * and atributes them to the left-side Systemimpl atributes.
         * 
         * @param other Systemimpl to be atributed to the left-side of the operator Systemimpl  
         * 
         * @return returns a Systemimpl memory adress
         * 
         */
        Systemimpl& operator=(const Systemimpl& other);

        /**
         * @brief Overload of equality operator for Systemimpl.
         *
         * Checks if two Systemimpls are equal, considering all their atributes.
         * 
         * @param other Systemimpl to be compared to the left-side of the operator Systemimpl.
         * 
         * @return returns a boolean, true if the Systemimpl are equal, false otherwise.
         * 
         */
        bool operator==(const System& other) const;
};

class SystemHandle : public System , public Handle<Systemimpl>{
    public:

        virtual ~SystemHandle(){}

        SystemHandle(){
            pImpl_->setName("");
            pImpl_->setValue(0.0);
        }

        SystemHandle(double value){
            pImpl_->setName("");
            pImpl_->setValue(value);
        }

        SystemHandle(string name){
            pImpl_->setName(name);
            pImpl_->setValue(0.0);
        }

        SystemHandle(double value, string name){
            pImpl_->setName(name);
            pImpl_->setValue(value);
        }

        SystemHandle(System &system){
            pImpl_->setName(system.getName());
            pImpl_->setValue(system.getValue());
        }


        bool setValue(double value){
            return pImpl_->setValue(value);
        }
        double getValue() const{
            return pImpl_->getValue();
        }


        bool setName(string name){
            return pImpl_->setName(name);
        }
        const string getName() const{
            return pImpl_->getName();
        }

        bool operator==(const System& other) const{return pImpl_->operator==(other);}

};   

#endif