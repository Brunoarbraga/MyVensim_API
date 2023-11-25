#include "derived_flows.h"

// Construtores do exponential Flowimpl
ExponentialFlow::ExponentialFlow():Flowimpl() {}
ExponentialFlow::ExponentialFlow(string name, double value, System* origin, System* destination):Flowimpl(name, value, origin, destination) {}
ExponentialFlow::ExponentialFlow(Flow& flow) : Flowimpl(flow){}

// sobrescrita do run para o exponential Flowimpl
double ExponentialFlow::run(){

    return 0.01 * getOrigin()->getValue();

}



// Construtores do logistical Flowimpl
LogisticalFlow ::LogisticalFlow():Flowimpl() {}
LogisticalFlow ::LogisticalFlow(string name, double value, System* origin, System* destination) : Flowimpl(name, value, origin, destination) {}
LogisticalFlow ::LogisticalFlow(Flow& flow) : Flowimpl(flow){}

// sobrescrita do run para o logistical Flowimpl
double LogisticalFlow ::run(){

    double value = getDestination()->getValue();
    return 0.01 * value * (1 - value / 70);

}


// Construtores do complex Flowimpl
ComplexFlow ::ComplexFlow():Flowimpl() {}
ComplexFlow ::ComplexFlow(string name, double value, System* origin, System* destination) : Flowimpl(name, value, origin, destination) {}
ComplexFlow ::ComplexFlow(Flow& flow) : Flowimpl(flow){}

// sobrescrita do run para o logistical Flowimpl
double ComplexFlow ::run(){

    return 0.01 * getOrigin()->getValue();

}

