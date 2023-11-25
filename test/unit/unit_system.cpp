#include "unit_system.h"
#include "../../src/model.h"

#include <cassert>

void unit_system_default_constructor(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem();
    assert(s1.getValue() == 0);
    cout << "Systemimpl default constructor unit test passed" << endl;    

    delete(&s1);
    delete(&m1);

}

void unit_system_copy_constructor(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem();
    assert(s1.getValue() == 0);

    System &s2 = m1.createSystem(s1);
    assert(s2 == s1);
    cout << "Systemimpl copy constructor unit test passed" << endl;

    delete(&s1);
    delete(&m1);

}

void unit_system_value_constructor(){
    
    Model& m1 = Model::createModel("model1");

    System &s3 = m1.createSystem(10);
    assert(s3.getValue() == 10);
    cout << "Systemimpl value constructor unit test passed" << endl;

    delete(&s3);
    delete(&m1);

}

void unit_system_name_constructor(){
   
    Model& m1 = Model::createModel("model1");
   

    System &s4 = m1.createSystem("system4");
    assert(s4.getName() == "system4");
    cout << "Systemimpl name constructor unit test passed" << endl;

    delete(&s4);
    delete(&m1);

}

void unit_system_complete_constructor(){
    
    Model& m1 = Model::createModel("model1");

    System &s5 = m1.createSystem("system5", 20);
    assert(s5.getValue() == 20);
    assert(s5.getName() == "system5");
    
    cout << "Systemimpl complete constructor unit test passed" << endl;

    delete(&s5);
    delete(&m1);

}

void unit_system_destructor(){}

void unit_system_getValue(){

    Model& m1 = Model::createModel("model1");

    System &s1= m1.createSystem(100);
    double value = s1.getValue();
    assert(value == 100);
    cout << "Systemimpl getValue() unit test passed" << endl;

    delete(&s1);
    delete(&m1);

}

void unit_system_setValue(){

    Model& m1 = Model::createModel("model1");

    System &s1= m1.createSystem();
    s1.setValue(50);
    assert(s1.getValue() == 50);
    cout << "Systemimpl setValue() unit test passed" << endl;

    delete(&s1);
    delete(&m1);

}

void unit_system_getName(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem("system1");
    string name = s1.getName();
    assert(name == "system1");
    cout << "Systemimpl getName() unit test passed" << endl;

    delete(&s1);
    delete(&m1);

}

void unit_system_setName(){

    Model& m1 = Model::createModel("model1");

    System &s1= m1.createSystem();
    s1.setName("system1");
    assert(s1.getName() == "system1");
    cout << "Systemimpl setName() unit test passed" << endl;

    delete(&s1);
    delete(&m1);

}

void unit_system_atribution_operator(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem("system1", 30);
    System &s2 = m1.createSystem();
    s2 = s1;
    assert(s2.getName() == "system1");
    assert(s2.getValue() == 30);
    cout << "Systemimpl atribution operator unit test passed" << endl;

    delete(&s1);
    delete(&m1);

}

void unit_system_equals_operator(){

    Model& m1 = Model::createModel("model1");

    System &s1 = m1.createSystem("system", 10), &s2 = m1.createSystem("system", 10);
    assert(s1 == s2);
    cout << "Systemimpl equals operator unit test passed" << endl;

    delete(&s1);
    delete(&s2);
    delete(&m1);

}

void run_unit_tests_system(){

    unit_system_default_constructor();
    unit_system_copy_constructor();
    unit_system_value_constructor();
    unit_system_name_constructor();
    unit_system_complete_constructor();
    unit_system_destructor();
    unit_system_getValue();
    unit_system_setValue();
    unit_system_getName();
    unit_system_setName();
    unit_system_atribution_operator();
    unit_system_equals_operator();

}
