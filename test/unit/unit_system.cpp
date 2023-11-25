#include "unit_system.h"
#include <cassert>

void unit_system_default_constructor(){

    System *s1 = new Systemimpl;
    assert(s1->getValue() == 0);
    cout << "Systemimpl default constructor unit test passed" << endl;    

    delete(s1);

}

void unit_system_copy_constructor(){
    System *s1 = new Systemimpl;
    assert(s1->getValue() == 0);

    System *s2 = new Systemimpl(*s1);
    assert(*s2 == *s1);
    cout << "Systemimpl copy constructor unit test passed" << endl;

    delete(s1);
}

void unit_system_value_constructor(){
    
    System *s3 = new Systemimpl(10);
    assert(s3->getValue() == 10);
    cout << "Systemimpl value constructor unit test passed" << endl;

    delete(s3);

}

void unit_system_name_constructor(){
   
    System *s4 = new Systemimpl("system4");
    assert(s4->getName() == "system4");
    cout << "Systemimpl name constructor unit test passed" << endl;

    delete(s4);

}

void unit_system_complete_constructor(){
    
    System *s5 = new Systemimpl(20, "system5");
    assert(s5->getValue() == 20);
    assert(s5->getName() == "system5");
    
    cout << "Systemimpl complete constructor unit test passed" << endl;

    delete(s5);

}

void unit_system_destructor(){}

void unit_system_getValue(){
    System *s1= new Systemimpl(100);
    double value = s1->getValue();
    assert(value == 100);
    cout << "Systemimpl getValue() unit test passed" << endl;

    delete(s1);
}

void unit_system_setValue(){
    System *s1= new Systemimpl();
    s1->setValue(50);
    assert(s1->getValue() == 50);
    cout << "Systemimpl setValue() unit test passed" << endl;

    delete(s1);
}

void unit_system_getName(){
    System *s1= new Systemimpl("system1");
    string name = s1->getName();
    assert(name == "system1");
    cout << "Systemimpl getName() unit test passed" << endl;

    delete(s1);
}

void unit_system_setName(){
    System *s1= new Systemimpl();
    s1->setName("system1");
    assert(s1->getName() == "system1");
    cout << "Systemimpl setName() unit test passed" << endl;

    delete(s1);
}

void unit_system_atribution_operator(){
    System *s1 = new Systemimpl(30, "system1");
    System *s2 = new Systemimpl();
    s2 = s1;
    assert(s2->getName() == "system1");
    assert(s2->getValue() == 30);
    cout << "Systemimpl atribution operator unit test passed" << endl;

    delete(s1);
}

void unit_system_equals_operator(){
    System *s1 = new Systemimpl(10, "system"), *s2 = new Systemimpl(10, "system");
    assert(*s1 == *s2);
    cout << "Systemimpl equals operator unit test passed" << endl;

    delete(s1);
    delete(s2);
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
