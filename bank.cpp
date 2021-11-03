#include "bank.h"
#include <iostream>
#include <clocale>
#include <chrono>
#include <cstdlib>


Bank::Bank(int serviceDeskNum, int closeTime) {
	m_QueueNum = serviceDeskNum;
	m_CloseTime = closeTime;
	m_TotalTimeOfCustomer = 0;
	m_CustomerNum = 0;

	m_Queue = new std::queue<QueueNode>[serviceDeskNum];

	srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
}

Bank::~Bank() {
	delete[] m_Queue;
}

void Bank::BankOpen() {

}