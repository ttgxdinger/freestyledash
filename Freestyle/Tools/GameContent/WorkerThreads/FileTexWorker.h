#pragma once
#include "../../Threads/cthread.h"
#include "../../Texture/TextureItem/TextureItem.h"

using namespace std;

class FileTexWorker : public CThread
{
private :
	bool m_IsBusy;
	bool m_WaitingToStart;
	TextureItem * m_CurrentItem;
public :
	bool m_IsDisposed;
	void SetItem(TextureItem* newItem);
	unsigned long Process(void* parameter);
	void LoadCurrentItem();
	bool IsBusy()
	{
		if(m_IsBusy || m_WaitingToStart)
			return true;
		else
			return false;
	}
	FileTexWorker();
	~FileTexWorker(){
	m_IsDisposed = true;
	};
};