#ifndef ACT1STATE_H
#define ACT1STATE_H

#include "legostate.h"

// VTABLE: LEGO1 0x100d7028
// SIZE 0x26c
class Act1State : public LegoState {
public:
	Act1State();

	// FUNCTION: LEGO1 0x100338a0
	inline virtual const char* ClassName() const override // vtable+0x0c
	{
		// GLOBAL: LEGO1 0x100f0154
		return "Act1State";
	};

	// FUNCTION: LEGO1 0x100338b0
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, Act1State::ClassName()) || LegoState::IsA(name);
	};
};

#endif // ACT1STATE_H
