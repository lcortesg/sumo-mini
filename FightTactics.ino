/**
 * @function
 */
 

bool searchPID(){
    measure = ((enemy_sensor_left + enemy_sensor_front + enemy_sensor_right) == 0)?(measure):(enemy_sensor_left*1000 + enemy_sensor_front*2000 + enemy_sensor_right*3000)/(enemy_sensor_left + enemy_sensor_front + enemy_sensor_right);
    #if DEBUG > NONE
        Serial.print("\n>>> LOG: measure:\t");
        Serial.println(measure);
    #endif
        error = ref - measure;
    #if DEBUG > NONE
        Serial.print("\n>>> LOG: error:\t");
        Serial.println(error);
    #endif  
        error_int += (actuation >= POWER_MAX)?(0):(error);
    #if DEBUG > NONE
        Serial.print("\n>>> LOG: error int:\t");
        Serial.println(error_int);
    #endif  
        error_dev = error - error_prev;
    #if DEBUG > NONE
        Serial.print("\n>>> LOG: error_dev:\t");
        Serial.println(error_dev);
    #endif  
        error_prev = error;
    #if DEBUG > NONE
        Serial.print("\n>>> LOG: error_prev:\t");
        Serial.println(error_prev);
    #endif
        actuation = (error*KP + error_int*KI + error_dev*KD);
        actuation = (actuation >= POWER_MAX)?(POWER_MAX):(actuation <= -POWER_MAX)?(-POWER_MAX):(actuation);
    #if DEBUG > NONE
        Serial.print("\n>>> LOG: actuation:\t");
        Serial.println(actuation);
    #endif
        if(abs(actuation) > 50){
            digitalWrite(MOTOR_LEFT_A, 0);
            digitalWrite(MOTOR_LEFT_B, actuation);
            digitalWrite(MOTOR_RIGHT_A, 0);
            digitalWrite(MOTOR_RIGHT_B, actuation);
       
        }
    return ( (enemy_sensor_front == 1) && (abs(actuation) < 50) );
}


void fight(){
    switch(tactic){
        case 1 : {
            fight1();
        break;
        }  
        default : {
            fight1();
        break;  
        }
    }
    return;  
}

void fight1(){
    
    pinMode(MOTOR_LEFT_A, OUTPUT);
    pinMode(MOTOR_LEFT_B, OUTPUT);
    pinMode(MOTOR_RIGHT_A, OUTPUT);
    pinMode(MOTOR_RIGHT_B, OUTPUT);
    /*
    unsigned long next = millis() + 10000;
    actuation = 0;
    #if DEBUG > 0
        Serial.print("\n>>> LOG : millis : ");
        Serial.println(millis());
        Serial.print("\n>>> LOG : next : ");
        Serial.println(next);
    #endif
    
    if(actuation < POWER_MAX){
        while(millis() < next){
            actuation = (actuation >= POWER_MAX)?(POWER_MAX):(actuation+10);
            ST.motor(1, actuation);
            ST.motor(2, actuation);
            delay(20);
            if(measureLine()){
                survive();
                break; 
            }
        }
    }
    else{
        ST.motor(1, POWER_MAX);
        ST.motor(2, POWER_MAX);
    }
    */
    return;
}
