#include "flowimpl.h"


// Construtores do flow
Flowimpl::~Flowimpl(){}
Flowimpl::Flowimpl() : name(""), value(0.0), origin(nullptr), destination(nullptr){}
Flowimpl::Flowimpl(string name, double value, System* origin, System* destination) : name(name), value(value), origin(origin), destination(destination){}
Flowimpl::Flowimpl(Flow &flow) {

    name = flow.getName();
    value = flow.getValue();
    origin = flow.getOrigin();
    destination = flow.getDestination();

}


// Getters e setters do flow
bool Flowimpl::setOrigin(System* origin){
    this->origin = origin;
    return true;
}
bool Flowimpl::setDestination(System* destination){
    this->destination = destination;
    return true;
}
System* Flowimpl::getOrigin() const{
    return origin;
}
System* Flowimpl::getDestination() const{
    return destination;
}
bool Flowimpl::setName(string name){
    this->name = name;
    return true;
}
bool Flowimpl::setValue(double value){
    this->value = value;
    return true;
}
string Flowimpl::getName() const{
    return name;
}
double Flowimpl::getValue() const{
    return value;
}



// Sobrecarga do operador de igualdade
bool Flowimpl::operator==(const Flow& other) const{
    return (name == other.getName()) && (value == other.getValue()) && (origin == other.getOrigin()) && (destination == other.getDestination());
}


