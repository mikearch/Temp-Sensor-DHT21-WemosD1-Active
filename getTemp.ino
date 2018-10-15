 //Read data and store it to variables hum and temp
    
    void getTemp(){
    hum = dht.readHumidity();
    temp= dht.readTemperature();

     // Check if any reads failed and exit early (to try again).
    if (isnan(hum) || isnan(temp) ) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    return;
    }
