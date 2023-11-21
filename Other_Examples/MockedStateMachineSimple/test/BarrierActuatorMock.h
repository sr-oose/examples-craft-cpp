#ifndef BARRIERACTUATORMOCK_H_
#define BARRIERACTUATORMOCK_H_

#include <gmock/gmock.h>
#include "BarrierActuator.h"

class BarrierActuatorMock : public BarrierActuator {
public:
	MOCK_METHOD0(sendCloseCommand, void());
	MOCK_METHOD0(sendOpenCommand, void());
};

#endif /* BARRIERACTUATORMOCK_H_ */
