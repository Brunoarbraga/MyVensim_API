#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

//#include "../derived_flows/derived_flows.h"

void unit_model_default_constructor();
void unit_model_copy_constructor();
void unit_model_name_constructor();
void unit_model_system_constructor();
void unit_model_flow_constructor();
void unit_model_complete_constructor();

void unit_model_constructor();
void unit_model_destructor();
void unit_model_add();
void unit_model_remove();
void unit_model_run();
void unit_flow_begin();
void unit_flow_end();
void unit_system_begin();
void unit_system_end();
void unit_model_equals_operator();

void run_unit_tests_model();





#endif