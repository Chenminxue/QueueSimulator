#pragma once
#ifndef __BANK_H__
#define __BANK_H__

#include <list>
#include <queue>


// Bank system
class Bank {
public:
	explicit Bank(int serviceDeskNum = 4, int closeTime = 8 * 3600);

	~Bank();

	void simulation();

private:
	int m_QueueNum;
	int m_CloseTime;
	int m_TotalTimeOfCustomer;
	int m_CustomerNum;

	std::list<Event> m_EventList;
	std::queue<QueueNode>* m_Queue;

	void BankOpen();
	void CustomerArrived(Event *event);
	void CustomerLeave(Event *event);

	int ShortestQueueSearch();
	void SortEventList();
};

// Event
struct Event {
	int s_TimeStamp;
	int s_Type; // 0: arrive event; 1 ~ 4: leave events of four service desk

	bool operator < (const Event& rhs) {
		return s_TimeStamp < rhs.s_TimeStamp;
	}
};

// QueueNode
struct QueueNode {
	int s_ArriveTime;
	int s_LeaveTime;
};

#endif // !__BANK_H__