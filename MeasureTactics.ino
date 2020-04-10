/**
<<<<<<< HEAD
 * @function measureLine : Lee los sensores de línea y determina si se está detectando un fondo blanco
=======
 * @function measureLine : Lee los sensores de línea y determina si se está detectando un fondo blanco 
>>>>>>> 78b7154f0c3b81b701fbb7887594625cef9d480f
 * @param : none
 * @return : retorna 0 si no se detecta una línea, 1 en caso contrario
 */


bool measureEnemy(){
    enemy_sensor_left = !digitalRead(PIN_SENSOR_LEFT);
    enemy_sensor_front = !digitalRead(PIN_SENSOR_FRONT);
    enemy_sensor_right = !digitalRead(PIN_SENSOR_RIGHT);

    #if DEBUG > NONE
        Serial.print("\n>>> LOG: mediciones de enemigo: \t");
        Serial.print(enemy_sensor_left);
        Serial.print("\t");
        Serial.print(enemy_sensor_front);
        Serial.print("\t");
        Serial.print(enemy_sensor_right);
    #endif
        
    return (enemy_sensor_left) || (enemy_sensor_front) || (enemy_sensor_right);
}
