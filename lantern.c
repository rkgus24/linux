while (1) {
    #if 1
    if (!HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2)) {
      HAL_Delay(100);

      if (!HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_2)) {
        if (ledState == LED_ON) {
          for (int i = 0; i < LED_COUNT; i++) {
            HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_RESET);
          }
          ledState = LED_OFF;
        } else {
          if (ledCount < LED_COUNT) {
            ledCount++;
          }
          for (int i = 0; i < ledCount
          for (int i = 0; i < ledCount; i++) {
            HAL_GPIO_WritePin(leds[i].port, leds[i].pin, GPIO_PIN_SET);
          }
          ledState = LED_ON;
        }
      }
    }
    #endif

     #if 1
    if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
      HAL_Delay(100);

      if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)) {
        if (ledState == LED_ON) {
          if (ledCount > 0) {
            ledCount--;
            HAL_GPIO_WritePin(leds[ledCount].port, leds[ledCount].pin, GPIO_PIN_RESET);
          }
          if (ledCount == 0) {
            ledState = LED_OFF;
          }
        }
      }
    }
    #endif
  }
}
