void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

bool cube[6];
int c = 1;

void led(bool *led) {
  digitalWrite(5, led[0]);
  digitalWrite(6, led[1]);
  digitalWrite(7, led[2]);
  digitalWrite(8, !led[3]);
  digitalWrite(9, !led[4]);
  digitalWrite(10, !led[5]);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (c > 128)c = 0;
  c++;
  int divi = c;
  for (int i = 0; i < 6; i++) {
    cube[i] = divi % 2;
    divi = divi / 2;
  }
  led(cube);
  delay(200);
}
