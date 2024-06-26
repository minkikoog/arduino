왜 490 Hz 또는 976 Hz를 사용하게 되었나?
ChatGPT
Arduino에서 기본적으로 490 Hz 또는 976 Hz의 PWM 주파수를 사용하는 이유는 주로 하드웨어 타이머 설정에 기인합니다. 각 타이머는 특정 주파수로 설정되어 있으며, 이는 마이크로컨트롤러의 클록 속도와 타이머의 분주기 설정에 따라 결정됩니다.

기본 PWM 주파수 설정
Arduino Uno와 같은 보드의 경우, AVR ATmega328P 마이크로컨트롤러를 사용합니다. 이 마이크로컨트롤러에는 여러 개의 하드웨어 타이머가 있으며, 기본적으로 다음과 같이 설정됩니다:

타이머 0 (Timer 0):

핀 5와 6을 제어합니다.
기본 주파수는 약 976 Hz입니다.
이 주파수는 타이머 0이 8비트 타이머로 설정되고, Arduino의 기본 클록 속도 16 MHz를 64로 분주한 값입니다. 즉, 16,000,000 / 64 / 256 = 약 976 Hz입니다.
타이머 1 (Timer 1):

핀 9와 10을 제어합니다.
기본적으로 Servo 라이브러리와 같이 다른 용도로 사용됩니다.
PWM 주파수를 직접 설정하지 않으며, 주로 서보 모터 제어에 사용됩니다.
타이머 2 (Timer 2):

핀 3와 11을 제어합니다.
기본 주파수는 약 490 Hz입니다.
이 주파수는 타이머 2가 8비트 타이머로 설정되고, Arduino의 기본 클록 속도 16 MHz를 128로 분주한 값입니다. 즉, 16,000,000 / 128 / 256 = 약 490 Hz입니다.
왜 490 Hz 또는 976 Hz를 사용하는가?
호환성:

기본 주파수로 490 Hz와 976 Hz는 다양한 애플리케이션에서 충분히 호환성이 있습니다. 대부분의 DC 모터와 LED 제어에는 이 주파수가 적합합니다.
간단한 구현:

16 MHz의 클록 속도를 가지는 마이크로컨트롤러에서 8비트 타이머를 사용하여 490 Hz와 976 Hz 주파수를 생성하는 것은 비교적 간단합니다. 이는 분주기와 타이머의 최대 값(256)을 사용하여 쉽게 구현할 수 있습니다.
성능과 소음의 균형:

이 주파수는 모터와 같은 부하를 제어할 때 성능과 소음의 균형을 유지합니다. 너무 낮은 주파수는 소음을 증가시키고, 너무 높은 주파수는 전력 손실을 증가시킬 수 있습니다.
타이머 주파수 변경 방법
Arduino에서 기본 PWM 주파수를 변경하려면 하드웨어 타이머의 설정을 조정해야 합니다. 예를 들어, Timer 0의 분주기를 변경하여 주파수를 변경할 수 있습니다:

cpp
코드 복사
void setup() {
  // Timer 0의 분주기를 64에서 8로 변경하여 주파수를 높임
  TCCR0B = (TCCR0B & 0b11111000) | 0x02; // 분주기를 8로 설정
}
이와 같은 방식으로 다른 타이머의 분주기 설정을 변경하여 원하는 PWM 주파수를 설정할 수 있습니다.

결론
Arduino의 기본 PWM 주파수인 490 Hz와 976 Hz는 하드웨어 타이머의 기본 설정과 클록 속도의 조합으로 인해 선택되었습니다. 이 주파수는 대부분의 애플리케이션에서 충분한 성능을 제공하며, 성능과 소음의 균형을 잘 맞춥니다. 필요한 경우, 타이머 설정을 변경하여 PWM 주파수를 조정할 수 있습니다.
