#include "PWM_Servo.hpp"

#include <Servo.h>

GRCL::PWM_Servo::PWM_Servo(uint8_t gpioPin)
    : PWM_Servo(gpioPin, PWM_SERVO_DEFAULT_MIN_PULSE_WIDTH_, PWM_SERVO_DEFAULT_MID_PULSE_WIDTH_, PWM_SERVO_DEFAULT_MAX_PULSE_WIDTH_)
{}


GRCL::PWM_Servo::PWM_Servo(uint8_t gpioPin, uint16_t minimumPulseWidth, uint16_t middlePulseWidth, uint16_t maximumPulseWidth) {
    pin_ = gpioPin;
    currentPulseWidth_ = middlePulseWidth;
    minPulseWidth_ = minimumPulseWidth;
    midPulseWidth_ = middlePulseWidth;
    maxPulseWidth_ = maximumPulseWidth;
    Attach();
}

GRCL::PWM_Servo::~PWM_Servo(){
    Detach();
}


void GRCL::PWM_Servo::Attach(){
    // gpio_set_function(pin_, GPIO_FUNC_PWM);
    // uint sliceNum = pwm_gpio_to_slice_num(pin_);
    // pwm_config config = pwm_get_default_config();
    // uint64_t clockSpeed = clock_get_hz(clk_sys);
    // clockDiv_ = 64.0;
    // wrap_ = 39062.0;
    // while (((clockSpeed / clockDiv_ / 50.0) > 65535.0) && (clockDiv_ < 256.0)) {
    //     clockDiv_ += 64.0;
    // }
    // wrap_ = (clockSpeed / clockDiv_ / 50.0);
    // pwm_config_set_clkdiv(&config, clockDiv_);
    // pwm_config_set_wrap(&config, wrap_);
    // pwm_init(sliceNum, &config, true);
}

void GRCL::PWM_Servo::Detach() {
    // pwm_set_enabled(pwm_gpio_to_slice_num(pin_), false);
}


void GRCL::PWM_Servo::Write(uint16_t pulseWidth) {
    if (pulseWidth > maxPulseWidth_) { 
        pulseWidth = maxPulseWidth_; 
    } else if (pulseWidth < minPulseWidth_) {
        pulseWidth = minPulseWidth_;
    }
    // pwm_set_gpio_level(pin_, (pulseWidth / 20000.0) * wrap_);
    currentPulseWidth_ = pulseWidth;
}

uint16_t GRCL::PWM_Servo::Read() {
    return currentPulseWidth_;
}
