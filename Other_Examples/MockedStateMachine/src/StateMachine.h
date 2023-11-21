#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <memory>
#include "States.h"
#include "BarrierActuator.h"

class LevelCrossingState;

class StateMachine {
public:
	StateMachine(BarrierActuatorPtr actuator);

	void trainApproaching();
	void trainHasPassed();
	void barrierFullyOpened();
	void barrierFullyClosed();

	StateID getStateID();

private:
	LevelCrossingStatePtr currentState;
};

#endif /* STATEMACHINE_H_ */
