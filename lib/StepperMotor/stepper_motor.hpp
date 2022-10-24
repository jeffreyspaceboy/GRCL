#ifndef GRCL_STEPPERMOTOR_HPP_
#define GRCL_STEPPERMOTOR_HPP_

#include <string>

namespace GRCL
{
	/// @brief Basic stepper motor control.
	class StepperMotor{
		public:
			StepperMotor();
		private:
			std::string motor_name_;
	};
}

#endif  // GRCL_STEPPERMOTOR_HPP_