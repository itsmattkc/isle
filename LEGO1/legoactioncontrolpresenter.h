#ifndef LEGOACTIONCONTROLPRESENTER_H
#define LEGOACTIONCONTROLPRESENTER_H

#include "decomp.h"
#include "legoutil.h"
#include "mxmediapresenter.h"

// VTABLE: LEGO1 0x100d5118
// SIZE 0x68
class LegoActionControlPresenter : public MxMediaPresenter {
public:
	inline LegoActionControlPresenter() { m_unk0x50 = ExtraActionType_none; }
	virtual ~LegoActionControlPresenter() override { Destroy(TRUE); }; // vtable+0x00

	// FUNCTION: LEGO1 0x1000d0e0
	inline virtual const char* ClassName() const override // vtable+0x0c
	{
		// GLOBAL: LEGO1 0x100f05bc
		return "LegoActionControlPresenter";
	}

	// FUNCTION: LEGO1 0x1000d0f0
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, LegoActionControlPresenter::ClassName()) || MxMediaPresenter::IsA(name);
	}

	// TODO: Find proper compilation unit to put this
	// SYNTHETIC: LEGO1 0x1000d1d0
	// LegoActionControlPresenter::`scalar deleting destructor'

	virtual void ReadyTickle() override;           // vtable+0x18
	virtual void RepeatingTickle() override;       // vtable+0x24
	virtual void ParseExtra() override;            // vtable+0x30
	virtual MxResult AddToManager() override;      // vtable+0x34
	virtual void Destroy(MxBool p_fromDestructor); // vtable+0x5c

private:
	ExtraActionType m_unk0x50; // 0x50
	MxString m_unk0x54;        // 0x54
	undefined4 m_unk0x64;      // 0x64
};

#endif // LEGOACTIONCONTROLPRESENTER_H
