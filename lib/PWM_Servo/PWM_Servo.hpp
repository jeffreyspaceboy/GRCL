#ifndef GRCL_PWMSERVO_HPP_
#define GRCL_PWMSERVO_HPP_

#include <stdint.h>

#define PWM_SERVO_DEFAULT_MIN_PULSE_WIDTH_ 500
#define PWM_SERVO_DEFAULT_MID_PULSE_WIDTH_ 1500
#define PWM_SERVO_DEFAULT_MAX_PULSE_WIDTH_ 2500

namespace GRCL {
	class PWM_Servo {
		public:
			PWM_Servo(uint8_t gpioPin);
			PWM_Servo(uint8_t gpioPin, uint16_t minimumPulseWidth, uint16_t middlePulseWidth, uint16_t maximumPulseWidth);
			~PWM_Servo();
		protected:
			void Attach();
			void Detach();

			void Write(uint16_t pulseWidth);
			uint16_t Read();

			uint8_t pin_;
			uint16_t minPulseWidth_, midPulseWidth_, maxPulseWidth_, currentPulseWidth_;
			double clockDiv_, wrap_;
	};
}
#endif // GRCL_PWMSERVO_HPP_
