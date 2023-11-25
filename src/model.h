#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "flow.h"
#include "../test/derived_flows/derived_flows.h"




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
class Model {

    public:

        static Model& createModel(string name);
        virtual System& createSystem(string name, double value) = 0;
        virtual System& createSystem() = 0;
        virtual System& createSystem(string name) = 0;
        virtual System& createSystem(double value) = 0;
        virtual System& createSystem(System& system) = 0;

        
        template <typename T>
        Flow& createFlow(string name, double value, System* origin, System* destination){
            Flow* flow = new T(name, value, origin, destination);
            add(flow);
            return *flow;
        }

        template <typename T>
        Flow& createFlow(){
            Flow* flow = new T();
            add(flow);
            return *flow;
        }
        
        template <typename T>
        Flow& createFlow(Flow& f){
            Flow* flow = new T(f);
            add(flow);
            return *flow;
        }

        virtual ~Model(){};

        virtual const string getName() const = 0;
        virtual bool setName(string name) = 0;

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

        /**
         * @brief System iterator begin.
         *
         * Begins the iterator and returns its beginning.
         * 
         */
        virtual systemit system_begin() = 0;

        /**
         * @brief System iterator end.
         *
         * end the iterator and returns its endpoint.
         * 
         */
        virtual systemit system_end() = 0;

        /**
         * @brief Flow iterator begin.
         *
         * Begins the iterator and returns its beginning.
         * 
         */
        virtual flowit flow_begin() = 0;

        /**
         * @brief Flow iterator end.
         *
         * end the iterator and returns its endpoint.
         * 
         */
        virtual flowit flow_end() = 0;        

        /**
         * @brief add function for the model.
         *
         * Overloaded function to add a Flow to the Model. Adds it to the flowVector model atribute
         * via the push_back() method. 
         * 
         * @param flow flow to be added to the model, can be any of the flow derived classes 
         * 
         * @return reutrns a boolean value, true if the addition was successful, false otherwise.
         * Used to verify the integrity of the function call before moving on with the model simulation.
         * 
         */
        virtual bool add(Flow* flow) = 0;
 
        /**
         * @brief add function for the model.
         *
         * Overloaded function to add a System to the Model. Adds it to the systemVector model atribute
         * via the push_back() method. 
         * 
         * @param system System to be added to the Model.
         * 
         * @return reutrns a boolean value, true if the addition was successful, false otherwise. 
         * Used to verify the integrity of the function call before moving on with the model simulation.
         * 
         */            
        virtual bool add(System* system) = 0;


        virtual bool remove(Flow* flow) = 0;
        virtual bool remove(System* system) = 0;


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
        virtual bool run(int startTime, int endTime) = 0;

        /**
         * @brief printing function for the Model class.
         *
         * Function that prints on terminal all the model informations, that is, all the flows and its 
         * atributes, all the systems and its atributes, and the Model name.
         * 
         * Can be used to verify if the Model is looking as expected throughout the simulation, if needed.
         * 
         */
        virtual void printModel() = 0;

        /**
         * @brief Overload of equality operator.
         *
         * Checks if two Models are equal, considering all their atributes, including the ones inside the vectors.
         * 
         * @param other Model to be compared to the method calling Model for equality.
         * 
         * @return returns a boolean, true if the Models are equal, false otherwise.
         * 
         */
};

#endif