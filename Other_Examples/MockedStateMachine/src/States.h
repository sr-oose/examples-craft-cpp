#ifndef STATES_H_
#define STATES_H_

#include <memory>
#include <stdexcept>

#include "BarrierActuator.h"

// Forward declarations
class LevelCrossingState;
class StateClosing;
class StateOpening;
class StateClosed;
class StateOpen;
class StateMachine;


using LevelCrossingStatePtr = std::shared_ptr<LevelCrossingState>;

enum class StateID { OPENING, CLOSING, OPEN, CLOSED };

class LevelCrossingState {
public:
	// Constructor
	LevelCrossingState(BarrierActuatorPtr actuator)
		: actuator(actuator){ }

	// Event handlers
	virtual LevelCrossingStatePtr onTrainApproaching();
	virtual LevelCrossingStatePtr onBarrierFullyClosed();
	virtual LevelCrossingStatePtr onBarrierFullyOpened();
	virtual LevelCrossingStatePtr onTrainHasPassed();
	virtual StateID getStateID() = 0;

	// Destructor
	virtual ~LevelCrossingState() = default;

protected:
	BarrierActuatorPtr actuator;
};

class StateClosing : public LevelCrossingState {
public:
	StateClosing(BarrierActuatorPtr actuator)
		: LevelCrossingState(actuator) { }

	virtual LevelCrossingStatePtr onTrainApproaching() override;
	virtual LevelCrossingStatePtr onBarrierFullyClosed() override;
	virtual LevelCrossingStatePtr onTrainHasPassed() override;
	virtual StateID getStateID() override;

};

class StateOpening : public LevelCrossingState {
public:
	StateOpening(BarrierActuatorPtr actuator)
		: LevelCrossingState(actuator) { }

	virtual LevelCrossingStatePtr onTrainApproaching() override;
	virtual LevelCrossingStatePtr onBarrierFullyOpened() override;
	virtual LevelCrossingStatePtr onTrainHasPassed() override;
	virtual StateID getStateID() override;
};

class StateOpen : public LevelCrossingState {
public:
	StateOpen(BarrierActuatorPtr actuator)
		: LevelCrossingState(actuator) { }

	virtual LevelCrossingStatePtr onTrainApproaching() override;
	virtual LevelCrossingStatePtr onTrainHasPassed() override;
	virtual StateID getStateID() override;
};

class StateClosed : public LevelCrossingState {
public:
	StateClosed(BarrierActuatorPtr actuator)
		: LevelCrossingState(actuator) { }

	virtual LevelCrossingStatePtr onTrainApproaching() override;
	virtual LevelCrossingStatePtr onTrainHasPassed() override;
	virtual StateID getStateID() override;
};


#endif /* STATES_H_ */
