#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Represents the System.
 *
 * This class represents the real life systems and its phenomena, storing its energy (value),
 * that could be altered through the course of time in the simulation. e.g. Respiratory system, cardiovascular system. 
 * 
 * Systems can exist independently from any other structure in the simulation.
 * 
 */
class System {

    public:

        /**
         * @brief System virtual destructor.
         *
         * Destructs the system, freeing its memory allocation.
         * 
         */
        virtual ~System(){};

        /**
         * @brief Getter function for the value.
         * 
         * Gets the current value of the system and returns it to the user.
         *
         * @return The current double value.
         * Can be used to evaluate the flow, and to update the system's value
         *
         */
        virtual double getValue() const = 0;

        /**
         * @brief Setter function for the value.
         * 
         * Sets the value of the system and returns success or failure.
         * Can be used to update the System's value when the simulation is ran.
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
         * Gets the current name of the system and returns it to the user.
         *
         * @return The current string name, the return value is constant to assure it wont
         * be modified in the process
         *
         */
        virtual const string getName() const = 0;

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
        virtual bool setName(string name) = 0;

        /**
         * @brief System << operator overload.
         * 
         * Overloads the << cout operator so that the system can be printed on terminal (its name and value).
         * Used only by the printModel() method, since it prints all the systems it contains.
         *
         * @param system system to be printed
         *
         */
        friend ostream& operator<<(ostream& os, const System& system);

        /**
         * @brief System's atribution operator overload.
         *
         * Atributes one System to another, that is, copies all of its informations (name and value)
         * and atributes them to the left-side System atributes.
         * 
         * @param other System to be atributed to the left-side of the operator System  
         * 
         * @return returns a System memory adress
         * 
         */
        virtual System& operator=(const System& other) = 0;

        /**
         * @brief Overload of equality operator for System.
         *
         * Checks if two Systems are equal, considering all their atributes.
         * 
         * @param other System to be compared to the left-side of the operator System.
         * 
         * @return returns a boolean, true if the System are equal, false otherwise.
         * 
         */
        virtual bool operator==(const System& other) const = 0;
};

#endif