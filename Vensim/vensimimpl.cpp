#include "vensimimpl.h"

vector<Model*> modelVector;


//Implementação cria o model
Model& Vensimimpl::createModel(string name){
    Model* model = new Modelimpl(name);
    modelVector.push_back(model);
    return *model;
}

//Interface delega para a implementação
Model& Vensim::createModel(string name){
    return Vensimimpl::createModel(name);
}




//Implementação cria o system
System& Vensimimpl::createSystem(string name, double value){
    System* system = new Systemimpl(value, name);
    return *system;
}

//Iterface delega para a implementação
System& Vensim::createSystem(string name, double value){
    return Vensimimpl::createSystem(name, value);

}
