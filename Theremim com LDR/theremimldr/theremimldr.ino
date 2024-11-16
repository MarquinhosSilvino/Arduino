void setup() {
  // Definir o pino do alto-falante como saída
  pinMode(11, OUTPUT);  // Speaker pin
}

void loop() {
  const int ldrPin = A0;   // Pino do LDR (sensor de luz)
  const int speakerPin = 11; // Pino do alto-falante

  // Leitura do valor do sensor LDR
  int sensorValue = analogRead(ldrPin); 

  // Definir os valores mínimo e máximo para o sensor LDR
  int sensorMin = 42;   // Valor mínimo do sensor LDR
  int sensorMax = 950;  // Valor máximo do sensor LDR

  // Definir os limites de frequência para o alto-falante
  int freqMin = 200;    // Frequência mínima
  int freqMax = 1200;   // Frequência máxima

  // Mapear o valor do sensor LDR para a faixa de frequências
  int mappedFrequency = map(sensorValue, sensorMin, sensorMax, freqMin, freqMax);


  // Gerar um tom com a frequência mapeada
  tone(speakerPin, mappedFrequency); 

  // Esperar 100ms para o próximo loop
  delay(100);