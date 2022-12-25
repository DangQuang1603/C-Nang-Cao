#include<setjmp.h>
#define btn_blink 12
#define btn_duoi 11
#define btn_tat 10

jmp_buf temp;
int value = 0;

// link video   https://drive.google.com/file/d/1AOpthOpdocCdzcp50mLv423Y3Ahe7ctS/view?usp=sharing
// em không có đủ đồ nên dùng mô phỏng ạ

#define TRY if ((value = setjmp(temp)) == 0)
#define CATCH(NUM) else if (value == NUM)
#define THROW(NUM) longjmp(temp, NUM)


void setup() {
   for (int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i , LOW);
   }
   pinMode(btn_blink, INPUT);
   pinMode(btn_duoi, INPUT);
   pinMode(btn_tat, INPUT);

}

void choptat_status() {
  int btn_choptat_st = digitalRead(btn_blink);
  if (btn_choptat_st == LOW) {
    THROW(1);
  }
}

void BTN_Duoi() {
  int btn_duoi_st = digitalRead(btn_duoi);
  if (btn_duoi_st == LOW) {
    THROW(2);
  }
}

void BTN_tatLed() {
  int btn_tat_st = digitalRead(btn_tat);
  if (btn_tat_st == LOW) {
    THROW(3);
  }
}

void delaymlili_check(int timee) {
  int timecheck = timee;
  for (int i = 0; i < timecheck; i++) {
    choptat_status();
    BTN_Duoi();
    BTN_tatLed();
    }
  }

void choptat() {
  for (int i = 0; i < 5; i++) {
    for (int j = 2; j < 10; j++) {
      digitalWrite(j, HIGH);
    }
    delaymlili_check(20000);
    for (int j = 2; j < 10; j++) {
      digitalWrite(j, LOW);
    }
    delaymlili_check(20000);
  }
}

void duoi() {
    for (int i = 2; i < 10; i++) {
      digitalWrite(i, HIGH);
      delaymlili_check(10000);
    }
}

void tat() {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
  }
  delaymlili_check(10000);
}
void loop() {
  value = setjmp(temp);
  switch (value) {
      case 1:
        choptat();
        break;
      case 2:
        duoi();
        break;
      case 3:
        tat();
        break;
      default:
        choptat_status();
        BTN_Duoi();
        BTN_tatLed();
        break;
    }
}