#ifndef MXQUEUE_H
#define MXQUEUE_H

#include "mxlist.h"

template <class T>
class MxQueue : public MxList<T> {
public:
	void Enqueue(T& p_obj)
	{
		// TODO
	}

	MxBool Dequeue(T& p_obj)
	{
		MxBool has_next = (this->m_first != NULL);
		if (this->m_first) {
			p_obj = this->m_first->GetValue();
			this->_DeleteEntry(this->m_first);
		}

		return has_next;
	}
};

#endif // MXQUEUE_H
