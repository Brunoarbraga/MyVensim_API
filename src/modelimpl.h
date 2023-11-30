#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"


/**
 * @brief Represents the model.
 *
 * This class represents the environment in which the systems take place,
 * storing all the systems and their interactions (flows) with each other. 
 * 
 * Can be ran to simulate real world systemic structures through the systems stored inside it,  
 * keeping track of the time and values while doing it.
 * 
 */
class Modelimpl : public Model {

    protected:

        static vector<Model*> modelVector;

        /**
         * @brief The model's system vector.
         *
         * This atribute represents all of the systems contained insed the Modelimpl.
         * Stores the pointers to the systems.
         * Systems can be added and removed from this vector at will.
         * 
         * 
         */
        vector<System*> systemVector;

        /**
         * @brief The model's flow vector.
         *
         * This atribute represents all of the flows (interactions) contained insed the Modelimpl.
         * Stores the pointers to the flows.
         * flows can be added and removed from this vector at will.
         * 
         * 
         */
        vector<Flow*> flowVector;

        /**
         * @brief The model's name.
         *
         * This represents the Modelimpl's name, is set to "" by default, and can be
         * changed at any given time by the user.
         * 
         */
        string name;

        /**
         * @brief Modelimpl's atribution operator overload.
         *
         * Atributes one Modelimpl to another, that is, copies all of its informations
         * and atributes them to the left-side model atributes.
         * 
         * This overload is set as private to prevent illegal pointer operations
         * possibly caused by the flows a systems vectors when making a copy. Due
         * to same memory loaction pointing.
         * 
         * @param other Modelimpl to be atributed to the left-side of the operator Modelimpl  
         * 
         * @return returns a Modelimpl memory adress
         * 
         */
        Modelimpl& operator=(const Modelimpl& other);

    public:


        static Model& createModel();
        static Model& createModel(string name);
        static Model& createModel(System* systems);
        static Model& createModel(Flow* flows);
        static Model& createModel(string name, System* systems, Flow* flows);
        static Model& createModel(Model& copiedModel);

        System& createSystem(string name, double value);
        System& createSystem();
        System& createSystem(string name);
        System& createSystem(double value);
        System& createSystem(System& system);


        /**
         * @brief Modelimpl default constructor.
         *
         * Instances a Modelimpl object with an empty string "" name atribute if no parameter is passed.
         * 
         */
        Modelimpl();

        /**
         * @brief Copy constructor for Modelimpl.
         *
         * Makes a deep copy of a given Modelimpl, to the method calling Modelimpl.
         * Copies every atribute, including the pointers inside the vectors.
         * 
         * @param model Modelimpl to be copied.
         * 
         */
        Modelimpl(Model &model);

        /**
         * @brief Modelimpl constructor override with name parameter.
         *
         * Intances a Modelimpl atributing the string parameter given to the Modelimpl name atribute.
         * 
         * @param name string name to be atributed to the Modelimpl being instanced.
         * 
         */
        Modelimpl(string name);

        /**
         * @brief Modelimpl constructor override with System parameter.
         *
         * Intances a Modelimpl with the systems passed as parameters.
         * Includes those systems in the Modelimpl systemVector.
         * 
         * @param systems systems pointer that will be included in the vector.
         * 
         */
        Modelimpl(System* systems);

         /**
         * @brief Modelimpl constructor override with flows parameter.
         *
         * Intances a Modelimpl with the flows passed as parameters.
         * Includes those floes in the Modelimpl flowVector.
         * 
         * @param flows flows pointer that will be included in the vector.
         * 
         */
        Modelimpl(Flow* flows);

         /**
         * @brief Complete Modelimpl constructor.
         *
         * Intances a Modelimpl with all the atributes passed as parameters.
         * All the atributes that the class Modelimpl has are going to be "filled".
         * 
         * @param name string name to be atributed to the Modelimpl being instanced.
         * 
         * @param systems systems pointer that will be included in the vector.
         * 
         * @param flows flows pointer that will be included in the vector.
         * 
         */
        Modelimpl(string name, System* systems, Flow* flows);

        /**
         * @brief Modelimpl virtual destructor.
         *
         * Destructs the model, freeing its memory allocation.
         * 
         */
        virtual ~Modelimpl();

        const string getName() const;
        bool setName(string name);

        /**
         * @brief Definition of the systemVector iterator.
         *
         * Its better to use iterators instead of specific data structure containers, since
         * those are of programmers choice of implementation, meaning that if we use a vector here,
         * and the programmer using the API decides to use another data structure, the API wont work as exprected.
         * 
         */
        typedef vector<System*>::iterator systemit;

        /**
         * @brief Definition of the flowVector iterator.
         *
         * Its better to use iterators instead of specific data structure containers, since
         * those are of programmers choice of implementation, meaning that if we use a vector here,
         * and the programmer using the API decides to use another data structure, the API wont work as exprected.
         * 
         */
        typedef vector<Flow*>::iterator flowit;

        typedef vector<Model*>::iterator modelit;

        modelit model_begin();
        modelit model_end();

        /**
         * @brief System iterator begin.
         *
         * Begins the iterator and returns its beginning.
         * 
         */
        systemit system_begin();

        /**
         * @brief System iterator end.
         *
         * end the iterator and returns its endpoint.
         * 
         */
        systemit system_end();

        /**
         * @brief Flow iterator begin.
         *
         * Begins the iterator and returns its beginning.
         * 
         */
        flowit flow_begin();

        /**
         * @brief Flow iterator end.
         *
         * end the iterator and returns its endpoint.
         * 
         */
        flowit flow_end();        

        /**
         * @brief add function for the model.
         *
         * Overloaded function to add a Flow to the Modelimpl. Adds it to the flowVector model atribute
         * via the push_back() method. 
         * 
         * @param flow flow to be added to the model, can be any of the flow derived classes 
         * 
         * @return reutrns a boolean value, true if the addition was successful, false otherwise.
         * Used to verify the integrity of the function call before moving on with the model simulation.
         * 
         */
        bool add(Flow* flow);
 
        /**
         * @brief add function for the model.
         *
         * Overloaded function to add a System to the Modelimpl. Adds it to the systemVector model atribute
         * via the push_back() method. 
         * 
         * @param system System to be added to the Modelimpl.
         * 
         * @return reutrns a boolean value, true if the addition was successful, false otherwise. 
         * Used to verify the integrity of the function call before moving on with the model simulation.
         * 
         */            
        bool add(System* system);


        bool remove(Flow* flow);
        bool remove(System* system);


        /**
         * @brief Run function for the model.
         *
         * This function causes the model to run, evaluating the flow values inside it,
         * and updating its systems values accordingly within each iteration, given the starTime  
         * and endTime of the model simulation.
         *  
         * @param startTime time for the model to start running
         * 
         * @param endTime time for the model to stop running
         * 
         */
        bool run(int startTime, int endTime);

        /**
         * @brief printing function for the Modelimpl class.
         *
         * Function that prints on terminal all the model informations, that is, all the flows and its 
         * atributes, all the systems and its atributes, and the Modelimpl name.
         * 
         * Can be used to verify if the Modelimpl is looking as expected throughout the simulation, if needed.
         * 
         */
        void printModel();

        /**
         * @brief Overload of equality operator.
         *
         * Checks if two Models are equal, considering all their atributes, including the ones inside the vectors.
         * 
         * @param other Modelimpl to be compared to the method calling Modelimpl for equality.
         * 
         * @return returns a boolean, true if the Models are equal, false otherwise.
         * 
         */
};

#endif