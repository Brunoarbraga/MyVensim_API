#include "unit_flow.h"
#include "../../src/model.h"

#include <cassert>

void unit_flow_default_constructor(){

    Model& m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>("ExponentialFlow", 0.0, nullptr, nullptr);
    assert(f1.getValue() == 0.0);
    cout << "Flow default constructor unit test passed" << endl;

}

void unit_flow_copy_constructor(){

    Model& m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>();
    assert(f1.getValue() == 0.0);

    Flow &f2 = m1.createFlow<ExponentialFlow>(f1);
    assert(f2.getName() == f1.getName());
    assert(f2.getValue() == f1.getValue());
    assert(f2.getOrigin() == f1.getOrigin());
    assert(f2.getDestination() == f1.getDestination());

    cout << "Flow copy constructor unit test passed" << endl;

}

void unit_flow_complete_constructor(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem("system1", 10);
    System &s2 = m1.createSystem("system2", 20);
    Flow &f3 = m1.createFlow<ExponentialFlow>("flow1", 50, &s1, &s2);

    assert(f3.getName() == "flow1");
    assert(f3.getValue() == 50);
    assert((f3.getOrigin()) == &s1);
    assert((f3.getDestination()) == &s2);

    cout << "Flow complete constructor unit test passed" << endl;


}  

void unit_flow_destructor(){}

void unit_flow_getValue(){

    Model& m1 = Model::createModel("model1");

    Flow& f1 = m1.createFlow<ExponentialFlow>("f1", 100, nullptr, nullptr);
    double value = f1.getValue();
    assert(value == 100);
    cout << "Flow getValue() unit test passed" << endl;


}
void unit_flow_setValue(){

    Model& m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>();
    f1.setValue(50);
    assert(f1.getValue() == 50);
    cout << "Flow setValue() unit test passed" << endl;


}

void unit_flow_getName(){

    Model& m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>("flow1", 0, nullptr, nullptr);
    string name = f1.getName();
    assert(name == "flow1");
    cout << "Flow getName() unit test passed" << endl;


}
void unit_flow_setName(){

    Model& m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>();
    f1.setName("flow1");
    assert(f1.getName() == "flow1");
    cout << "Flow setName() unit test passed" << endl;


}
void unit_flow_setOrigin(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem();
    Flow &f1 = m1.createFlow<ExponentialFlow>();
    f1.setOrigin(&s1);
    assert((f1.getOrigin()) == &s1);
    cout << "Flow setOrigin() unit test passed" << endl;


}
void unit_flow_getOrigin(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem();
    Flow &f1 = m1.createFlow<ExponentialFlow>("flow1", 0, &s1, nullptr);
    System &s2 = m1.createSystem(*(f1.getOrigin()));
    assert(s1 == s2);
    cout << "Flow getOrigin() unit test passed" << endl;

    
}
void unit_flow_setDestination(){

    Model& m1 = Model::createModel("model1");
    
    System &s1 = m1.createSystem();
    Flow &f1 = m1.createFlow<ExponentialFlow>();
    f1.setDestination(&s1);
    assert((f1.getDestination()) == &s1);
    cout << "Flow setDestination() unit test passed" << endl;


}
void unit_flow_getDestination(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem();
    Flow &f1 = m1.createFlow<ExponentialFlow>("flow1", 0, nullptr, &s1);
    System &s2 = m1.createSystem(*(f1.getDestination()));
    assert(s1 == s2);
    cout << "Flow getDestination() unit test passed" << endl;


}
void unit_flow_atribution_operator(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem("system1", 100), &s2 = m1.createSystem("system2", 50);
    Flow &f1 = m1.createFlow<ExponentialFlow>("flow1", 10, &s1, &s2);
    Flow &f2 = m1.createFlow<ExponentialFlow>();
    f2 = f1;
    assert(f2.getName() == "flow1");
    assert(f2.getValue() == 10);
    assert((f2.getOrigin()) == &s1);
    assert((f2.getDestination()) == &s2);
    cout << "Flow atribution operator unit test passed" << endl;


}
void unit_flow_equals_operator(){

    Model& m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>("flow1", 10, nullptr, nullptr), &f2 = m1.createFlow<ExponentialFlow>("flow1", 10, nullptr, nullptr);
    assert(f1 == f2);
    cout << "Flow equals operator unit test passed" << endl;

}

void run_unit_tests_flow(){

    unit_flow_default_constructor();
    unit_flow_copy_constructor();
    unit_flow_complete_constructor();
    unit_flow_destructor();
    unit_flow_setValue();
    unit_flow_getValue();
    unit_flow_setName();
    unit_flow_getName();
    unit_flow_setOrigin();
    unit_flow_getOrigin();
    unit_flow_setDestination();
    unit_flow_getDestination();
    unit_flow_atribution_operator();
    unit_flow_equals_operator();

}