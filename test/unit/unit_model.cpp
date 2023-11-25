#include "unit_model.h"
#include "../../src/model.h"


#include <cassert>

using namespace std;

void unit_model_default_constructor(){

    Model &m1 = Model::createModel();
    assert(m1.getName() == "");
    cout << "Model default constructor unit test passed" << endl;

    delete(&m1);

}

void unit_model_copy_constructor(){

    Model &m1 = Model::createModel();
    assert(m1.getName() == "");

   
    Model &m2 = Model::createModel(m1);

    Model::systemit system1_it = m1.system_begin();
    Model::systemit system1_end = m1.system_end();
    Model::flowit flow1_it = m1.flow_begin();
    Model::flowit flow1_end = m1.flow_end();

    Model::systemit system2_it = m2.system_begin();
    Model::flowit flow2_it = m2.flow_begin();

    while(system1_it != system1_end){

        assert(system1_it == system2_it);

        system1_it++;
        system2_it++;
    }

    while(flow1_it != flow1_end){

        assert(flow1_it == flow2_it);

        flow1_it++;
        flow2_it++;
    }

    assert(m2.getName() == m1.getName());

    cout << "Model copy constructor unit test passed" << endl;

    delete(&m1);

}

void unit_model_name_constructor(){

    Model &m3 = Model::createModel("model3");
    assert(m3.getName() == "model3");
    cout << "Model name constructor unit test passed" << endl;

    delete(&m3);

}

void unit_model_system_constructor(){

    Model &m1 = Model::createModel("model1");

    System &s1 = m1.createSystem();
    Model &m4 = Model::createModel(&s1);
    Model::systemit it = m4.system_begin();
    assert(*it == &s1);
    cout << "Model Systemimpl constructor unit test passed" << endl;

    delete(&s1);
    delete(&m4);
    delete(&m1);

}

void unit_model_flow_constructor(){

    Model &m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>();
    Model &m5 = Model::createModel(&f1);
    Model::flowit it2 = m5.flow_begin();
    assert(*it2 == &f1);
    cout << "Model Flow constructor unit test passed" << endl;

    delete(&f1);
    delete(&m5);
    delete(&m1);

}

void unit_model_complete_constructor(){

    Model &m1 = Model::createModel("model1");

    System &s2 = m1.createSystem();
    Flow &f2 = m1.createFlow<ExponentialFlow>();
    Model &m6 = Model::createModel("model6", &s2, &f2);
    Model::systemit it3 = m6.system_begin();
    Model::flowit it4 = m6.flow_begin();
    assert(m6.getName() == "model6");
    assert(*it3 == &s2);
    assert(*it4 == &f2);
    cout << "Model complete constructor unit test passed" << endl;

    delete(&s2);
    delete(&f2);
    delete(&m6);
    delete(&m1);


}

void unit_model_destructor(){}

void unit_model_add(){

    Model &m1 = Model::createModel("model1");

    // since create utilzes add inside of it, we can test by just creating.
    System &s1 = m1.createSystem();
    Flow &f1 = m1.createFlow<ExponentialFlow>();

    Model::systemit system_it = m1.system_begin();
    Model::flowit flow_it = m1.flow_begin();
    assert(*system_it == &s1);
    assert(*flow_it == &f1);

    cout << "Model add() unit test passed" << endl;

    delete(&f1);
    delete(&s1);
    delete(&m1);

}

void unit_model_remove(){

    Model &m1 = Model::createModel("model1");

    System &s1 =  m1.createSystem();
    Flow &f1 =  m1.createFlow<ExponentialFlow>();

    m1.remove(&s1);
    m1.remove(&f1);
    Model::systemit system_it = m1.system_begin();
    Model::systemit system_end = m1.system_end();
    Model::flowit flow_it = m1.flow_begin();
    Model::flowit flow_end = m1.flow_end();

    assert(system_it == system_end);
    assert(flow_it == flow_end);

    cout << "Model remove() unit test passed" << endl;

    delete(&f1);
    delete(&s1);
    delete(&m1);

}

void unit_model_system_begin(){

    Model &m1 = Model::createModel();

    System &s1 = m1.createSystem("system1");
    System &s2 = m1.createSystem("system2");


    assert(*(m1.system_begin()) == &s1);
    assert(*(m1.system_begin()) != &s2);

    delete(&s1);
    delete(&s2);
    delete(&m1);

    cout << "Model system_begin() unit test passed" << endl;
}

void unit_model_system_end(){

    Model &m1 = Model::createModel("model1");

    System &s1 = m1.createSystem("system1");
    System &s2 = m1.createSystem("system2");


    Model::systemit it = m1.system_begin();
    Model::systemit end = m1.system_end();

    int contador = 0;
    while(it != end){
        contador++;
        it++;
    }

    assert(contador == 2);

    Model &m2 = Model::createModel();
    assert(m2.system_begin() == m2.system_end());

    delete(&s1);
    delete(&s2);
    delete(&m1);
    delete(&m2);

    cout << "Model system_end() unit test passed" << endl;
}

void unit_model_flow_begin(){

    Model &m1 = Model::createModel("model1");
    
    Flow &f1 = m1.createFlow<ExponentialFlow>("f1", 0.0, nullptr, nullptr);
    Flow &f2 = m1.createFlow<ExponentialFlow>("f2", 10, nullptr, nullptr);


    assert(*(m1.flow_begin()) == &f1);
    assert(*(m1.flow_begin()) != &f2);

    cout << "Model flow_begin() unit test passed" << endl;

    delete(&f1);
    delete(&f2);
    delete(&m1);

}

void unit_model_flow_end(){

    Model &m1 = Model::createModel("model1");

    Flow &f1 = m1.createFlow<ExponentialFlow>("f1", 0.0, nullptr, nullptr);
    Flow &f2 = m1.createFlow<ExponentialFlow>("f2", 10, nullptr, nullptr);

    Model::flowit it = m1.flow_begin();
    Model::flowit end = m1.flow_end();

    int contador = 0;
    while(it != end){
        contador++;
        it++;
    }

    assert(contador == 2);

    Model &m2 = Model::createModel("model2");
    assert(m2.flow_begin() == m2.flow_end());

    delete(&f1);
    delete(&f2);
    delete(&m1);
    delete(&m2);

    cout << "Model flow_end() unit test passed" << endl;
}

void unit_model_run(){

    Model &m1 = Model::createModel("model1");

    // Since we want to test if run() method executes its loop correctly,
    // we just have to check if the method returns true, given that the function
    // only returns true if thats the case, a guard we put inside of it.
    assert((m1.run(50,100)) == true);

}


void run_unit_tests_model(){

    unit_model_default_constructor();
    unit_model_copy_constructor();
    unit_model_name_constructor();
    unit_model_system_constructor();
    unit_model_flow_constructor();
    unit_model_complete_constructor();
    unit_model_destructor();
    unit_model_add();
    unit_model_remove();
    unit_model_flow_begin();
    unit_model_flow_end();
    unit_model_system_begin();
    unit_model_system_end();
    unit_model_run();

}
