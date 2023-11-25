#include "systemimpl.h"
#include "flowimpl.h"
#include "modelimpl.h"

#include <algorithm>

vector<Model*> Modelimpl::modelVector;

Model& Model::createModel(string name){
    return Modelimpl::createModel(name);
}

Model& Modelimpl::createModel(string name){
    Model *model = new Modelimpl(name);
    modelVector.push_back(model);
    return *model;
}





System& Modelimpl::createSystem(string name, double value){
    System *system = new Systemimpl(value, name);
    add(system);
    return *system;
}

System& Modelimpl::createSystem(){
    System *system = new Systemimpl();
    add(system);
    return *system;
}

System& Modelimpl::createSystem(string name){
    System *system = new Systemimpl(name);
    add(system);
    return *system;
}

System& Modelimpl::createSystem(double value){
    System *system = new Systemimpl(value);
    add(system);
    return *system;
}

System& Modelimpl::createSystem(System& s){
    System *system = new Systemimpl(s);
    add(system);
    return *system;
}




        
// Construtores de model
Modelimpl::Modelimpl() : name(""){}
Modelimpl::Modelimpl(string name) : name(name){}
Modelimpl::Modelimpl(System* systems) : name(""){
    systemVector.push_back(systems);
}
Modelimpl::Modelimpl(Flow* flows) : name(""){
    flowVector.push_back(flows);
}
Modelimpl::Modelimpl(string name, System* systems, Flow* flows) : name(name){
    systemVector.push_back(systems);
    flowVector.push_back(flows);
}
Modelimpl::~Modelimpl(){}
Modelimpl::Modelimpl(Model &model){
    
     name = model.getName();

    for(systemit it = system_begin(); it < system_end(); it++){
        add(*it);
    }


    for(flowit it = flow_begin(); it < flow_end(); it++){
        add(*it);
    }



}


const string Modelimpl::getName() const{
    return name;
}
bool Modelimpl::setName(string name){
    this->name = name;
    return true;
}




bool Modelimpl::add(Flow* flow){

    flowVector.push_back(flow);
    return true;

}

bool Modelimpl::add(System* system){

    systemVector.push_back(system);
    return true;

}

bool Modelimpl::remove(System *system){

    auto it = find(systemVector.begin(), systemVector.end(), system);

    if (it != systemVector.end()) {
        systemVector.erase(it);
        return true;
    } else {
        return false;
    }

}

bool Modelimpl::remove(Flow* flow){

    auto it = find(flowVector.begin(), flowVector.end(), flow);

    if (it != flowVector.end()) {
        flowVector.erase(it);
        return true;
    } else {
        return false;
    }

}

bool Modelimpl::run(int startTime, int endTime){

    System* origin_system;
    System* destination_system;

    int counter = 0;

    for(int time = startTime; time <= endTime; time++){

        counter++;

        for (auto flowPtr : flowVector) {
            flowPtr->setValue(flowPtr->run());
        }

        for(auto flowPtr : flowVector){
            
            
            origin_system = flowPtr->getOrigin();
            (*origin_system).setValue((*origin_system).getValue() - flowPtr->getValue());

            
            destination_system = flowPtr->getDestination();
            (*destination_system).setValue((*destination_system).getValue() + flowPtr->getValue());

        }

    }

    if(counter != (endTime - startTime) + 1)
        return false;

    // Descomentar se quiser ver os resultados
    //printModel();
    //cout << endl;
    return true;

}

void Modelimpl::printModel(){
    
    cout << "Modelimpl " << name << ":" << endl;

    for (vector<System*>::iterator it = systemVector.begin(); it != systemVector.end(); ++it) {
        cout << *(it) << endl;
    }


}

Modelimpl& Modelimpl::operator=(const Modelimpl& other) {

    if (this == &other) {
        return *this; 
    }

    systemVector.clear();
    flowVector.clear();


    for(auto systemPtr : other.systemVector){
        systemVector.push_back(systemPtr);
    }

    for(auto flowPtr : other.flowVector){
        flowVector.push_back(flowPtr);
    }

    name = other.name;

    return *this;
}


Modelimpl::systemit Modelimpl::system_begin(){
    return systemVector.begin();
}

Modelimpl::systemit Modelimpl::system_end(){
    return systemVector.end();
}


Modelimpl::flowit Modelimpl::flow_begin(){
    return flowVector.begin();
}

Modelimpl::flowit Modelimpl::flow_end(){
    return flowVector.end();
}

