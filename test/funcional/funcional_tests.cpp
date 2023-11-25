#include "funcional_tests.h"
#include "../../src/model.h"
//#include "../derived_flows/derived_flows.h"


#include <cassert>
#include <cmath>

bool exponentialFuncionalTest(){
    
    Model& m1 = Model::createModel("model1");
    System &pop1 = m1.createSystem("pop1", 100);
    System &pop2 = m1.createSystem("pop2", 0); 
    Flow &f1 = m1.createFlow<ExponentialFlow>("ExponentialFlow", 0.0, &pop1, &pop2);

  
    m1.run(1,100);

    //cout << (pop1.getValue() - 36.6032)*1000 << endl;

    assert(trunc(fabs(pop1.getValue() - 36.6032)*1000) < 1);
    assert(trunc(fabs(pop2.getValue() - 63.3968)*1000) < 1);

    cout << "Passed 100 iterations exponential test" << endl;


    delete(&f1);
    delete(&pop1);
    delete(&pop2);
    delete(&m1);

    return true;
}

bool logisticalFuncionalTest(){

    Model &m2 = Model::createModel("model2");
    System &p1 = m2.createSystem("p1", 100);
    System &p2 = m2.createSystem("p2", 10);
    Flow &f1 = m2.createFlow<LogisticalFlow>("LogisticalFlow", 0.0857143, &p1, &p2); 

    m2.run(1,100);

    assert(trunc(fabs(p1.getValue() - 88.2167)*1000) < 1);
    assert(trunc(fabs(p2.getValue() - 21.7833)*1000) < 1);

    cout << "Passed 100 iterations logistical test" << endl;

    delete(&f1);
    delete(&p1);
    delete(&p2);
    delete(&m2);

    return true;
    
}

bool complexFuncionalTest(){

    
    Model &m3 = Model::createModel("model3");

    System &Q1 = m3.createSystem("Q1", 100.0);
    System &Q2 = m3.createSystem("Q2", 0);
    System &Q3 = m3.createSystem("Q3", 100);
    System &Q4 = m3.createSystem("Q4", 0.0);
    System &Q5 = m3.createSystem("Q5", 0.0);

    Flow &v = m3.createFlow<ComplexFlow>("v", 0.0, &Q4, &Q1);
    Flow &u = m3.createFlow<ComplexFlow>("u", 0.0, &Q3, &Q4);
    Flow &g = m3.createFlow<ComplexFlow>("g", 0.0, &Q1, &Q3);
    Flow &f = m3.createFlow<ComplexFlow>("f", 0.0, &Q1, &Q2);
    Flow &t = m3.createFlow<ComplexFlow>("t", 0.0, &Q2, &Q3);
    Flow &r = m3.createFlow<ComplexFlow>("r", 0.0, &Q2, &Q5);

    m3.run(1, 100);

    assert(trunc(fabs(Q1.getValue() - 31.8513)*1000) < 1);
    assert(trunc(fabs(Q2.getValue() - 18.4003)*1000) < 1);
    assert(trunc(fabs(Q3.getValue() - 77.1143)*1000) < 1);
    assert(trunc(fabs(Q4.getValue() - 56.1728)*1000) < 1);
    assert(trunc(fabs(Q5.getValue() - 16.4612)*1000) < 1);

    cout << "Passed 100 iterations complex test" << endl;
    

    delete(&v);
    delete(&u);
    delete(&g);
    delete(&f);
    delete(&t);
    delete(&r);

    delete(&Q1);
    delete(&Q2);
    delete(&Q3);
    delete(&Q4);
    delete(&Q5);

    delete(&m3);

    return true;

}