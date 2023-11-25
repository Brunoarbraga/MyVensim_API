#include "unit_test.h"
#include "unit_flow.h"
#include "unit_system.h"
#include "unit_model.h"

#include <iostream>

using namespace std;

int main(){

    cout << "--------------------------------" << endl;
    run_unit_tests_flow();

    cout << "--------------------------------" << endl;
    run_unit_tests_system();

    cout << "--------------------------------" << endl;
    run_unit_tests_model();

    cout << "--------------------------------" << endl;

    return 1;

}
