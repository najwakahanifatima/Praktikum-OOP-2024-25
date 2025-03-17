#include "RekeningGiro.h"

RekeningGiro::RekeningGiro(double saldo, double sb){
    Rekening::Rekening(saldo);
    if (sb < 0){
        sb = 0.0;
    } else {
        sukuBunga = sb;
    }
}

