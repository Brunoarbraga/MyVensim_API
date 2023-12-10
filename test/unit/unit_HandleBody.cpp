#include "../../src/model.h"
#include "../../src/systemimpl.h"
#include <cassert>

int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

void unit_HandleBody(){
    

    // Apenas a implementacao da classe "Flux" precisa ser conhecida na
    // fase de "cria��o de objetos", pois o usu�rio precisa implementar 
    // v�rios tipos de fluxo. Ent�o, o m�dulo de cria��o de objetos precisa
    // conhecer os fluxos implementados pelo usu�rio.No entanto, nenhuma outra 
    // implementa��o precisa ser conhecida por qq outro m�dulo.
    
    // Cria modelo
    Model& m = Model::createModel("Modelo de Pop.");      
    m.createFlow<ExponentialFlow>();    

    // USANDO REFERENCIAS PARA INTERFACE (CLASSE ABSTRATA)
    //System& s1 = m.createSystem("populacao",10.0);
    //System& s2 = m.createSystem("Teste", 7.90)   ;
    //cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;
    //s1 = s2;  // nao funciona pq s1 � uma referencia, portanto nao pode ser redefinida
    //cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;    
    
    // USANDO PONTEIROS PARA INTERFACE (CLASSE ABSTRATA)
    System* s1 = &m.createSystem("populacao",10.0);
    System* s2 = &m.createSystem("Teste", 7.90)   ;
    cout << "s1: " << s1->getName() << ", s2: " <<  s2->getName() << endl;
    s1 = s2;
    //*s1 = *s2;
    cout << "s1: " << s1->getName() << ", s2: " <<  s2->getName() << endl;    
    cout << "s1: " << s1 << ", s2: " <<  s2 << endl;    
    
    
    // Fa�a o teste COM e SEM as chaves abaixo

{
    // USANDO OBJETOS HANDLES (DELEGA��O)
    SystemHandle s3(7, "Tiago"), s4(8, "Antonio");
    cout << "s3: " << s3.getName() << ", s2: " <<  s4.getName() << endl;
    s3 = s4;  // comente esta linha e veja que o resultado muda
    cout << "s3: " << s4.getName() << ", s2: " <<  s4.getName() << endl;        
	s3 = s3;
	cout << "s3: " << s4.getName() << ", s2: " <<  s4.getName() << endl;        
}

    
    //m.run(0,30);
    // imprime relatorio
    //cout << s1->getValue() << endl;

    assert(numHandleCreated == 6);
    assert(numBodyCreated == 6);

    delete(&m);

    assert(numHandleDeleted == 6);
    assert(numBodyDeleted == 6);
   

    
    cout << "Created handles: "  << numHandleCreated << endl;
    cout << "Deleted handles: "  << numHandleDeleted << endl;    
    cout << "Created bodies: "  << numBodyCreated << endl;
    cout << "Deleted bodies: "  << numBodyDeleted << endl;


}

void run_unit_tests_HandleBody(){

    unit_HandleBody();

}