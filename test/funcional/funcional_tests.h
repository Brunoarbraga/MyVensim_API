#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

/**
 * @brief Exponential funtional test function.
 *
 * Given the Model class in the model.h file, the ExponentialFlow class in the derived_flows.h file, and
 * the System class in the system.h file, taking two system parameters with values 100 and 0, respectively,
 * and one ExponentialFlow parameter with value 0.0, when ran, this test simulates a systemic structure in a 100
 * unts of time (0-100 iteration), and returns:
 * 36.6032 as the system1 final value and 
 * 63.3968 as the system2 final value.
 * 
 * Then, if the final results are correct, matching the exponential test Vensim simulation, 
 * it prints a success message on terminal.
 * 
 */
bool exponentialFuncionalTest();

/**
 * @brief Logistical funtional test function.
 * 
 * Given the Model class in the model.h file, the LogisticalFlow class in the derived_flows.h file, and
 * the System class in the system.h file, taking two system parameters with values 100 and 10, respectively,
 * and one LogisticalFlow parameter with value 0.0857143, when ran, this test simulates a systemic structure in a 100
 * unts of time (0-100 iteration), and returns: 
 * 88.2167 as the system1 final value and 
 * 21.7833 as the system2 final value.
 * 
 * Then, if the final results are correct, matching the logistical test Vensim simulation, 
 * it prints a success message on terminal.
 * 
 */
bool logisticalFuncionalTest();


/**
 * @brief Complex funtional test function.
 *
 * Given the Model class in the model.h file, the ComplexFlow class in the derived_flows.h file, and
 * the System class in the system.h file, taking five System parameters with values 100, 0, 100, 0 and 0, respectively,
 * and six ComplexFlow parameters with values 0.0, all of them, when ran, this test simulates a systemic structure in a 100
 * unts of time (0-100 iteration), and returns: 
 * 31.8513 as the system1 final value, 
 * 18.4003 as the system2 final value,
 * 77.1143 as the system3 final value, 
 * 56.1728 as the system4 final value and 
 * 16.4612 as the system5 final value.
 * 
 * Then, if the final results are correct, matching the logistical test Vensim simulation, 
 * it prints a success message on terminal.
 * 
 */
bool complexFuncionalTest();

#endif
