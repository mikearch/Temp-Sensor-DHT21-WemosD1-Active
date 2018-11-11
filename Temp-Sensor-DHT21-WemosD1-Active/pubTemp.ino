void pubTemp() {

// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    //float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    //float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // Computes temperature values in Celsius
    //float hic = dht.computeHeatIndex(t, h, false);  //commented to eliminate heat index calc
    static char temperatureTemp[7];
    dtostrf(t, 6, 2, temperatureTemp);   // changed hic variable in this function to t
    
    // Uncomment to compute temperature values in Fahrenheit 
    // float hif = dht.computeHeatIndex(f, h);
    // static char temperatureTemp[7];
    // dtostrf(hic, 6, 2, temperatureTemp);
    
   // static char humidityTemp[7];          //comment out humidity stuff
    //dtostrf(h, 6, 2, humidityTemp);

    // Publishes Temperature and Humidity values
    client.publish("home/office/esp1/temperature", temperatureTemp);
    // client.publish("home/office/esp1/humidity", humidityTemp); //comented out humidity stuff

    return;
}
