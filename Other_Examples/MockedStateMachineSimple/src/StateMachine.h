#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <memory>
#include "BarrierActuator.h"

class LevelCrossingState;

class StateMachine {
public:
	enum class StateID { OPENING, CLOSING, OPEN, CLOSED };

	StateMachine(BarrierActuatorPtr actuator);

	void trainApproaching();
	void trainHasPassed();
	void barrierFullyOpened();
	void barrierFullyClosed();

	StateID getStateID();

private:
	StateID currentState;
	BarrierActuatorPtr actuator;
};

#endif /* STATEMACHINE_H_ */
