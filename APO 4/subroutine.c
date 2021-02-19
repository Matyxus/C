#include "subroutine.h"

int subroutine_fnc(int x){
    if (x < 91 && x >= 65){
        return (x+32);
    }
    return x;
}
