#ifndef LEGOPATHCONTROLLER_H
#define LEGOPATHCONTROLLER_H

#include "mxcore.h"

// VTABLE: LEGO1 0x100d7d60
// SIZE 0x40
class LegoPathController : public MxCore {
public:
	LegoPathController();
	virtual ~LegoPathController() override;

	virtual MxResult Tickle() override; // vtable+08

	// FUNCTION: LEGO1 0x10045110
	inline const char* ClassName() const override // vtable+0xc
	{
		// GLOBAL: LEGO1 0x100f11b8
		return "LegoPathController";
	}

	// FUNCTION: LEGO1 0x10045120
	inline MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, LegoPathController::ClassName()) || MxCore::IsA(name);
	}
};

#endif // LEGOPATHCONTROLLER_H
