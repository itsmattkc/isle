#ifndef MXFLCPRESENTER_H
#define MXFLCPRESENTER_H

#include "decomp.h"
#include "mxvideopresenter.h"

#include <flic.h>

// VTABLE: LEGO1 0x100dc2c0
// SIZE 0x68
class MxFlcPresenter : public MxVideoPresenter {
public:
	MxFlcPresenter();
	virtual ~MxFlcPresenter() override;

	// FUNCTION: LEGO1 0x1004e200
	inline virtual MxBool IsA(const char* name) const override // vtable+0x10
	{
		return !strcmp(name, MxFlcPresenter::ClassName()) || MxVideoPresenter::IsA(name);
	}

	// FUNCTION: LEGO1 0x100b33f0
	inline virtual const char* ClassName() const override // vtable+0xc
	{
		// GLOBAL: LEGO1 0x100f43c8
		return "MxFlcPresenter";
	}

	virtual void LoadHeader(MxStreamChunk* p_chunk) override; // vtable+0x5c
	virtual void CreateBitmap() override;                     // vtable+0x60
	virtual void VTable0x70() override;                       // vtable+0x70

protected:
	FLIC_HEADER* m_flicHeader;
};

#endif // MXFLCPRESENTER_H
