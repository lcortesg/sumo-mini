/**
 * @brief: Firmware developed for the Robot Sumo Auto named "Lauchita". It finds it's enemy using a PID controller.
 * @author : Lucas Cortes.
 * @date: 19/12/2019
 */
 

#define NONE 0
#define INFO 1
#define SERIAL INFO
#define DEBUG INFO

#define MOTOR_LEFT_A 2
#define MOTOR_LEFT_B 3

#define MOTOR_RIGHT_A 4
#define MOTOR_RIGHT_B 5


#define PIN_SENSOR_LEFT 7
#define PIN_SENSOR_FRONT 8
#define PIN_SENSOR_RIGHT 9


#define PIN_START_BUTTON 6
#define PIN_DIP_SWITCH_1 A0
#define PIN_DIP_SWITCH_2 A1

#define TIME_SURVIVE_1 120


/**
 * @brief : defines the maximum power given to the motors.
 */
#define POWER_MAX 255


/**
 * @brief : PID controller constants.
 */
#define KP 0.15 //0.064
#define KI 0.0008
#define KD 0.016

/**
 * @brief: Reference to follow with the PID controller.
 */
#define REF 2000


#define PIN_LED 13


double enemy_sensor_left = 0;
double enemy_sensor_front = 0;
double enemy_sensor_right = 0;

double actuation = 0;
double error_prev = 0;
double error = 0;
double error_int = 0;
double error_dev = 0;
double measure = 0;
double ref = REF;


int tactic = 0;


void setup(){
    
     pinMode(MOTOR_LEFT_A, OUTPUT);
     pinMode(MOTOR_LEFT_B, OUTPUT);
     pinMode(MOTOR_RIGHT_A, OUTPUT);
     pinMode(MOTOR_RIGHT_B, OUTPUT);
    
    
    #if SERIAL > NONE
        Serial.begin(115200);
        Serial.println("Init Sumo Robot - CoR 2019");
    #endif

    pinMode(PIN_SENSOR_LEFT, INPUT_PULLUP);
    pinMode(PIN_SENSOR_FRONT, INPUT_PULLUP);
    pinMode(PIN_SENSOR_RIGHT, INPUT_PULLUP);


    pinMode(PIN_LED, OUTPUT);
    //digitalWrite(PIN_LED, LOW);

    pinMode(PIN_DIP_SWITCH_1, INPUT_PULLUP);
    pinMode(PIN_DIP_SWITCH_2, INPUT_PULLUP);
    tactic = digitalRead(PIN_DIP_SWITCH_1);

    #if SERIAL > NONE
        Serial.println("Wait for Button Start ...");
    #endif


    #if SERIAL > NONE
        Serial.println("Fight!!!");
    #endif
    
}


void loop(){

    while(digitalRead(PIN_START_BUTTON)){
        digitalWrite(PIN_LED, HIGH);
        /*
        if(measureEnemy()){
            if(searchPID()){
                fight();
            }
        }
        */
        
        digitalWrite(MOTOR_LEFT_A, LOW);
        digitalWrite(MOTOR_LEFT_B, HIGH);
        digitalWrite(MOTOR_RIGHT_A, LOW);
        digitalWrite(MOTOR_RIGHT_B, HIGH);
        
    }

    digitalWrite(MOTOR_LEFT_A, LOW);
    digitalWrite(MOTOR_LEFT_B, LOW);
    digitalWrite(MOTOR_RIGHT_A, LOW);
    digitalWrite(MOTOR_RIGHT_B, LOW);
    digitalWrite(PIN_LED, LOW);

}
