
float estimatePower(short int inputSample, float decayCoeff, float prevPower) {

    float estPower;

    estPower = decayCoeff*inputSample*inputSample;

    estPower = estPower + (1-decayCoeff)*prevPower;

    return estPower;

}
