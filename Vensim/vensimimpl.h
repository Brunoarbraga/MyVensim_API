#include "vensim.h"

class Vensimimpl : public Vensim{
    protected:
        static vector<Model*> modelVector;
    public:
        static Model& createModel(string name);
        static System& createSystem(string name, double value);
};