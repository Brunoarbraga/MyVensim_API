#include "../src/flowimpl.h"
#include "../src/systemimpl.h"
#include "../src/modelimpl.h"

class Vensim{
    public:
        static Model& createModel(string name);
        static System& createSystem(string name, double value);
};