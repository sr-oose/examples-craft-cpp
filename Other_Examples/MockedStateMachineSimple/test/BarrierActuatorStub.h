#ifndef BARRIERACTUATORSTUB_H_
#define BARRIERACTUATORSTUB_H_

#include "BarrierActuator.h"

class BarrierActuatorStub: public BarrierActuator {
	virtual void sendCloseCommand();
	virtual void sendOpenCommand();
};

#endif /* BARRIERACTUATORSTUB_H_ */
