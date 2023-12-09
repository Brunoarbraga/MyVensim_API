#include "systemimpl.h"

Systemimpl::Systemimpl() : value(0.0), name(""){}
Systemimpl::Systemimpl(double value) : value(value), name(""){}
Systemimpl::Systemimpl(string name) : value(0.0), name(name) {}
Systemimpl::Systemimpl(double value, string name) : value(value), name(name){}

Systemimpl::~Systemimpl(){}

Systemimpl::Systemimpl(System &system){
    name = system.getName();
    value = system.getValue();
}


double Systemimpl::getValue() const{
    return value;
}
bool Systemimpl::setValue(double value){
    this->value = value;
    return true;
}

const string Systemimpl::getName() const{
    return name;
}
bool Systemimpl::setName(string name){
    this->name = name;
    return true;
}

ostream& operator<<(ostream& os, const Systemimpl& system) {
    os << "Systemimpl " << system.getName() << ": "<< system.value; // Replace 'someMember' with the actual member you want to print
    return os;
}

// Sobrecarga operador de atribuição
Systemimpl& Systemimpl::operator=(const Systemimpl& other) {
    
    if (this == &other) {
        return *this; 
    }

    value = other.getValue();
    name = other.getName();

    return *this;
}

// Sobrecarga operador igual
bool Systemimpl::operator==(const System& other) const{
    return (value == other.getValue()) && (name == other.getName());
}
