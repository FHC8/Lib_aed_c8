

#ifndef _TRIGGER_H_
#define _TRIGGER_H_
#include "patrones_c8_min.h"

#define conectarCon(x) agregar(&x)
#define activaClock(x) agregar(&x)

#define MAX_IOBS 4
#define checkIO(cant,obs) (cant < MAX_IOBS && obs != nullptr)
#define iterTo(x,cant) for(int x = 0; x < cant; x++)
#define copyNext(x,obs) obs[x] = obs[x + 1]
#define iterSince(x,y,cant) for (int y = x; y < cant - 1; y++)
#define def_observers(n) IObserver* observers[n]; \
    int cant = 0

class Trigger: public IObservable{
private:
    def_observers(MAX_IOBS);
public:
    int getCant(){ return cant; }
    void agregar(IObserver* observer) override { 
        if (checkIO(cant,observer)) { observers[cant++] = observer; } 
    }
    void remover(IObserver* observer) override {
        iterTo(i,cant) {
            if (observers[i] == observer) {
                iterSince(i,j,cant) { copyNext(j,observers); }
                cant--;
                break;
            }
        }
    }
    void notificar() override { 
        iterTo(i,cant) {
            if (observers[i] != nullptr) { observers[i]->serNotificadoPor(this); }
        }
    }
};

#endif
